#include "can/CanDriver.hpp"
#include <chrono>
#include <thread>
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
    frame.id  = 0x123U;
    frame.dlc = 2U;
    frame.data[0] = 0xABU;
    frame.data[1] = 0xCDU;

    while (true)
    {
        driver.send(frame);
        std::cout << "TX: Sent frame 0x123\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
