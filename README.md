# CAN_demo worked under Ubuntu 22.04

## Project structure
```bash
can_demo/
├── CMakeLists.txt
├── include/
│   └── can/
│       ├── CanFrame.hpp
│       ├── CanInterface.hpp
│       └── CanDriver.hpp
├── src/
│   └── can/
│       └── CanDriver.cpp
├── main_tx.cpp
├── main_rx.cpp
└── README.md
```

## Build & Run
### Enable CAN interface (virtual example)

sudo modprobe vcan

sudo ip link add dev can0 type vcan

sudo ip link set up can0


## Build
mkdir build && cd build

cmake ..

make


## Run in two terminals, (first terminal)
./can_rx

## Run (second terminal)
./can_tx

