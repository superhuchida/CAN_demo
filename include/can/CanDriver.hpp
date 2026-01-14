#ifndef CAN_DRIVER_HPP
#define CAN_DRIVER_HPP

#include "CanInterface.hpp"

namespace can
{
    class CanDriver final : public CanInterface
    {
    public:
        CanDriver() noexcept;
        ~CanDriver() noexcept override;

        bool open(const char* interfaceName) noexcept override;
        bool send(const CanFrame& frame) noexcept override;
        bool receive(CanFrame& frame) noexcept override;
        void close() noexcept override;

    private:
        int socketFd;
    };
}

#endif
