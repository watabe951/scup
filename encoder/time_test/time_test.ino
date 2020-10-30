unsigned long ts = 1000; //[ms]

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long tic, toc;
  tic = micros();

  ///////////処理//////////////
  Serial.println(tic);
  ///////////ここまで/////////////
  
  toc = micros();
  delay(ts - (toc - tic) * 1e-3);

}
