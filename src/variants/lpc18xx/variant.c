// Copyright 2014 Technical Machine, Inc. See the COPYRIGHT
// file at the top-level directory of this distribution.
//
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LPC board pin   |  PORT  | Designation |  Func  | peripheral
 * ----------------+--------+-------------+--------+------------
 *  Debug LEDs
 *  D4             | PB_2   | GPIO5[22]   |  4     |
 *  D5             | P7_3   | GPIO3[11]   |  0     |
 *
 *  CC3000
 *  CLK            | P1_19  | SSP1_CLK    |  1     |
 *  MISO           | P0_0   | SSP1_MISO   |  1     |
 *  MOSI           | P0_1   | SSP1_MOSI   |  1     |
 *  IRQ            | P4_2   | GPIO2[2]    |  0     |
 *  CS             | P4_1   | GPIO5[14]   |  4     |
 *  SW_EN          | P8_5   | GPIO4[5]    |  0     |
 *  Conn_LED       | P4_3   | GPIO2[3]    |  0     |
 *  Error_LED      | P4_4   | GPIO2[4]    |  0     |
 *
 *  External pins
 *  SCL            | P2_4   | I2C1_SCL    |  1     |
 *  SDA            | P2_3   | I2C1_SDA    |  1     |
 *  SCK            | P3_0   | SSP0_SCK    |  4     |
 *  MISO           | P9_1   | SSP0_MISO   |  7     |
 *  MOSI           | P9_2   | SSP0_MOSI   |  7     |
 *
 *  A_G1           | PA_2   | GPIO4[9]    |  0     |
 *  A_G2           | PB_0   | GPIO5[20]   |  4     |
 *  A_G3           | P7_0   | GPIO3[8]    |  0     |
 *
 *  B_G1           | PB_1   | GPIO5[21]   |  4     |
 *  B_G2           | PB_3   | GPIO5[23]   |  4     |
 *  B_G3           | PB_5   | GPIO5[25]   |  4     |
 *
 *  C_G1           | P1_4   | GPIO0[11]   |  0     |
 *  C_G2           | P1_5   | GPIO1[8]    |  0     |
 *  C_G3           | P9_3   | GPIO4[15]   |  0     | can also be MCOA0 - Motor control PWM channel 0, output A, func2
 *
 *  D_G1           | P4_6   | GPIO2[6]    |  0     |
 *  D_G2           | P8_7   | GPIO4[7]    |  0     |
 *  D_G3           | P9_0   | GPIO4[12]   |  0     | can also be ss for ssp0, func7
 *
 *  E_A0           | ADC0_1 | -           |  -     | cannot do any output at all
 *  E_A1           | ADC0_2 | -           |  -     | cannot do any output at all
 *  E_A2           | ADC0_0 | -           |  -     | IS ALSO THE DAC, can do true analog & digital output
 *  E_A3           | P7_5   | GPIO3[13]   |  0     | ADC0_3, func8
 *  E_A4           | P7_4   | GPIO3[12]   |  0     | ADC0_4, func8
 *  E_A5           | PB_6   | GPIO5[26]   |  4     | ADC0_6, func8
 *  E_G1           | P7_1   | GPIO3[9]    |  0     | U2_TXD, func6
 *  E_G2           | P7_2   | GPIO3[10]   |  4     | U2_RXD, func6
 *  E_G3           | P7_0   | GPIO3[8]    |  0     |
 *  E_G4           | P4_0   | GPIO2[0]    |  0     | MCOA0 - Motor control PWM channel 0, output A, func1
 *  E_G5           | P9_5   | GPIO5[18]   |  4     | MCOA1 - Motor control PWM channel 1, output A, func1
 *  E_G6           | P4_8   | GPIO5[12]   |  4     |
 *
 */

