
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define LED 13


unsigned char carSpeed = 10;
bool state = LOW;
int getstr;

void left_forward() {
  
  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,LOW);
}

void left_backward() {
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH); 

  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,LOW);
}

void right_forward() {
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,HIGH); 
}

void right_backward() {
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void forward(){ 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void back(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void left(){
  
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH); 


  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,HIGH); 
}


void right(){
  digitalWrite(IN1,HIGH); 
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void stop_e(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}


void stateChange(){
  state = !state;
  digitalWrite(LED, state);
  Serial.println("Light");  
}



void setup() {
    
    Serial.begin(9600);
    pinMode(LED, OUTPUT); 
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);
    pinMode(3,INPUT);
    pinMode(4,INPUT);
  
    
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
}

void loop() { 

  int val1 = digitalRead(3);
  int val2 = digitalRead(4);

  getstr = (val2*2) + (val1*1);

//  forward();
//  delay(3000);
//  stop_e();



/*
  stop_e();
  forward();
  delay(3000);
  stop_e();
  left();
  delay(3000);
  stop_e();
  right();
  delay(3000);
  stop_e();
 */

  forward();
  delay(2000);

  right();
  delay(500);

  stop_e();
  delay(1000);

  forward();
  delay(2000);

  left();
  delay(500);

  forward();
  delay(2000);

  right();
  delay(500);
  /*
  //getstr = Serial.read();
  switch(getstr){
    case 0: forward(); break;
    case 1: back();   break;
    case 2: left();   break;
    case 3: stop();  break;
    case 4: stop();   break;
    case 5: stateChange(); break;
    default:  break;
  }
  */
}




