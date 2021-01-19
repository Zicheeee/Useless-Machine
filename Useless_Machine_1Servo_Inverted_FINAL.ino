#include <Servo.h>
Servo armservo; 

int switchpin = 4;
int armpin = 13;
int down = 160;
int up = 10;

int ranAction = 0;
int action = 1;
int nextPress = 0;
int lastPress = 0;
bool willCheck = false;
bool checking = false;

int pos = 0;

void setup() {
pinMode(switchpin,INPUT);
pinMode(2,OUTPUT);

armservo.attach(armpin);

// Servo Default Starting Position

armservo.write(down);
}

void loop() {

// Action Selection starting with 1

  if (digitalRead(switchpin) == LOW && checking == false)
  {
    willCheck = true;
    if(action == 0)
    {
      ranAction = random(1,5);
      if(ranAction > 1)
      {
        action = ranAction+2;
      }
      else
      {
        action = ranAction;
      }
    }
    
    if (action == 1) {
      action1();
      action = 2;
    }
    else if (action == 2) {
      action2();
      action = 3;
    }
    else if (action == 3) {
      action3();
      action = 0;
    }
    else if (action == 4) {
      action4();
      action = 0;
    }
    else if (action == 5) {
      action5();
      action = 0;
    }
    else if (action == 6) {
      action6();
      action = 0;
    }
    else if (action == 7) {
      action7();
      action = 0;
    }
    lastPress = millis();
    nextPress = millis() + random(0,3000);
  }
  else
  {
    if(millis() > (nextPress) && willCheck)
    {
      if(random(3)==0)
      {
        checking = true;
        checkingAction();
      }
      willCheck = false;
      checking = false;
    }
  }
}

void checkingAction()
{
  bool hasPressed = false;
  armservo.write(70);
  for(int i = 0; i < 1500; i +=100)
  {
    if (digitalRead(switchpin) == LOW)
    {
      armservo.write(up);
      delay(100); 
      armservo.write(down);
      i = 1500;
      hasPressed = true;
      break;
    }
    delay(100);
  }
  if(hasPressed == false)
  {
    for(pos = 70; pos < down; pos +=1)
    {
      if (digitalRead(switchpin) == LOW)
      {
        delay(50);
        armservo.write(0);
        delay(250);
      }
      armservo.write(pos);
      delay(30);
    }
  }
  //armservo.write(down);
  delay(100);
  armservo.write(down);
  delay(250);
}

//The Following are actions that are chosen chronologically

void action1() {
  armservo.write(up);
  delay(250); 
  armservo.write(down);
  delay(250);
}

void action2() {
  armservo.write(up);
  delay(500);
  armservo.write(down);
  delay(250);
}

void action3() {
  armservo.write(up);
  delay(1000);
  armservo.write(down);
  delay(250);
}

void action4() {
  armservo.write(down);
  delay(500);
for(pos = down; pos > 40; pos -=1)
  {
    armservo.write(pos);
    delay(30);
  }
  delay(200);
  armservo.write(up);
  delay(1000);
  armservo.write(down);
  delay(250);
}

void action5() {
  armservo.write(up);
  delay(250); 
  armservo.write(down);
  delay(250);
}

void action6() {
  armservo.write(120);
  delay(500);
  armservo.write(down);
  delay(100);
  armservo.write(120);
  delay(500);
  armservo.write(down);
  delay(100);
  armservo.write(120);
  delay(500);
  armservo.write(down);
  delay(100);
  armservo.write(120);
  delay(500);
  armservo.write(down);
  delay(100);
  armservo.write(up);
  delay(250);
  armservo.write(down);
  delay(250);
}

void action7() {
for(pos = down; pos > up; pos -=2)
  {
    armservo.write(pos);
    delay(30);
  }
  armservo.write(up);
for(pos = up; pos < down; pos +=2)
  {
    armservo.write(pos);
    delay(30);
  }
  armservo.write(down);
  delay(250);
}