const PinDescription g_APinDescription_boardV0[NUM_PINS] =
{

	// Debug leds - TM-00-00, TM-00-02
	{11u, 2u, FUNC4, 5u, 22u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},	// PB_2 GPIO5[22] D4
	{7u, 3u, FUNC0, 3u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// P7_3 GPIO3[11] D5

	// cc3000
	{1u, 19u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_CLK | P1_19  | SSP1_CLK    |  1
	{0u, 0u,  FUNC1, 0u, 0u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_MISO | P0_0   | SSP1_MISO   |  1
	{0u, 1u,  FUNC1, 0u, 1u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_MOSI | P0_1   | SSP1_MOSI   |  1
	{4u, 2u,  FUNC0, 2u, 2u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, // IRQ |  P4_2   | GPIO2[2]    |  0
	{4u, 1u,  FUNC0, 2u, 1u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // CS  | P4_1   | GPIO2[1]   |  4
	{8u, 5u,  FUNC0, 4u, 5u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SW EN | P8_5   | GPIO4[5]    |  0
	{4u, 3u,  FUNC0, 2u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // Conn led | P4_3   | GPIO2[3]    |  0
	{4u, 4u,  FUNC0, 2u, 4u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // Error_LED | P4_4   | GPIO2[4]    |  0
	{4u, 9u,  FUNC4, 5u, 13u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // Smartconfig switch | P4_9   | GPIO5[13]   |  4

	// external pins
	{2u, 4u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},	// I2C1_SCL |  P2_4   | I2C1_SCL    |  1
	{2u, 3u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// I2C1_SDA  | P2_3   | I2C1_SDA    |  1
	{3u, 0u, FUNC4, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// SSP0_CLK | P3_0   |  4
	{9u, 1u, FUNC7, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// SSP0_MISO | P9_1     |  7
	{9u, 2u, FUNC7, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// SSP0_MOSI | P9_2     |  7

	// port A - UPDATED TO TM-00-00
	{4u, 6u, FUNC0, 2u, 6u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G1 | P4_6   | GPIO2[6]    |  0
	{8u, 7u, FUNC0, 4u, 7u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G2 | P8_7   | GPIO4[7]    |  0
	{9u, 0u, FUNC0, 4u, 12u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | P9_0   | GPIO4[12]   |  0

	// port B - UPDATED TO TM-00-00
	{1u, 4u, FUNC0, 0u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G1 | P1_4   | GPIO0[11]   |  0
	{1u, 5u, FUNC0, 1u, 8u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G2 | P1_5   | GPIO1[8]    |  0
	{9u, 3u, FUNC0, 4u, 15u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | P9_3   | GPIO4[15]   |  0

	// port C - CHECK G1 (IS THE ##u PORT THEN PIN IN HEX?) OTHERWISE UP TO TM-00-00
	{11u, 4u, FUNC4, 5u, 24u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G1 | PB_4   | GPIO5[21]   |  4
	{11u, 3u, FUNC4, 5u, 23u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G2 | PB_3   | GPIO5[23]   |  4
	{11u, 5u, FUNC4, 5u, 25u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | PB_5   | GPIO5[25]   |  4

	// port D - UPDATED TO TM-00-00
	{10u, 2u, FUNC0, 4u, 9u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G1 | PA_2   | GPIO4[9]    |  0
	{11u, 0u, FUNC4, 5u, 20u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G2 | PB_0   | GPIO5[20]   |  4
	{7u, 0u,  FUNC0, 3u, 8u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | P7_0   | GPIO3[8]    |  0


	// gpio bank E - NOT UP TO DATE. TM-00-00 has A1 and A2 unconnected :(
	// working under the assumption that it's {port, pin, ... . Unsure about the rest of the settings
	// changed:
	{7u, 4u,  FUNC0, 3u, 12u, ADC_CHANNEL_4, NOTSLAVESELECT, ADC_MODE, ADC_CHANNEL_4, NO_CHANNEL},   // A1 | P7_4   | GPIO3[12]   |  0
	{7u, 5u,  FUNC0, 3u, 13u, ADC_CHANNEL_3, NOTSLAVESELECT, ADC_MODE, ADC_CHANNEL_3, NO_CHANNEL}, 	// A2 | P7_5   | GPIO3[13]   |  0
	{11u, 6u, FUNC4, 5u, 26u, ADC_CHANNEL_6, NOTSLAVESELECT, ADC_MODE, ADC_CHANNEL_6, NO_CHANNEL},  // A3 | PB_6   | GPIO5[26]   |  4
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_0, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A4 | ADC0_0 | -           |  -
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_1, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A5 | ADC0_1 | -           |  -
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_2, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A6 | ADC0_2 | -           |  -
	{7u, 1u,  FUNC0, 3u, 9u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC6, NO_CHANNEL}, 	// G1 | P7_1   | GPIO3[9]    |  0
	{7u, 2u,  FUNC0, 3u, 10u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC6, NO_CHANNEL}, 	// G2 | P7_2   | GPIO3[10]   |  4
	{11u, 1u, FUNC4, 5u, 21u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | PB_1   | GPIO5[12]    |  4
	{4u, 8u,  FUNC4, 5u, 12u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // G4 | P4_8   | GPIO5[12]   |  4
	{4u, 0u,  FUNC0, 2u, 0u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G5 | P4_0   | GPIO2[0]    |  0
	{9u, 5u,  FUNC4, 5u, 18u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G6 | P9_5   | GPIO5[18]   |  4

	// button
	{4u, 9u,  FUNC4, 5u, 13u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // button | P4_9   | GPIO5[13]   |  4

	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_5, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // unconnected ADC channel 5
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_7, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}   // unconnected ADC channel 7

};

const PinDescription g_APinDescription_boardV2[NUM_PINS]=
{

	// Debug leds - TM-00-00, TM-00-02
	{11u, 2u, FUNC4, 5u, 22u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},	// PB_2 GPIO5[22] D4
	{7u, 3u, FUNC0, 3u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// P7_3 GPIO3[11] D5

	// cc3000
	{1u, 19u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_CLK | P1_19  | SSP1_CLK    |  1
	{0u, 0u,  FUNC1, 0u, 0u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_MISO | P0_0   | SSP1_MISO   |  1
	{0u, 1u,  FUNC1, 0u, 1u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_MOSI | P0_1   | SSP1_MOSI   |  1
	{4u, 2u,  FUNC0, 2u, 2u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, // IRQ |  P4_2   | GPIO2[2]    |  0
	{4u, 1u,  FUNC0, 2u, 1u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // CS  | P4_1   | GPIO2[1]   |  4
	{8u, 5u,  FUNC0, 4u, 5u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SW EN | P8_5   | GPIO4[5]    |  0
	{4u, 3u,  FUNC0, 2u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // Conn led | P4_3   | GPIO2[3]    |  0
	{4u, 4u,  FUNC0, 2u, 4u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // Error_LED | P4_4   | GPIO2[4]    |  0
	{4u, 9u,  FUNC4, 5u, 13u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // Smartconfig switch | P4_9   | GPIO5[13]   |  4

	// external pins
	{2u, 4u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},	// I2C1_SCL |  P2_4   | I2C1_SCL    |  1
	{2u, 3u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// I2C1_SDA  | P2_3   | I2C1_SDA    |  1
	{3u, 0u, FUNC4, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// SSP0_CLK | P3_0   |  4
	{9u, 1u, FUNC7, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// SSP0_MISO | P9_1     |  7
	{9u, 2u, FUNC7, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// SSP0_MOSI | P9_2     |  7


	// port A - UPDATED TO TM-00-02
	// uart 3
	{9u, 3u, FUNC0, 4u, 15u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL}, 	// G1 | P9_3   | GPIO4[15]    |  0
	{9u, 4u, FUNC4, 5u, 17u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL}, 	// G2 | P9_4   | GPIO5[17]    |  4
	{9u, 0u, FUNC0, 4u, 12u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | P9_0   | GPIO4[12]   |  0

	// port B - UPDATED TO TM-00-02
	// uart2
	{1u, 15u, FUNC0, 0u, 2u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL}, 	// G1 | P1_15   | GPIO0[2]   |  0
	{1u, 16u, FUNC0, 0u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL}, 	// G2 | P1_16   | GPIO0[3]    |  0
	{1u, 4u,  FUNC0, 0u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | P1_4   | GPIO0[11]   |  0

	// port C - Updated to TM-00-02
	// sw uart 1
	{11u, 1u, FUNC4, 5u, 21u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC5, NO_CHANNEL}, 	// G1 | PB_1   | GPIO5[21]   |  4
	{7u, 2u,  FUNC0, 3u, 10u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL}, 	// G2 | P7_2   | GPIO3[10]   |  4
	{11u, 5u, FUNC4, 5u, 25u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | PB_5   | GPIO5[25]   |  4

	// port D - UPDATED TO TM-00-02
	// uart 0
	{9u, 5u, FUNC4, 5u, 18u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL}, 	// G1 | P9_5   | GPIO5[18]    |  0
	{9u, 6u, FUNC0, 4u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL}, 	// G2 | P9_6   | GPIO4[11]   |  4
	{7u, 0u, FUNC0, 3u, 8u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G3 | P7_0   | GPIO3[8]    |  0

	// GPIO port - updated to TM-00-02
	{7u, 4u,  FUNC0, 3u, 12u, ADC_CHANNEL_3, NOTSLAVESELECT, ADC_MODE, 3, NO_CHANNEL},   // A1 | P7_4   | GPIO3[12]   |  0
	{7u, 5u,  FUNC0, 3u, 13u, ADC_CHANNEL_4, NOTSLAVESELECT, ADC_MODE, 4, NO_CHANNEL}, 	// A2 | P7_5   | GPIO3[13]   |  0
	{11u, 6u, FUNC4, 5u, 26u, ADC_CHANNEL_6, NOTSLAVESELECT, ADC_MODE, 6, NO_CHANNEL},  // A3 | PB_6   | GPIO5[26]   |  4
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_0, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A4 | ADC0_0 | -           |  -
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_1, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A5 | ADC0_1 | -           |  -
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_2, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A6 | ADC0_2 | -           |  -
	{8u, 3u,  FUNC0, 4u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL}, 	// G1 | P8_3   | GPIO4[3]    |  0
	{8u, 7u,  FUNC0, 4u, 7u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL}, 	// G2 | P8_7   | GPIO4[7]   |  4
	{11u, 3u, FUNC4, 5u, 23u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, PWM_MODE, FUNC5, SCT_8}, 	// G3 | PB_3   | GPIO5[23]    |  4
	{4u, 8u,  FUNC4, 5u, 12u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // G4 | P4_8   | GPIO5[12]   |  4
	{4u, 0u,  FUNC0, 2u, 0u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, 	// G5 | P4_0   | GPIO2[0]    |  0
	{11u, 0u, FUNC4, 5u, 20u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // G6 | PB_0   | GPIO5[20]   |  4

	// button
	{4u, 9u, FUNC4, 5u, 13u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL} ,  // button | P4_9   | GPIO5[13]   |  4

	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_5, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // unconnected ADC channel 5
	{NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_7, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}   // unconnected ADC channel 7

};

const PinDescription g_APinDescription_boardV3[NUM_PINS]=
{

  // Debug leds - TM-00-00, TM-00-02
  {11u, 2u, FUNC4, 5u, 22u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, // PB_2 GPIO5[22] D4
  {7u, 3u, FUNC0, 3u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // P7_3 GPIO3[11] D5

  // cc3000
  {1u, 19u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_CLK | P1_19  | SSP1_CLK    |  1
  {0u, 0u,  FUNC1, 0u, 0u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_MISO | P0_0   | SSP1_MISO   |  1
  {0u, 1u,  FUNC1, 0u, 1u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP1_MOSI | P0_1   | SSP1_MOSI   |  1
  {4u, 2u,  FUNC0, 2u, 2u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}, // IRQ |  P4_2   | GPIO2[2]    |  0
  {4u, 1u,  FUNC0, 2u, 1u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // CS  | P4_1   | GPIO2[1]   |  4
  {8u, 5u,  FUNC0, 4u, 5u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SW EN | P8_5   | GPIO4[5]    |  0
  {4u, 3u,  FUNC0, 2u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // Conn led | P4_3   | GPIO2[3]    |  0
  {4u, 4u,  FUNC0, 2u, 4u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // Error_LED | P4_4   | GPIO2[4]    |  0
  {4u, 9u,  FUNC4, 5u, 13u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // Smartconfig switch | P4_9   | GPIO5[13]   |  4

  // external pins
  {2u, 4u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // I2C1_SCL |  P2_4   | I2C1_SCL    |  1
  {2u, 3u, FUNC1, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // I2C1_SDA  | P2_3   | I2C1_SDA    |  1
  {3u, 0u, FUNC4, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // SSP0_CLK | P3_0   |  4
  {9u, 1u, FUNC7, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // SSP0_MISO | P9_1     |  7
  {9u, 2u, FUNC7, NO_PORT, NO_BIT, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // SSP0_MOSI | P9_2     |  7


  // port A
  // uart 3
  {9u, 3u, FUNC0, 4u, 15u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL},   // G1 | P9_3   | GPIO4[15]    |  0
  {9u, 4u, FUNC4, 5u, 17u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL},   // G2 | P9_4   | GPIO5[17]    |  4
  {9u, 0u, FUNC0, 4u, 12u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // G3 | P9_0   | GPIO4[12]   |  0

  // port B
  // uart2
  {1u, 15u, FUNC0, 0u, 2u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL},   // G1 | P1_15   | GPIO0[2]   |  0
  {1u, 16u, FUNC0, 0u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL},   // G2 | P1_16   | GPIO0[3]    |  0
  {1u, 4u,  FUNC0, 0u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // G3 | P1_4   | GPIO0[11]   |  0

  // port C
  // sw uart 1
  {11u, 1u, FUNC4, 5u, 21u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC5, NO_CHANNEL},  // G1 | PB_1   | GPIO5[21]   |  4
  {7u, 2u,  FUNC0, 3u, 10u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL},   // G2 | P7_2   | GPIO3[10]   |  4
  {11u, 5u, FUNC4, 5u, 25u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // G3 | PB_5   | GPIO5[25]   |  4

  // port D
  // uart 0
  {9u, 5u, FUNC4, 5u, 18u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL},   // G1 | P9_5   | GPIO5[18]    |  0
  {9u, 6u, FUNC0, 4u, 11u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL},   // G2 | P9_6   | GPIO4[11]   |  4
  {7u, 0u, FUNC0, 3u, 8u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},  // G3 | P7_0   | GPIO3[8]    |  0

  // GPIO port
  {NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_0, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A1 | ADC0_0   | GPIO3[12]   |  0
  {7u, 5u,  FUNC0, 3u, 13u, ADC_CHANNEL_3, NOTSLAVESELECT, ADC_MODE, 3, NO_CHANNEL},   // A2 | P7_5   | GPIO3[13]   |  0
  {7u, 4u,  FUNC0, 3u, 12u, ADC_CHANNEL_4, NOTSLAVESELECT, ADC_MODE, 4, NO_CHANNEL},  // A3 | P7_4   | GPIO5[26]   |  4
  {11u, 6u, FUNC4, 5u, 26u, ADC_CHANNEL_6, NOTSLAVESELECT, ADC_MODE, 6, NO_CHANNEL},   // A4 | PB_6 | -           |  -
  {NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_1, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A5 | ADC0_1 | -           |  -
  {NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_2, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // A6 | ADC0_2 | -           |  -
  {8u, 3u,  FUNC0, 4u, 3u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC7, NO_CHANNEL},  // G1 | P8_3   | GPIO4[3]    |  0
  {4u, 10u, FUNC4, 5u, 14u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, UART_MODE, FUNC1, NO_CHANNEL},  // G2 | P4_10   | GPIO5[14]   |  4
  {4u, 8u,  FUNC4, 5u, 12u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, FUNC1, CTIN_5},  // G3 | P4_8   | GPIO5[12]    |  4
  {11u, 3u, FUNC4, 5u, 23u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, PWM_MODE, FUNC5, SCT_8},   // G4 | PB_3   | GPIO5[23]   |  4
  {4u, 5u,  FUNC0, 2u, 5u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, PWM_MODE, FUNC1, SCT_5},  // G5 | P4_5   | GPIO2[5]    |  0
  {11u, 0u, FUNC4, 5u, 20u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, PWM_MODE, FUNC1, SCT_10},   // G6 | PB_0   | GPIO5[20]   |  4

  // button
  {4u, 9u, FUNC4, 5u, 13u, NO_ANALOG_CHANNEL, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // button | P4_9   | GPIO5[13]   |  4

  // unconnected ADCs

  {NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_5, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL},   // unconnected ADC channel 5
  {NO_PORT, NO_PIN, NO_FUNC, NO_PORT, NO_BIT, ADC_CHANNEL_7, NOTSLAVESELECT, NO_ALTERNATE, NO_ALTERNATE, NO_CHANNEL}   // unconnected ADC channel 7

};

const PinDescription *g_APinDescription = g_APinDescription_boardV3; // default

#ifdef __cplusplus
}
#endif
