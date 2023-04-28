#include <interface.h>
#include <joystic.h>
#include <craneController.h>

Joystick joystick = Joystick(34, 23);
// Joystick joystick = Joystick(34);

CraneParams crane;

volatile bool selectFlag = false;

#define SW 22
#define BUTTON 19

void IRAM_ATTR changeSelectFlag()
{
  Serial.println("Pressed");
  selectFlag = !selectFlag;
}

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), changeSelectFlag, RISING);

  Serial.begin(9600);
  joystick.begin();

  initDisplay();
  drawVerticalVision();

  drawCrane(crane.X, crane.Y);
  drawSuperiorVision(crane.angle);

  showInfo(crane.X, crane.Y, crane.angle, selectFlag);
}

void loop()
{
  tft.fillScreen(BLACK); // Limpando a tela
  craneController(&crane, joystick.readX(), 55, selectFlag);
  drawCrane(crane.X, crane.Y);
  drawSuperiorVision(crane.angle);
  drawVerticalVision();
  showInfo(crane.X, crane.Y, crane.angle, selectFlag);

  Serial.print("X:");
  Serial.print(crane.X);
  Serial.print(" Y:");
  Serial.print(crane.Y);
  Serial.print(" Angle:");
  Serial.print(crane.angle);
  Serial.print(" selectFlag:");
  Serial.print(selectFlag);
  Serial.print(" BUTTON:");
  Serial.println(digitalRead(BUTTON));
  delay(500);
}