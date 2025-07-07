#define N_SEG 8
#define N_NUM 9

// Segments: A, B, C, D, E, F, G, DP
const unsigned char display_pin_num[] = {0, 1, 2, 3, 4, 5, 6, 7};

/*
0  |  A, B, C, D, E, F     |  0011-1111  |  0x3F
1  |  B, C                 |  0000-0110  |  0x06          
2  |  A, B, D, E, G        |  0101-1011  |  0x5B
3  |  A, B, C, D, G        |  0100-1111  |  0x4F
4  |  B, C, F, G           |  0110-0110  |  0x66
5  |  A, C, D, F, G        |  0110-1101  |  0x6D
6  |  A, C, D, E, F, G     |  0111-1101  |  0x7D
7  |  A, B, C              |  0000-0111  |  0x07
8  |  A, B, C, D, E, F, G  |  0111-1111  |  0x7F
9  |  A, B, C, F, G        |  0110-0111  |  0x67
*/
unsigned char i;
const unsigned char display_num[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
unsigned char num_idx = 0;

void setup() 
{
  for(i = 0; i < N_SEG; i++)
    pinMode(display_pin_num[i], OUTPUT);
  set_display(0x00);
}

void loop() 
{ 
  set_display(display_num[num_idx]);
  if(++num_idx > N_NUM)
    num_idx = 0;
  delay(1000);
}

void set_display(unsigned char val)
{
  for(i = 0; i < N_SEG; i++)
  {
    digitalWrite(display_pin_num[i], (val & 0x01));
    val >>= 1;
  }
}
