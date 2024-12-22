# Object Detection and Counting Using ESP8266 and TF Luna LiDAR

## Objective of the Project

1. **To detect an object within a given range**: The detection range is set to 80 cm (can be customized).
2. **To count the number of objects detected**: An object is counted only if it remains within the detection range for more than 1 second.
3. **To avoid false counts when an object is removed**: If the object is removed from the detection range, the count does not increase.
4. **To avoid false counts when the object is repositioned quickly**: If the object is repositioned within 1 second of removal, even if it remains in the detection range for more than 1 second, the count does not increase.
5. **To count objects accurately when repositioned after sufficient time**: If the object is repositioned after 1 second of removal and remains in the detection range for more than 1 second, the count increases.
6. **To avoid re-triggering issues**: The system ensures stable and reliable object detection and counting.

---

## Required Components

- **ESP8266 Microcontroller**
- **TF Luna LiDAR Sensor**
- **Arduino IDE**
- **USB Cable**

---

## Required Libraries

1. **Wire Library**: For I2C communication between the ESP8266 and TF Luna LiDAR.
   - Pre-installed in the Arduino IDE.

2. **TFLI2C Library**: For interfacing with the TF Luna LiDAR sensor.
   - [Download the TFLI2C Library](https://github.com/your-link-to-library)

3. **ArduinoJson Library**: For handling JSON serialization and deserialization.
   - [Download ArduinoJson Library](https://github.com/bblanchon/ArduinoJson)

---

## Installation Steps

1. **Set Up Arduino IDE**
   - Install the latest version of the Arduino IDE from [arduino.cc](https://www.arduino.cc/).
   - Install the ESP8266 board support package in Arduino IDE.
     - Go to **File > Preferences**.
     - Add the following URL to the "Additional Board Manager URLs":
       `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
     - Go to **Tools > Board > Board Manager** and search for "ESP8266".
     - Click **Install**.

2. **Install Required Libraries**
   - Open Arduino IDE.
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for `TFLI2C` and install it.
   - Search for `ArduinoJson` and install it.

3. **Connect Hardware**
   - Connect the TF Luna LiDAR sensor to the ESP8266 using I2C (SDA and SCL pins).
   - Power the ESP8266 and LiDAR using a suitable power source.

4. **Upload Code**
   - Open the provided code in the Arduino IDE.
   - Select the correct board and port under **Tools > Board** and **Tools > Port**.
   - Click **Upload** to upload the code to the ESP8266.

---

## How It Works

1. The TF Luna LiDAR sensor continuously measures the distance to objects in its line of sight.
2. If an object is detected within the defined threshold limit (80 cm):
   - The system checks if the object remains within the range for more than 1 second before counting it.
   - If the object is removed and repositioned too quickly, the system avoids incrementing the count to prevent false triggering.
3. The object count and distance data are serialized into a JSON string and printed to the Serial Monitor.

---

## Example Output

```json
{"Count": 5, "Dist": 45}
```
- `Count`: Total number of objects detected.
- `Dist`: Current distance to the object in cm.

---

## Features

- Real-time object detection and counting.
- JSON output for easy integration with other systems.
- Configurable detection thresholds and timing parameters.

---

## Applications

- Smart home automation.
- Industrial object counting systems.
- Robotics and automation.

---

## Troubleshooting

1. **No detection or inaccurate counts**:
   - Verify the connections between the TF Luna LiDAR and ESP8266.
   - Ensure the threshold and timing parameters are suitable for your application.

2. **Serial Monitor not showing output**:
   - Check the selected COM port in Arduino IDE.
   - Ensure the baud rate is set to 9600.

---

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute this project, provided you include the original license file and give proper attribution.

Feel free to fork and contribute to this project on [GitHub](https://github.com/your-repository-link).

