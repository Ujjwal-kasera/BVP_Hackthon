#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHTesp.h>
const int DHT_PIN = 2;
DHTesp dhtSensor;
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Wire.begin(23);
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello KRISHAK");
  delay(2000);
  lcd.clear();
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  lcd.setCursor(0,0);
  int N_value=analogRead(A0);
  lcd.print("N: "+String(N_value)+"mg/Kg");
  lcd.setCursor(0,1);
  int P_value=analogRead(A1);
  lcd.print("P: "+String(P_value)+"mg/Kg");
  lcd.setCursor(0,2);
  int K_value=analogRead(A3);
  lcd.print("K: "+String(K_value)+"mg/Kg");
  delay(1000);
  // int i = analogRead(A0);
  // String msg = String(i); 
  // lcd.clear();
  // lcd.print("Soil: ");
  // lcd.print(msg);
  // delay(1000);
  // TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  // lcd.print("Temperature: " + String(data.temperature) + "C");
  // lcd.setCursor(0,2);
  // lcd.print("Humidity: " + String(data.humidity) + "%");
  // delay(100);
}