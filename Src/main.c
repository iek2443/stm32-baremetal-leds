// LED Definitions (STM32F4 Discovery Board):
// LD3 ORANGE -> Port D, Pin 13
// LD4 GREEN  -> Port D, Pin 12
// LD5 RED    -> Port D, Pin 14
// LD6 BLUE   -> Port D, Pin 15

// 1. Base address definitions for peripheral memory access
#define PERIPH_BASE             (0x40000000UL)                // Base address of all peripherals
#define AHB1PERIPH_OFFSET       (0x00020000UL)                // Offset for AHB1 peripheral bus
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)  // Base address of AHB1 peripherals

// 2. Define GPIOD base address (Port D is used for onboard LEDs)
#define GPIOD_OFFSET            (0x0C00UL)
#define GPIOD_BASE              (AHB1PERIPH_BASE + GPIOD_OFFSET)

// 3. Define RCC (Reset and Clock Control) base address
#define RCC_OFFSET              (0x3800UL)
#define RCC_BASE                (AHB1PERIPH_BASE + RCC_OFFSET)

// 4. Define the register to enable GPIO port clocks
#define AHB1EN_R_OFFSET         (0x30UL)
#define RCC_AHB1EN_R_           (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define GPIODEN                 (1U << 3)                     // Bit 3 enables GPIOD clock

// 5. Define register for GPIO mode configuration
#define MODE_R_OFFSET           (0x00UL)
#define GPIOD_MODE_R            (*(volatile unsigned int *)(GPIOD_BASE + MODE_R_OFFSET))

// 6. Define register for GPIO output data
#define OD_R_OFFSET             (0x14UL)
#define GPIOD_OD_R              (*(volatile unsigned int *)(GPIOD_BASE + OD_R_OFFSET))

// 7. Define pin numbers and LED aliases
#define PIN12                   (1U << 12)
#define LD4_GREEN               PIN12

#define PIN13                   (1U << 13)
#define LD3_ORANGE              PIN13

#define PIN14                   (1U << 14)
#define LD5_RED                 PIN14

#define PIN15                   (1U << 15)
#define LD6_BLUE                PIN15

// ===========================
// Main Program Entry
// ===========================
int main(void) {

    // Enable clock for GPIOD
    RCC_AHB1EN_R_ |= GPIODEN;

    // Set pins 12, 13, 14, 15 to output mode
    // Each pin takes 2 bits in the MODER register.
    // 00: Input, 01: Output, 10: Alternate Function, 11: Analog

    // Set pin 12 as output (bits 24-25)
    GPIOD_MODE_R |= (1U << 24);
    GPIOD_MODE_R &= ~(1U << 25);

    // Set pin 13 as output (bits 26-27)
    GPIOD_MODE_R |= (1U << 26);
    GPIOD_MODE_R &= ~(1U << 27);

    // Set pin 14 as output (bits 28-29)
    GPIOD_MODE_R |= (1U << 28);
    GPIOD_MODE_R &= ~(1U << 29);

    // Set pin 15 as output (bits 30-31)
    GPIOD_MODE_R |= (1U << 30);
    GPIOD_MODE_R &= ~(1U << 31);

    // Infinite loop to toggle LEDs in sequence
    while (1) {

        // Toggle Orange LED (LD3)
        GPIOD_OD_R ^= LD3_ORANGE;
        for (int i = 0; i < 200000; i++) {
            // Delay loop (not precise but enough for blinking effect)
        }

        // Toggle Green LED (LD4)
        GPIOD_OD_R ^= LD4_GREEN;
        for (int i = 0; i < 200000; i++) {
        }

        // Toggle Red LED (LD5)
        GPIOD_OD_R ^= LD5_RED;
        for (int i = 0; i < 200000; i++) {
        }

        // Toggle Blue LED (LD6)
        GPIOD_OD_R ^= LD6_BLUE;
        for (int i = 0; i < 200000; i++) {
        }
    }
}
