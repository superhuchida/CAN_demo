#include "can/CanDriver.hpp"
#include <iostream>

int main()
{
    can::CanDriver driver;

    if (!driver.open("can0"))
    {
        std::cerr << "Failed to open CAN interface\n";
        return 1;
    }

    can::CanFrame frame;

    while (true)
    {
        if (driver.receive(frame))
        {
            std::cout << "RX: ID=0x" << std::hex << frame.id
                      << " DLC=" << std::dec << static_cast<int>(frame.dlc)
                      << "\n";
        }
    }
}
