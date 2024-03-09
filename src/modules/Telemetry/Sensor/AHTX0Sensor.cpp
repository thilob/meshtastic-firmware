#include "AHTX0Sensor.h"
#include "../mesh/generated/meshtastic/telemetry.pb.h"
#include "TelemetrySensor.h"
#include "configuration.h"
#include <Adafruit_AHTX0.h>

AHTX0Sensor::AHTX0Sensor() : TelemetrySensor(meshtastic_TelemetrySensorType_AHTX0, "AHTX0") {}

int32_t AHTX0Sensor::runOnce()
{
    LOG_INFO("Init sensor: %s\n", sensorName);
    if (!hasSensor()) {
        return DEFAULT_SENSOR_MINIMUM_WAIT_TIME_BETWEEN_READS;
    }
    status = ahtx0.begin();
    return initI2CSensor();
}

void AHTX0Sensor::setup() {}

bool AHTX0Sensor::getMetrics(meshtastic_Telemetry *measurement)
{

    sensors_event_t humidity, temp;
    ahtx0.getEvent(&humidity, &temp);

    measurement->variant.environment_metrics.temperature = temp.temperature;
    measurement->variant.environment_metrics.relative_humidity = humidity.relative_humidity;

    return true;
}