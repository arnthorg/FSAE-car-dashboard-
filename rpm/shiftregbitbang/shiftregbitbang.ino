#define Data 3
#define CP 4
bool toggleData = 0;
void setup() {
  pinMode(Data, OUTPUT);
  pinMode(CP, OUTPUT);
  digitalWrite(CP,0);
  digitalWrite(Data,1);
}

void loop() {
  
  for(int iter = 0; iter<8;iter++) {
    digitalWrite(CP,1);
    delay(50);
    digitalWrite(CP,0);
    delay(50);
  }
  digitalWrite(Data,toggleData);
  toggleData = !toggleData;
}
