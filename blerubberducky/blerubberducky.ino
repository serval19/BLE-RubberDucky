#include <BleKeyboard.h>
const char *name="Logitech";
#define pin1 2;
#define pin2 4;
BleKeyboard keyboard(name,"Espressif",100);
bool laststate1=HIGH;
bool laststate2=HIGH;
void setup() {
  Serial.begin(115200);
  pinMode(pin1,INPUT_PULLUP);
  pinMode(pin2,INPUT_PULLUP);
  keyboard.begin();

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
