#ifndef CAN_FRAME_HPP
#define CAN_FRAME_HPP

#include <cstdint>
#include <array>

namespace can
{
    static constexpr std::uint8_t CAN_MAX_DLC = 8U;

    struct CanFrame
    {
        std::uint32_t id;
        std::uint8_t  dlc;
        std::array<std::uint8_t, CAN_MAX_DLC> data;

        CanFrame() noexcept :
            id(0U),
            dlc(0U),
            data{0U}
        {
        }
    };
}

#endif
