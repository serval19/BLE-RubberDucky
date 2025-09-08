#include <BleKeyboard.h>


#define pin1 2
const char* name="Logitech";
BleKeyboard keyboard(name,"Espressif",100);
bool state=true;


void setup() {
  Serial.begin(115200);
  pinMode(pin1,INPUT_PULLUP);
  
  keyboard.begin();
  

  // put your setup code here, to run once:

}

void loop() {
  
  while(state){
    if(keyboard.isConnected()){
    
      Serial.println("Trigger is running.");
      keyboard.press(KEY_LEFT_GUI);
      keyboard.press('r');
      delay(500);
      keyboard.releaseAll();
      delay(1000);
      keyboard.print("notepad");
      delay(100);
      keyboard.press(KEY_RETURN);
      delay(1000);
      keyboard.releaseAll();
      delay(1000);
      const char* text="Don't connect random bluetooth devices without Checking first!";
      for(int i=0;i<strlen(text);i++){
        keyboard.print(text[i]);
        delay(100);
      }

    }
    

  
  delay(10);
  state=false;

  }
  
  
}

  // put your main code here, to run repeatedly:


