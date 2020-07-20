
#define DISTANCE_FORWARD_PIN  A1
#define DISTANCE_RIGHT_PIN  A0
#define DISTANCE_LEFT_PIN  A2
#define TURRET_PIN   A3
#define PROX2_PIN   A4
#define PIR_PIN   A5

/*
- (3x) Sharp distance measuring sensor gp2y0a21yk https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2y0a21yk_e.pdf
- RadioShack PIR sensor
- (2x) proxdots <http://www.bittybot.com/index.php?pageId=ProxDot>
*/
void sensors_initialize(){
    pinMode(TURRET_PIN, OUTPUT);
    digitalWrite(TURRET_PIN,LOW);
    pinMode(PROX2_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
}

int forward_distance(){
    int sensorValue = analogRead(DISTANCE_FORWARD_PIN);
    return sensorValue;
}

int right_distance(){
    int sensorValue = analogRead(DISTANCE_RIGHT_PIN);
    return sensorValue;
}

int left_distance(){
    int sensorValue = analogRead(DISTANCE_LEFT_PIN);
    return sensorValue;
}

int PIR(){
    int sensorVal = digitalRead(PIR_PIN);
    return sensorVal;
}

int prox1(){
    int sensorVal = digitalRead(TURRET_PIN);
    return sensorVal;
}

int prox2(){
    int sensorVal = digitalRead(PROX2_PIN);
    return sensorVal;
}

void FireOne(){
  digitalWrite(TURRET_PIN,HIGH);
  delay(25);//20 and lower occassionally missfires
  digitalWrite(TURRET_PIN,LOW);
}

