#include <TCS3200.h>

uint8_t RGBvalue[3];

TCS3200 colSens;

void setup()
{
  Serial.begin(115200);
  Serial.println("BEGIN");
  colSens.begin();
}

void loop()
{
  colSens.loop();
  colSens.getRGB (RGBvalue);
  //colSens.getRGBtoMaxCorrection (RGBvalue);

      Serial.print("\tR:\t"); Serial.print(RGBvalue[0]);
      Serial.print("\tG:\t"); Serial.print(RGBvalue[1]);
      Serial.print("\tB:\t"); Serial.print(RGBvalue[2]);
      Serial.print("\t");
      Serial.println();    

if ( RGBvalue[0] >230 && RGBvalue[1] >70){
  Serial.print("\t\t YELLOW");
}

else if ( RGBvalue[0] >175 &&RGBvalue[1] >80 && RGBvalue[2] >100){
  Serial.print("\t\t WHITE");
}
else if ( RGBvalue[0] > 200  ){
  Serial.print("\t\t RED");
}

else if ( RGBvalue[1] >200){
  Serial.print("\t\t GREEN");  
}
else if ( RGBvalue[2] >200){
    Serial.print("\t\t BLUE");
}



else if ( RGBvalue[0] >1.5*RGBvalue[1]){
  Serial.print("\t\t RED");
}

else if ( RGBvalue[1] >1.5*RGBvalue[2]){
  Serial.print("\t\t GREEN");  
}
else if ( RGBvalue[2] >1.5*RGBvalue[0]){
    Serial.print("\t\t BLUE");
}

}
