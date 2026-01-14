#ifndef CAN_INTERFACE_HPP
#define CAN_INTERFACE_HPP

#include "CanFrame.hpp"

namespace can
{
    class CanInterface
    {
    public:
        virtual ~CanInterface() = default;

        virtual bool open(const char* interfaceName) noexcept = 0;
        virtual bool send(const CanFrame& frame) noexcept = 0;
        virtual bool receive(CanFrame& frame) noexcept = 0;
        virtual void close() noexcept = 0;
    };
}

#endif
