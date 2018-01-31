#include <TCS3200.h>

uint8_t RGBvalue[3];
bool feedback = false;
TCS3200 colSens;
int LDR = 0;

/****    Colour Coding Information ****

        0:    No Illumination
        1:    Red
        2:    Green
        3:    Blue
        4:    White
        5:    Yellow

Brightness Scale : 1 to 9.

*/

void setup()
{
  Serial.begin(115200);
  Serial.println("BEGIN");
  colSens.begin();
}

void loop()
{
  colSens.loop();
  
  LDR = analogRead(A0);
  LDR = map(LDR, 0, 1023, 0, 9);
  Serial.print("B:");
  Serial.print(LDR);
  Serial.print(" ");

  colSens.getRGB (RGBvalue);
  //colSens.getRGBtoMaxCorrection (RGBvalue);

/*
  Serial.print(RGBvalue[0]);
  Serial.print(",");
  Serial.print(RGBvalue[1]);
  Serial.print(",");
  Serial.println(RGBvalue[2]);
*/

  if (feedback == true) {
    Serial.print("\tR:\t"); Serial.print(RGBvalue[0]);
    Serial.print("\tG:\t"); Serial.print(RGBvalue[1]);
    Serial.print("\tB:\t"); Serial.print(RGBvalue[2]);
    //Serial.print("\tSUM:\t"); Serial.print(RGBvalue[2]+RGBvalue[1]+RGBvalue[0]);
    
    Serial.print("\t");
  }

  if ( RGBvalue[0] > 200 && RGBvalue[1] > 200 && RGBvalue[2] > 200 ) {
    Serial.println("C:0");
    if (feedback == true)
      Serial.println("LOW LUMINANCE");
  }

  else if ( RGBvalue[0] > 230 && RGBvalue[1] > 70) {
    Serial.println("C:5");
    if (feedback == true)
      Serial.println("YELLOW");
  }

  else if ( RGBvalue[0] > 175 && RGBvalue[1] > 80 && RGBvalue[2] > 100) {
    Serial.println("C:4");
    if (feedback == true)
      Serial.println("WHITE");
  }
  else if ( RGBvalue[0] > 200  ) {
    Serial.println("C:1");
    if (feedback == true)
      Serial.println("RED");
  }

  else if ( RGBvalue[1] > 200) {
    Serial.println("C:2");
    if (feedback == true)
      Serial.println("GREEN");
  }
  else if ( RGBvalue[2] > 200) {
    Serial.println("C:3");
    if (feedback == true)
      Serial.println("BLUE");
  }

  else if ( RGBvalue[0] > 1.5 * RGBvalue[1]) {
    Serial.println("C:1");
    if (feedback == true)
      Serial.println("RED");
  }

  else if ( RGBvalue[1] > 1.5 * RGBvalue[2]) {
    Serial.println("C:2");
    if (feedback == true)
      Serial.println("GREEN");
  }
  else if ( RGBvalue[2] > 1.5 * RGBvalue[0]) {
    Serial.println("C:3");
    if (feedback == true)
      Serial.println("BLUE");
  }

}
