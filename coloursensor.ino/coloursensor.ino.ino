/*
   Colour Sensor TCS 3200

   Functionality : Detect Red,Yellow,Blue,Green light from an LED source.


*/

const int threshold=3;

int feedback = false;

const int s0 = 3;
const int s1 = 4;
const int s2 = 5;
const int s3 = 6;
const int out = 2;

int red = 0;
int green = 0;
int blue = 0;

int  pred = red;
int  pblue = blue;
int  pgreen = green;


int Rcount=0, Gcount=0,Bcount=0,Wcount=0;


void setup()
{
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}
void loop()
{
  color();
  if (feedback)
  {
  Serial.print(" R Intensity:");       Serial.print(red, DEC);
  Serial.print(" G Intensity: ");      Serial.print(green, DEC);
  Serial.print(" B Intensity : ");     Serial.print(blue, DEC);
  }
  
  Serial.println();

  // Removing noise data
  /*
  Serial.print("  RedD");
  Serial.print(pred - red);
  Serial.print("  GreenD");
  Serial.print(pgreen - green);
  Serial.print("  BlueD");
  Serial.print(pblue - blue);
  */

  
  if (   ( pred - red <= 5 || pred - red <= -5 ) && ( pgreen - green <= 5 || pgreen - green <= -5 ) && ( pblue - blue <= 5 || pblue - blue <= -5 )    ) {


      if (red < blue && red < green && red <50 && green <70 && blue<60)
      {
        if (feedback)
          Serial.println(" - (White Color)");
      Wcount+=1;
      Rcount=0;Gcount=0;Bcount=0;
      }
      else if (red < blue && red < green)
      {
        if (feedback)
          Serial.println(" - (Red Color)");
      Rcount+=1;
      Wcount=0;Gcount=0;Bcount=0;
      }

      else if (blue < red && blue < green)
      {
      Bcount+=1;
      Rcount=0;Gcount=0;Wcount=0;
      if (feedback)
        Serial.println(" - (Blue Color)");
      }

      else if (green < red && green < blue)
      {
      Gcount+=1;
      Wcount=0;Bcount=0;Rcount=0;
      if (feedback)
        Serial.println(" - (Green Color)");
      }
      else
      {
        if (feedback)
          Serial.print('\n');
      }

      if ( Wcount>threshold )
            Serial.println(" - (White Color)");
      else if ( Rcount>threshold )
          Serial.println(" - (Red Color)"); 
      else if ( Gcount>threshold )
          Serial.println(" - (Green Color)");
      else if ( Bcount>threshold )
          Serial.println(" - (Blue Color)");
      else 
          Serial.print("\n");

      if ( Rcount>5 || Gcount>5 || Bcount>5 || Wcount>5 )
          {
            Rcount=0;
            Gcount=0;
            Bcount=0;
            Wcount=0;
          }

          
/*
      if (red < blue && red < green&& red <20)
      {
      Serial.println(" - (Red Color)");
      }

      else if (red < blue && green < blue)
      {
        Serial.println(" - (Yellow Color)");
      }
      else if (red < blue && red < green && red < 100 && blue < 100 )
      {
        Serial.println(" - (Dark yellow Color)");
      }
      
      if (blue < red && blue < green)
      {
        Serial.println(" - (Blue Color)");
      }
      if (green < red && green < blue)
      {
        Serial.println(" - (Green Color)");
      }
*/
    }
    else
    {
      if (feedback)
      Serial.println(" - (Noise Data)");
    }



    // storing data from last loop onto previous variables
    pred = red;
    pblue = blue;
    pgreen = green;


    delay(300);
  }
  void color()
  {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    //count OUT, pRed, RED
    delay(10);
    red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s3, HIGH);
    delay(10);
    //count OUT, pBLUE, BLUE
    blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s2, HIGH);
    //count OUT, pGreen, GREEN
    delay(10);
    green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  }
