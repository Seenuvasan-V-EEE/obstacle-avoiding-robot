# Obstacle Avoiding Robot (Arduino)

An autonomous robot that detects and avoids obstacles using ultrasonic and IR sensors. Designed using Arduino UNO and SG90 servo for directional control.

## 🔧 Components Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- IR Sensors (2x)
- L298N Motor Driver
- DC Motors (2x)
- SG90 Servo Motor
- Wheels & Chassis
- 9V Battery or Power Bank

## ⚙️ Working Principle

1. Ultrasonic sensor detects obstacle distance.
2. If an obstacle is within threshold, the robot stops.
3. It checks left and right using a servo-mounted sensor.
4. Turns toward the clearer side.
5. Uses IR sensors for line or edge detection (optional).

## 🛠️ Circuit Diagram

*(Include a wiring diagram image or link here)*

## 🧠 Arduino Code

Code is available in the `arduino/` folder.

## 📸 Robot Demo

*(Upload a photo or video if available in the `images/` folder)*

## 🧪 Status

✅ Tested and working  
🛠️ Possible improvements: PID turning, Bluetooth control, ROS port

## 📄 License

MIT License