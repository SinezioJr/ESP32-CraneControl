#include <interface.h>
#include <joystic.h>
#include <craneController.h>

Joystick joystick = Joystick(12, 13);

CraneParams crane;

volatile bool selectFlag = false;

void IRAM_ATTR changeSelectFlag()
{
  Serial.println("Pres");
  selectFlag = !selectFlag;
}

void setup()
{
  pinMode(14, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(14), changeSelectFlag, RISING);

  Serial.begin(115200);
  joystick.begin();

  initDisplay();
  drawVerticalVission();

  drawCrane(crane.X, crane.Y);
  drawSuperiorVision(crane.angle);
}

void loop()
{
  craneController(&crane, joystick.readX(), joystick.readY(), selectFlag);
  if (selectFlag)
  {
    drawCrane(crane.X, crane.Y);
  }
  else
  {
    drawSuperiorVision(crane.angle);
  }
}