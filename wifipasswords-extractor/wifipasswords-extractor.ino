#include <BleKeyboard.h>
#define pin 2
bool laststate1=HIGH;
const char* name="Logitech";
BleKeyboard keyboard(name,"Espressif",,80);
bool state1;
void setup(){
  Serial.begin(115200);
  pinMode(pin,INPUT_PULLUP);
  keyboard.begin();
}
void loop(){
  if(keyboard.isConnected()){
    state1=digitalRead(pin);
    if(laststate1==HIGH && state1==LOW){
      Serial.println("Trigger running...");
      keyboard.press(LEFT_KEY_GUI);
      keyboard.press('r');
      delay(500);
      keyboard.releaseAll();
      delay(1000);
      keyboard.print("powershell");
    }
  }
}
