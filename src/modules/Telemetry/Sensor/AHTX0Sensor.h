#include "../mesh/generated/meshtastic/telemetry.pb.h"
#include "TelemetrySensor.h"
#include <Adafruit_AHTX0.h>

class AHTX0Sensor : public TelemetrySensor
{
  private:
    Adafruit_AHTX0 ahtx0 = Adafruit_AHTX0();

  protected:
    virtual void setup() override;

  public:
    AHTX0Sensor();
    virtual int32_t runOnce() override;
    virtual bool getMetrics(meshtastic_Telemetry *measurement) override;
};