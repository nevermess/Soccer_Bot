#include<Servo.h>
Servo striker;
Servo servoup;
Servo sweeper;

char incoming;

static int pos;

void go_forward()
{
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void go_back()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);

}

void left()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void right()
{
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}

void sweepr()
{
  pos -= 15;
  sweeper.write(pos);
}
void sweepl()
{
  pos += 15;
  sweeper.write(pos);
}
void strike()
{
  striker.write(45); //for goal
  delay(100);
  striker.write(0); //initial pos
}
void setup() {
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  striker.attach(9);
  servoup.attach(6);
  sweeper.attach(7);
  striker.write(0);  //initial position
  servoup.write(0);
  pos = 90;
  sweeper.write(90);
  Serial.print("Started");
}

void loop() {
 /* while (1)
  { for (pos = 0; pos < 180; pos++)
    { striker.write(pos);
delay(10);
    }
    for(pos =180;pos>0;pos--){
      striker.write(pos);
      delay(10);
      }
  }*/
  if (Serial.available() > 0)
 
{
  incoming = Serial.read();
  digitalWrite(13, HIGH);
  
}
delay(50);
digitalWrite(13,LOW);
switch (incoming)
{
case 'u': //forward
  go_forward();
  Serial.print("U");
  break;
case 'b': //backward
  go_back();
  Serial.print("B");
  break;
case 'l':
  right();
  Serial.print("L");
  break;
case 'r':
  left();
  Serial.print("R");
  break;
case 'a':
  sweepr();
  break;
case 'c':
  sweepl();
  break;
case 'd':
  strike();
  Serial.print("D");
  break;
case 'M':
  servoup.write(100);//down position
  delay(100);
  break;
case 'm':
  servoup.write(0);//up position
  delay(100);
  break;
default:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  break;
}
}
