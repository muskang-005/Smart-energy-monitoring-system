# Smart-energy-monitoring-system
## Abstract
This project presents a smart energy monitoring system using Arduino that measures current, calculates power consumption, and estimates energy usage in real time. It also provides overload protection and cost estimation for efficient energy management.


## Table of Contents
- Introduction
- System Overview
- Components Used
- Circuit Design
- Working Principle
- Results
- Conclusion


## Introduction
With increasing energy consumption, monitoring and managing electricity usage has become essential. This project aims to provide a low-cost solution for real-time power monitoring and load management.


## System Overview
The system uses a current sensor connected to an Arduino to measure current. Power is calculated using voltage and current, and energy consumption is tracked over time. The system displays real-time data on an LCD and alerts users in case of overload.


## Components Used
- Arduino Uno
- 16x2 LCD Display
- Buzzer
- LED
- Resistors and wires

## Circuit Design


![Circuit](images/)


---

## Working Principle
- Analog current signal is read using Arduino
- Power is calculated using P = V × I
- Energy is computed over time in kWh
- System classifies load (LOW, NORMAL, HIGH)
- Overload triggers buzzer and LED alert


## Results
- Successfully measured real-time power consumption
- Displayed energy usage and cost on LCD
- Detected overload conditions and triggered alerts


![Output](images/output.jpg)

---

## Conclusion
This project shows how we can monitor electrical power and energy using Arduino. It calculates power, energy consumption, and cost in real time and displays it on an LCD.
It also gives an alert when the load is high or in overload condition using LED and buzzer. This helps in preventing damage and saving energy.
In future, this system can be improved by adding internet connectivity to monitor data remotely.
