#define N_SEG 8
unsigned char segment_pin_num[] = {8, 9, 2, 3, 4, 5, 6, 7};

void setup()
{
  unsigned char i;
  for(i = 0; i < N_SEG; i++)
    pinMode(segment_pin_num[i], OUTPUT);
  set_display(0x00);
  
  Serial.begin(9600);
}

void loop()
{
  unsigned char val;
  if(Serial.available() > 0)
  {
    val = Serial.read();
    set_display(val);
  }
  delay(100);
}

void set_display(unsigned char val)
{
  unsigned char i;
  for(i = 0; i < N_SEG; i++)
  {
    digitalWrite(segment_pin_num[i], (val & 0x01)) ;
    val >>= 1;
  }
}
