/*
  Copyright (c) Qeexo
*/

#ifndef _VARIANT_TDK_IIM46234_
#define _VARIANT_TDK_IIM46234_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK        (F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (20u)
#define NUM_DIGITAL_PINS     (20u)
#define NUM_ANALOG_INPUTS    (0u)
#define NUM_ANALOG_OUTPUTS   (0u)
#define analogInputToDigitalPin(p)  (p)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs
#define PIN_LED_14           (14u)
#define PIN_LED              PIN_LED_14
#define LED_BUILTIN          PIN_LED_14


/*
 * Analog pins
 */
#define PIN_A0               (15ul)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_A4               (PIN_A0 + 4)
#define PIN_A5               (PIN_A0 + 5)
#define PIN_A6               (PIN_A0 + 6)

#define PIN_DAC0             (15ul)
#define PIN_DAC1             PIN_A1

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6 ;


#define ADC_RESOLUTION		12

// Other pins
#define PIN_ATN              (32ul)
static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */

// Serial1
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (24u)
#define PIN_SPI_MOSI         (25u)
#define PIN_SPI_SCK          (26u)
#define PERIPH_SPI           sercom4
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2


#define IMU_MU1_CS           (8u)
#define IMU_MU2_CS           (9u)
#define IMU_MU3_CS           (10u)
#define IMU_SU1_CS           (11u)
#define IMU_SU2_CS           (12u)
#define IMU_SU3_CS           (13u)


#define ICM40608_WHOAMI 0x39
#define ICM42600_WHOAMI 0x40
#define ICM42602_WHOAMI 0x41
#define ICM42605_WHOAMI 0x42
#define ICM42622_WHOAMI 0x46
#define ICM42686_WHOAMI 0x44
#define ICM42688_WHOAMI 0x47
#define ICM42608_WHOAMI 0x48
#define IIM42623_WHOAMI 0x5D
#define IIM42624_WHOAMI 0x5E
#define IIM42625_WHOAMI 0x5F



static const uint8_t SS	  = IMU_MU1_CS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;


/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (29ul)
#define PIN_USB_DM          (30ul)
#define PIN_USB_DP          (30ul)


/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (22u)
#define PIN_WIRE_SCL         (23u)
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler
#define WIRE_IT_HANDLER_0    SERCOM2_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM2_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM2_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM2_3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;


#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  // TODO: meaningful value for this
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

extern void rebootToBootloader();
#define REBOOT_TO_BOOTLOADER    rebootToBootloader


#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
//#define SERIAL_PORT_USBVIRTUAL      Serial
//#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_TDK_IIM46234_ */

