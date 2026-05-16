#define TRIG_PIN 5
#define ECHO_PIN 18


#define LF 12
#define LB 13
#define RF 14
#define RB 27

long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LF, OUTPUT);
   pinMode(LB, OUTPUT);
    pinMode(RF, OUTPUT);
     pinMode(RB, OUTPUT);
}

int get_distance(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

duration = pulseIn(ECHO_PIN, HIGH,30000);
distance = duration * 0.034/2;

return distance;

}
void forward(){
digitalWrite(LF, HIGH);
digitalWrite(RF, HIGH);
digitalWrite(LB, LOW );
digitalWrite(RB, LOW);

}
void stop_robot (){
digitalWrite(LF, LOW);
digitalWrite(RF, LOW);
digitalWrite(LB, LOW );
digitalWrite(RB, LOW);
}
void left(){
digitalWrite(LF, LOW);
digitalWrite(RF, HIGH);
digitalWrite(LB, HIGH );
digitalWrite(RB, LOW);

}
void right(){
digitalWrite(LF, HIGH);
digitalWrite(RF, LOW);
digitalWrite(LB, LOW );
digitalWrite(RB, HIGH);
}

void loop() {
  int d = get_distance();

  if(d>30){
    forward();
  }
  else if(d>15 && d <= 30){
    stop_robot();
    delay(200);
    left();
    delay(500);
  }else{

  stop_robot();
    delay(200);
    right();
    delay(700);

  }

  delay(100);
}
