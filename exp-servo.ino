#include <Servo.h>
#define REFRESH_INTERVAL   2000 //20000 
#define AVG_READS 5

#define POT1 A0
#define POT2 A1
#define POT3 10
#define POT4 9
#define S1 2
#define S2 1
#define S3 0

int r1 , r2, r3, r4;
int v1,v2,v3,v4;
int pv1,pv2,pv3,pv4;

Servo s1, s2, s3;

void setup() {
  pinMode(POT1, INPUT);
  pinMode(POT2, INPUT);
  pinMode(POT3, INPUT);
  pinMode(POT4, INPUT);
  s1.attach(S1);
  s2.attach(S2);
  s3.attach(S3);
  v1 = v2 = v3 = v4 = MIN_PULSE_WIDTH;
  pv1 = pv2 = pv3 = pv4 = MIN_PULSE_WIDTH;
  
}
int read(int pin,int previous)
{
  int sum =0;
  for(int i=0;i<AVG_READS;i++)
  {
    sum+=analogRead(pin);
  }
  return (previous + sum/AVG_READS)/2;
}
int sign(int value){
  return (value>0)-(value<0); 
}

void loop() {
  
  //if(r1>MAX_PULSE_WIDTH) v=-1;
  //if(r1<MIN_PULSE_WIDTH) v=+1;
  //r1+=v;
 
  r1 = read(POT1,r1);
  r2 = read(POT2,r2);
  r3 = read(POT3,r3);
  r4 = read(POT4,r4);
  
  v1=map(r1,0,1023,MIN_PULSE_WIDTH,MAX_PULSE_WIDTH);
  v2=map(r2,0,1023,MIN_PULSE_WIDTH,MAX_PULSE_WIDTH);
  if(r4>500){
    v3=map(1023-r3,0,1023,MIN_PULSE_WIDTH,MAX_PULSE_WIDTH);
  }else{
    v3=map(r2-(r3-1023),0,1023,MIN_PULSE_WIDTH,MAX_PULSE_WIDTH);
  }
  

  //pv1 += sign( v1 - pv1);
  //pv2 += sign( v2 - pv2);
  //pv3 += sign( v3 - pv3);
  
  //delay(0);
  s1.write(v1);
  s2.write(v2);
  s3.write(v3);
 
  //Serial.print(r1);
  //Serial.print(',');
  //Serial.print(r2);
  //Serial.print(',');
  //Serial.print(r3);
  //Serial.print(',');
  //Serial.print(r4);
  //Serial.println();
}

