int sensorPin=7; 
int ledPin=12;

void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(sensorPin,INPUT);
}

void loop()
{
  if(0==digitalRead(sensorPin))
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}