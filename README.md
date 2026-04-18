# 🚀 Autonomous Self-Healing CubeSat On-Board Computer (OBC)

## 📌 Overview
This project focuses on designing an Autonomous Self-Healing CubeSat On-Board Computer (OBC) using embedded systems and real-time processing.

The system continuously monitors satellite health parameters, detects faults intelligently, and performs automatic corrective actions without human intervention.

---

## 🎯 Objectives
- Real-time monitoring of voltage, temperature, and motion
- RTOS-based multitasking
- Intelligent fault detection
- Digital Twin-based predictive analysis
- Self-healing mechanisms
- LoRa-based long-range communication
- Adaptive power optimization

---

## 🧰 Components & Software

- ESP32 Development Board
- INA219 Voltage/Current Sensor
- LM35 Temperature Sensor
- MPU6050 IMU
- LoRa SX1278 Module
- LEDs
- Li-ion Battery
- Voltage Regulator / Boost Converter
- Resistors & Wires
- FreeRTOS

---

## 🧠 System Architecture

### Sensor Data Acquisition
- Voltage → INA219  
- Temperature → LM35  
- Motion → MPU6050  

### RTOS Task Management
- Sensor Task  
- Fault Detection Task  
- Communication Task  
- Telemetry Task  

### Fault Detection
System Modes:
- NORMAL  
- SAFE  
- CRITICAL  

### Digital Twin
- Predicts expected behavior  
- Detects anomalies  

### Predictive Analysis
- Uses historical trends to predict failures  

### Health Scoring
- > 70 → NORMAL  
- 40–70 → SAFE  
- < 40 → CRITICAL  

### Self-Healing Actions
- Retry sensor read  
- Reinitialize communication  
- Disable faulty module  
- Reconfigure system  

### LoRa Telemetry
- Sends sensor data, mode, and alerts  

### Mission Modes
- Science Mode  
- Communication Mode  
- Survival Mode  

---

## ⚙️ Implementation

### Hardware Connections
- I2C: SDA → GPIO 21, SCL → GPIO 22  
- LM35 → GPIO 36  
- LoRa SPI:
  - NSS → GPIO 5  
  - RST → GPIO 14  
  - DIO0 → GPIO 26  

- LEDs:
  - Green → GPIO 2  
  - Red → GPIO 4  

- Button → GPIO 15  

---

### RTOS Tasks

#### Sensor Task
- Reads sensors every 1 second  
- Computes stability index  

#### Fault Task
- Runs every 500 ms  
- Calculates fault score  
- Determines system mode  

#### LoRa Task
- Sends telemetry every 2 seconds  

---

### Watchdog System
- 5-second timeout  
- Automatic reset on failure  
- Manual reset via button  

---

### Telemetry
- Binary packet transmission  
- Packet size: 24 bytes  

---

### Base Station
- ESP32 with LoRa module  
- Receives and displays telemetry  

---

## 🧪 Testing
- Real-time telemetry verified  
- Fault injection tested  
- Temperature stress testing  
- Watchdog reset validated  

---

## ⚠️ Challenges
- Sensor noise and calibration  
- RTOS synchronization  
- Power instability  
- LoRa communication delay  
- Debugging integration  
- False fault detection  

---

## 🌍 Applications
- CubeSat missions  
- Spacecraft health monitoring  
- Autonomous systems  
- Remote sensing  
- Industrial fault detection  
- IoT predictive maintenance  

---

## 📸 Images
## CubeSat
<img width="1204" height="1600" alt="image" src="https://github.com/user-attachments/assets/99564572-fecb-4f05-8adb-2286fbf45f66" />
<img width="1600" height="1204" alt="image" src="https://github.com/user-attachments/assets/6aa1b9a0-5c15-4f0a-8dda-f9a82dc58da7" />
<img width="1600" height="1204" alt="image" src="https://github.com/user-attachments/assets/86b995d2-947a-497f-b20c-20bea62cd860" />
<img width="1204" height="1600" alt="image" src="https://github.com/user-attachments/assets/ab4056ee-78ac-4d2e-a748-af5a93b542d2" />

## Dashboard
<img width="1512" height="801" alt="WhatsApp Image 2026-04-17 at 9 25 40 PM" src="https://github.com/user-attachments/assets/2a57a336-1771-41c4-b236-8a235215c0f9" />


---

## 🎥 Demo Video
https://drive.google.com/file/d/1EqoDplPCBtw2ElLD_WiDVMEGUhs0tQ2y/view?usp=sharing

---

## 📚 Concepts Learned
- Embedded systems (ESP32)  
- FreeRTOS  
- Sensor interfacing  
- Fault detection & recovery  
- Digital Twin  
- LoRa communication  
- Low-power design  

---

## 🔮 Future Work
- Machine learning integration  
- Advanced Digital Twin  
- Cloud dashboard  
- Full CubeSat deployment  

---

## 🏁 Conclusion
This project demonstrates an intelligent, autonomous, and self-healing CubeSat OBC capable of real-time monitoring, fault detection, and recovery.

It is scalable, power-efficient, and suitable for advanced aerospace and embedded applications.
