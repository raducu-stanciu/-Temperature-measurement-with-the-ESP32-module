#include<LiquidCrystal.h>
//LiquidCrystal lcd(12, 14, 27 , 26, 25 , 33);
const int rs = 33, en = 25, d4 = 26, d5 = 27, d6 = 14, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int PIN_ANALOG_IN;

void setup() {
  // put your setup code here, to run once:
  PIN_ANALOG_IN=4;
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temperatura:") ;

  lcd.setCursor(0 ,1 );

 // lcd.print("UPB-anxiETTI");
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adcValue= analogRead(PIN_ANALOG_IN);
  double voltage = (double)adcValue / 4095.0 *3.3;
  double Rt = 10000 * voltage / (3.3 - voltage);
  double temperature_K = 1 / (1/(273.15+25) + log(Rt/10000)/3950.0  );
  double temperature_C = temperature_K - 273.15;


   Serial.print("ACD value : " );   Serial.print((int)adcValue ); Serial.print("\t " );
  Serial.print("Rt : " );   Serial.print((double)Rt ); Serial.print("ohmi\t " );
  Serial.print("Voltage : " );   Serial.print((double)voltage ); Serial.print("V\t " );
  Serial.print("Temperature : " );   Serial.print((double)temperature_C ); Serial.print("C\t " );
  Serial.print("\n " );
   lcd.setCursor(0 ,1 );
   lcd.print((double)temperature_C) ;
   lcd.print(" C") ;
  delay(1000);


}