#include "can/CanDriver.hpp"

#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

namespace can
{
    CanDriver::CanDriver() noexcept :
        socketFd(-1)
    {
    }

    CanDriver::~CanDriver() noexcept
    {
        close();
    }

    bool CanDriver::open(const char* interfaceName) noexcept
    {
        struct ifreq ifr {};
        struct sockaddr_can addr {};

        socketFd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
        if (socketFd < 0)
        {
            return false;
        }

        std::strncpy(ifr.ifr_name, interfaceName, IFNAMSIZ - 1U);
        if (ioctl(socketFd, SIOCGIFINDEX, &ifr) < 0)
        {
            return false;
        }

        addr.can_family  = AF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;

        if (bind(socketFd, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) < 0)
        {
            return false;
        }

        return true;
    }

    bool CanDriver::send(const CanFrame& frame) noexcept
    {
        struct can_frame canFrame {};

        canFrame.can_id  = frame.id;
        canFrame.can_dlc = frame.dlc;

        for (std::uint8_t i = 0U; i < frame.dlc; ++i)
        {
            canFrame.data[i] = frame.data[i];
        }

        return (write(socketFd, &canFrame, sizeof(canFrame)) == sizeof(canFrame));
    }

    bool CanDriver::receive(CanFrame& frame) noexcept
    {
        struct can_frame canFrame {};

        if (read(socketFd, &canFrame, sizeof(canFrame)) < 0)
        {
            return false;
        }

        frame.id  = canFrame.can_id;
        frame.dlc = canFrame.can_dlc;

        for (std::uint8_t i = 0U; i < frame.dlc; ++i)
        {
            frame.data[i] = canFrame.data[i];
        }

        return true;
    }

    void CanDriver::close() noexcept
    {
        if (socketFd >= 0)
        {
            ::close(socketFd);
            socketFd = -1;
        }
    }
}
