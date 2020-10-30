#define ENC_A 2
#define ENC_B 3
 
volatile byte pos;
volatile int  enc_count;

int wait_time = 10;
int counter = 0;
 
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
 
  attachInterrupt(0, ENC_READ, CHANGE);
  attachInterrupt(1, ENC_READ, CHANGE);
  Serial.begin(38400);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  
}
 
 
void loop() 
{   
  counter++;
  if (counter > 200)
  {
    counter = 0;
  }

  if (counter < 100)
  {
    digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(8, LOW);
  }

  delay(wait_time);
  }
 
 
void ENC_READ() {
  byte cur = (!digitalRead(ENC_B) << 1) + !digitalRead(ENC_A);
  byte old = pos & B00000011;
  byte dir = (pos & B00110000) >> 4;
 
  if (cur == 3) cur = 2;
  else if (cur == 2) cur = 3;
 
  if (cur != old)
  {
    if (dir == 0)
    {
      if (cur == 1 || cur == 3) dir = cur;
    } else {
      if (cur == 0)
      {
        if (dir == 1 && old == 3) enc_count++;
        else if (dir == 3 && old == 1) enc_count--;
        dir = 0;
      }
    }
 
    bool rote = 0;
    if (cur == 3 && old == 0) rote = 0;
    else if (cur == 0 && old == 3) rote = 1;
    else if (cur > old) rote = 1;
 
    pos = (dir << 4) + (old << 2) + cur;
 
    const char vector[2] = {'<', '>'};
    Serial.print(vector[rote]);
    Serial.print(" ");
    Serial.print(enc_count);
    Serial.print(" ");
    Serial.println(pos + (1 << 7), BIN);
    if (cur == 0) Serial.println();
  }


}
