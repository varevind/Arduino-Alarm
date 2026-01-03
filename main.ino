const int trig = 2, echo = 3;
float duration, distance;
int threshold = 10;

const int led = 4;

const int buzz = 5;
const int freq = 600; // Buzzer frequency in Hz

bool led_state = false, buzz_state = true;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);

  duration = pulseIn(echo, HIGH);
  distance = (duration * .0343); // .0343 is sound's speed

  if (distance < threshold)
  {
    for (int i = 0; i < 30; i++)
    {
      if (led_state)
        digitalWrite(led, HIGH);
      else
        digitalWrite(led, LOW);

      if (buzz_state)
        tone(buzz, freq);
      else
        noTone(buzz);

      delay(1000);

      led_state = !led_state;
      buzz_state = !buzz_state;
    }
  }
}