# Advanced Star Delta Timer

The **Advanced Star Delta Timer** is an intelligent control system designed to start industrial motors efficiently while managing frequent voltage fluctuations. This system is adaptable to various industrial needs, providing reliable and precise motor control.

# Acknowledgement
• I express my sincere gratitude to Trick Robotics for providing me with the opportunity to undertake this internship. The experience and knowledge gained during this period have been invaluable.

•	I extend my heartfelt thanks to my external guide,Mr.Ajit Sandhi , for their guidance and support throughout the internship. Their expertise and insights greatly contributed to my learning and development.

 Contact Details of Trick Robotics
  Address: Vidhyanagar,bhavnagar,364001,Gujarat
  E-mail: trickrobotics@gmail.com

## Features

- **Voltage Compatibility:** Operates at 440V AC or 220V AC, 50Hz.
- **Inputs:** Start, Stop, Error.
- **Outputs:** Mains, Star, Delta.
- **Adjustable Timing:**
  - **Time T1:** 0 to 60 seconds.
  - **Time T2:** 50ms to 100ms.
- **Smooth Transition:** Ensures smooth star to delta transitions, reducing power surges and mechanical stress.
- **Safety:** Includes robust safety interlocks and overload protection.

## Components

- **Relay:** Fundamental in switching circuits and safety mechanisms.
- **Optocoupler:** Isolates circuit sections to prevent high voltage impacts.
- **Transistor:** Acts as a switch and amplifier in circuits.
- **Diode:** Used for rectification purposes.
- **Potentiometer:** Allows adjustable voltage levels and tuning.
- **STM32F103C8T6:** Core microcontroller for embedded control systems.
- **7805 Voltage Regulator:** Provides a stable 5V output.

## System Functionality

### Star Delta Transition

The system starts the motor in the star configuration to reduce the initial inrush current. After a preset time (T1), it transitions to the delta configuration, ensuring smooth operation without mechanical stress or power surges.

### Safety Mechanisms

The system monitors for errors or abnormal conditions continuously. If an error is detected, it stops the motor immediately to prevent damage, ensuring the safety of both equipment and operators.

### Adjustable Timing

Timing parameters for the transition (T1 and T2) are easily adjustable to suit different motor requirements, providing flexibility for various industrial settings.

## Project Overview

### Problem Statement

Develop a cost-effective, reliable, and efficient star delta timer system for industrial motors, capable of handling voltage fluctuations and providing smooth motor startup.

### Challenges

1. **Component Pricing:** Ensured cost-effective component sourcing through market research.
2. **Prototyping Issues:** Resolved IC damage during soldering by improving techniques and handling practices.

### Design and Development Process

1. **Research:** Studied advanced star delta timers and related technologies.
2. **Component Selection:** Gathered and tested necessary components individually.
3. **Circuit Design:** Built and simulated relay circuits in Proteus, then assembled on a breadboard.
4. **Optimization:** Optimized circuit designs and code, troubleshooting and debugging as needed.
5. **PCB Design:** Created PCB layout and assembled components on Zero PCB.

### Future Steps

The prototype will be tested by Trick Robotics, Bhavnagar, followed by necessary modifications and quantity production.

## Getting Started

To set up and run this project:

1. Clone the repository:
   ```bash
    https://github.com/Vegad-uday/Advanced-Star-Delta-Timer
2.Open the project in Arduino IDE.

3.Go to File > Preferences in Arduino IDE and add the following URL to the Additional Board Manager URLs text box:

    https://github.com/stm32duino/BoardManagerFiles/raw/master/STM32/package_stm_index.json
4.Open the Boards Manager from Tools > Board > Boards Manager and install "STM32F1xx/GD32F1xx boards".

5.Select STM32F103C8T6 as your board from Tools > Board > STM32F1xx/GD32F1xx boards.

6.Connect your components according to the Code.

7.Upload the code to your STM32 microcontroller.

8.Test the system using the adjustable timing parameters (T1 and T2).

##Contributing

If you would like to contribute to this project, please open an issue or submit a pull request with your improvements or bug fixes.
