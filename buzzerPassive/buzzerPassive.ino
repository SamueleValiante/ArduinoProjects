int red = 11;
int blue = 10; 
int green = 9;
int val;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for(val=255; val>0; val--)
  {
    analogWrite(red, val);
    analogWrite(blue, 0);
    analogWrite(green, 0);
    delay(1);
  }

  for(val=0; val<255; val++)
  {
    analogWrite(red, 0);
    analogWrite(blue, 0);
    analogWrite(green, val);
    delay(1);
  }

  

  Serial.println(val, DEC);
}