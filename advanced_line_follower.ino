int pwm =150;
int pwmf =70;
int irl2,irl1,irr1,irr2;
int x ;
void setup() {
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(12,INPUT);
pinMode(13,INPUT);
}
void Stop(){
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
  }

void forward(){
  analogWrite(3,0);
  analogWrite(5,pwm);
  analogWrite(6,pwm);
  analogWrite(9,0);  
}
void fake_forward(){
  analogWrite(3,0);
  analogWrite(5,pwmf);
  analogWrite(6,pwmf);
  analogWrite(9,0); 
}
void left(){
  analogWrite(3,0);
  analogWrite(5,pwm);
  analogWrite(6,0);
  analogWrite(9,pwm); 
}
void special_left(){
  analogWrite(3,0);
  analogWrite(5,pwm);
  analogWrite(6,0);
  analogWrite(9,0); 
}
void right(){
  analogWrite(3,pwm);
  analogWrite(5,0);
  analogWrite(6,pwm);
  analogWrite(9,0);  
}
void special_right(){
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,pwm);
  analogWrite(9,0); 
}
void loop(){
 irl2 = digitalRead(10);
 irl1 = digitalRead(11);
 irr1 = digitalRead(12);
 irr2 = digitalRead(13);
 switch(irl2*1000 + irl1*100 + irr1*10 + irr2*1){
  case 0000:
  case 0110:
  case 1001:
  case 1111:
  forward();
  break;
  
  
  case 0001:
  case 0010:
  right();
  break;
  
  case 0100:
  case 1000:
  left();
  break;
  
  case 0101:
  case 1010:
  fake_forward();
  break;

  case 0011:
  case 0111:
  case 1011:
  while(1){
  special_right();
  irl2 = digitalRead(10);
  irl1 = digitalRead(11);
  if (irl2==1 || irl1==1)
  {
    Stop();
    break;
    }
  }
   break ;

  case 1100:
  case 1101:
  case 1110:
  while(1){
  special_left();
  irr1 = digitalRead(12);
  irr2 = digitalRead(13);
  if (irr2==1 || irr1==1)
  {
    Stop();
    break;
    }
   break ;
 }
}
}
