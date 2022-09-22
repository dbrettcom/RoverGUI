int buzzer = 2;
int trigPin = A0;   
int echoPin = A1;    

long duration, distance;

// Motor A

int enA = 8;
int in1 = 7;
int in2 = 6;

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() 
{
  if (Serial.available())
  {
    char val = Serial.read();

  if (val == 'F') 
  {
    Serial.println("Forward");
    analogWrite(enA, 200);
    analogWrite(enB, 200);
  
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH); 
  }     

   if (val == 'B')
   {
      Serial.println("Reverse");
      analogWrite(enA, 200);
      analogWrite(enB, 200);

      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
   }

   if (val == 'R')
   {
      Serial.println("Right");
      analogWrite(enA, 200);
      analogWrite(enB, 200);

      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
   }
   
   if (val == 'L')
   {
      Serial.println("Left");
      analogWrite(enA, 200);
      analogWrite(enB, 200);

      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
   }

   if (val == 'V') //Buzzer On
   {
    tone(buzzer, 1000);
   }

   if (val == 'v') //Buzzer Off
   {
    tone(buzzer, 0);
    delay(1000);
    noTone(buzzer);
   }
  
   if (val == 'S')
   {
      Serial.println("Stop");
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
   }
}
}
