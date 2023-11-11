#include "SdsDustSensor.h"

float pm25, pm10;

SdsDustSensor sds(Serial2); 

void process_command(String command) {
    command.trim();
    command.toUpperCase();

    Serial.println("DBG Received command: " + command);

    if (command == "GET_PM25") {
      Serial.printf("RES GET_PM25 %d\n", (int) (pm25 * 100));
    } else if (command == "GET_PM10") {
      Serial.printf("RES GET_PM10 %d\n", (int) (pm10 * 100));
    } else {
      Serial.println("ERR Unknown command");
    }
}

void serial_listener() {
    String serial_command;
    while(Serial.available() > 0) {
        char serial_char = Serial.read();
        serial_command += serial_char;

        if (serial_char == '\n') {
            process_command(serial_command);
            serial_command = "";
        }
    }
}

void setup() {
    Serial.begin(9600);
    sds.begin(); // this line will begin Serial1 with given baud rate (9600 by default)

    Serial.println(sds.queryFirmwareVersion().toString()); // prints firmware version
    Serial.println(sds.setQueryReportingMode().toString()); // ensures sensor is in 'query' reporting mode
    Serial.println(sds.setCustomWorkingPeriod(5).toString()); // ensures sensor is in 'query' reporting mode

    pm25 = -1;
    pm10 = -1;

    Serial.println("DBG AirQuality Initialized.");
}

void loop() {
    String serial_command;
    sds.wakeup();
    Serial.println("Sensor is working...");

    constexpr uint32_t down_s = 30;
    uint32_t deadline = millis() + down_s * 1000;
    while (static_cast<int32_t>(deadline - millis()) > 0) {
        serial_listener();
        delay(1000);
    }

    PmResult pm = sds.queryPm();
    if (pm.isOk()) {
        pm25 = pm.pm25;
        pm10 = pm.pm10;
        Serial.println(pm.toString());
    } else {
        Serial.print("Could not read values from sensor by this reason: ");
        Serial.println(pm.statusToString());
    }

    WorkingStateResult state = sds.sleep();
    if (state.isWorking()) {
        Serial.println("Problem with sleeping the sensor");
    } else {
        Serial.println("Sensor is sleeping...");
    }

    constexpr uint32_t sleep_s = 210;
    deadline = millis() + sleep_s * 1000;
    while (static_cast<int32_t>(deadline - millis()) > 0) {
        serial_listener();
        delay(1000);
    }
}
