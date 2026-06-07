int volt=9;
int current=10;
int voltpin=2;
int curpin=3;
volatile bool flag=false;
volatile unsigned long vtime=0;
volatile unsigned long itime=0;
int phaseshift=4;

const byte sinetable[32]={128, 153, 177, 199, 218, 234, 246, 253, 255, 253, 246, 234, 218, 199, 177, 153, 128, 103,  79,  57,  38,  22,  10,   3,   0,   3,  10,  22,  38,  57,  79, 103};
void volttime(){
  if(vtime==0){
  vtime=micros();
  }
}
void currtime(){
  if((vtime!=0)&&(itime==0)){
  itime=micros();
  flag=true;
  }
}
void setup(){
  pinMode(volt,OUTPUT);
  pinMode(current,OUTPUT);
  pinMode(voltpin,INPUT);
  pinMode(curpin,INPUT);
  attachInterrupt(0,volttime,RISING);
  attachInterrupt(1,currtime,RISING);
  Serial.begin(115200);
  Serial.println("Initiating the power grid");


}
void loop(){
  for (int i=0;i<32;i++){
    analogWrite(volt,sinetable[i]);
    byte time=(i+32-phaseshift)%32;
    analogWrite(current,sinetable[time]);
    delayMicroseconds(625);
     /* Serial.print(analogRead(A0));
Serial.print(","); 
Serial.println(analogRead(A1));*/
    
  }
  if(flag){
     noInterrupts();
    unsigned long v = vtime;
    unsigned long i = itime;
    vtime=0;
    itime=0;
    flag = false;
    interrupts();
    long diff;
    if(v>i){
      diff=v-i;
    }
    else{
      diff=i-v;
    }
   
      if((diff<10000)&&(diff>0)){
      float shift=(diff*3.14)/10000;
      float pf=cos(shift);
      Serial.print("shift(in radians): ");
      Serial.println(shift);
      Serial.print("pf is: ");
      Serial.println(pf);
      delay(1000);
      vtime = 0;
      itime = 0;
      flag = false;

    }


  }
  
  
}

