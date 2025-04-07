STM32 Bare-Metal: LED Blinking Example
======================================

This project demonstrates how to blink the onboard LEDs of the STM32F4 Discovery board using bare-metal (register-level) programming --- no HAL or libraries used.

🧠 What You Will Learn
----------------------

- How to enable the clock for GPIO ports using RCC

- How to configure GPIO pins as output

- How to toggle pins by writing to the output data register (ODR)

- Basic delay using a simple loop

🔧 Requirements
---------------

- STM32F4 Discovery Board

- ARM GCC Toolchain (or any STM32-supported compiler)

- ST-Link Programmer

- STM32CubeProgrammer or OpenOCD

- USB Mini-B cable

📁 Project Structure
--------------------

stm32-blink-led/\
├── src/\
│   └── main.c         --> Bare-metal LED toggle code\
├── inc/               --> (Optional: header files)\
└── README.md

💡 LED Information (STM32F4 Discovery)
--------------------------------------

| LED Name     |  Port   |  Pin |
| LD3 (Orange) |  GPIOD  |  13  |
| LD4 (Green)  |  GPIOD  |  12  |
| LD5 (Red)    |  GPIOD  |  14  |
| LD6 (Blue)   |  GPIOD  |  15  |

⚙️ Used Registers
-----------------

- `RCC_AHB1ENR` → Enables clock for GPIO port

- `GPIOD_MODER` → Configures the pin mode (output/input/etc.)

- `GPIOD_ODR` → Controls the output level on the pins

Each GPIO pin uses 2 bits in the MODER register.
