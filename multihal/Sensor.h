class AirQualitySensor : public OnChangeSensor {
    public:
        AirQualitySensor(int32_t sensorHandle, ISensorsEventCallback* callback);

    protected:
        std::vector<Event> readEvents() override;

    protected:
        float sensorRead = 0;

    static int64_t timevalToNano(timeval const& t) {
        return t.tv_sec*1000000000LL + t.tv_usec*1000;
    }
};