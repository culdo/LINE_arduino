#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_3); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */
MeLightSensor lightSensor(PORT_6);
int val, d, val_now, val2 = 0;
char recv_char;

MeDCMotor motor3(M1);
MeDCMotor motor4(M2);
uint8_t motorSpeed = 200;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
if (Serial.available()>0) {
  recv_char = Serial.read();
  if (recv_char=='1')
  {
    motor3.run(-motorSpeed);
    motor4.run(motorSpeed);
  }else if (recv_char=='2')
  {
    motor3.run(motorSpeed);
    motor4.run(-motorSpeed);
  }else if (recv_char=='3')
  {
    motor3.run(motorSpeed*0.7);
    motor4.run(motorSpeed*0.7);
  }else if (recv_char=='4')
  {
    motor3.run(-motorSpeed*0.7);
    motor4.run(-motorSpeed*0.7);
  }else if (recv_char=='5')
  {
    motor3.stop();
    motor4.stop();
  }
}
     
  val_now=ultraSensor.distanceCm();
  d=val-val_now;
  if(d<-10||d>10)
  {
    val = val_now;
    Serial.print("物體距離車子");
    Serial.print(val);
    Serial.println("公分");
    delay(100); /* the minimal measure interval is 100 milliseconds */
  }
  
  val_now=lightSensor.read();;
  d=val2-val_now;
  if(d<-20||d>20)
  {
    val2 = val_now;
    Serial.print("周圍亮度為");
    Serial.println(val2);
    delay(100); /* the minimal measure interval is 100 milliseconds */
  }
}

