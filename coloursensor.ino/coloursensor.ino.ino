/*
 * Colour Sensor TCS 3200
 * 
 * Functionality : Detect Red,Yellow,Blue,Green light from an LED source.
 * 
 * 
 */


const int s0 = 3;  
const int s1 = 4;  
const int s2 = 5;  
const int s3 = 6;  
const int out = 2;   

int red = 0;  
int green = 0;  
int blue = 0;  

 
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
 Serial.print("R Intensity:");        Serial.print(red, DEC);  
 Serial.print(" G Intensity: ");      Serial.print(green, DEC);  
 Serial.print(" B Intensity : ");     Serial.print(blue, DEC);  
 //Serial.println();

 if (red < blue && green < blue)
 {  
  Serial.println(" - (Yellow Color)");  
 }
 else if (red < blue && green < blue)
 {  
  Serial.println(" - (Yellow Color)");  
 }
  
 else if (red < blue && red < green && red <100 && blue< 100 )
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
 else{
 Serial.println();  
 }
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
