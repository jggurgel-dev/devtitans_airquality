AirQualitySensor::AirQualitySensor (int32_t sensorHandle, ISensorsEventCallback* callback)
  : OnChangeSensor(sensorHandle, callback), mInputReader((size_t)(4)) {
    mSensorInfo.name = "AirQuality Sensor";
    mSensorInfo.vendor = "devtitans";
    mSensorInfo.type = SensorType::DEVICE_PRIVATE_BASE;
    mSensorInfo.typeAsString = SENSOR_STRING_TYPE_LIGHT;
    mSensorInfo.maxRange = 43000.0f;
    mSensorInfo.resolution = 10.0f;
    mSensorInfo.power = 0.001f;         // mA
    mSensorInfo.minDelay = 200 * 1000;  // microseconds
}

std::vector AirQualitySensor::readEvents() {
    std::ifstream in("/sys/kernel/airquality/pm10"); // open sysfs file to read sensor read

    std::vector<Event> events;

    Event event_s;
    event_s.timestamp = ::android::elapsedRealtimeNano();
    event_s.sensorHandle = mSensorInfo.sensorHandle;
    event_s.sensorType = mSensorInfo.type;

    if (in) {
        in >> sensorRead; 
        in.close();
    } 

    event_s.u.scalar = sensorRead;
    events.push_back(event_s);

    return events;
}