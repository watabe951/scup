int wait_time = 10;
int counter = 0;
// double rad_counter = 0;
// boolean direction = 0;
// boolean updown = 0;

void setup()
{
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
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

  //   rad_counter = 3.1415 * counter / 180;
  //   if(0 <= counter && counter <= 180){
  //     digitalWrite(2, HIGH);
  //     digitalWrite(4, LOW);
  //     digitalWrite(7, HIGH);
  //     digitalWrite(8, LOW);
  //     analogWrite(5, 255 * abs(sin(rad_counter)));
  //     analogWrite(6, 255 * abs(sin(rad_counter)));
  //   }else if(180 < counter && counter <= 360){
  //     digitalWrite(2, LOW);
  //     digitalWrite(4, HIGH);
  //     digitalWrite(7, LOW);
  //     digitalWrite(8, HIGH   );
  //     analogWrite(5, 255 * abs(sin(rad_counter)));
  //     analogWrite(6, 255 * abs(sin(rad_counter)));
  //   }

  delay(wait_time);
}

//void forward()
//{
//  digitalWrite(8, HIGH);
//}
//void backward()
//{
//  digitalWrite(8, LOW);
//}
