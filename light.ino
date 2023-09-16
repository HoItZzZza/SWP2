#define PIN_LED 13 //PIN_LED를 13으로 정의
unsigned int count, toggle; //count, toggle 변수 선언
                            //toggle : 한 번 누르면 기능이 on되고 한 번 더 누르면 기능이 off
//"L"이 깜빡거려야 함
void setup() {
  pinMode(PIN_LED, OUTPUT); //PIN_LED를 output으로 할거다
  Serial.begin(115200); //serial은 115200으로 초기화
  while(!Serial){ //이건 뭐지
    ;
  }
  Serial.println("Hello World!"); //처음 한 번만 hello world 출력
  count = toggle = 0; //count, toggle 0으로 초기화
  digitalWrite(PIN_LED, toggle);  //이건 뭐지
}

void loop() { //여기서 계속 반복
  Serial.println(++count);  //count를 1씩 늘리면서 출력
  toggle = toggle_state(toggle);  
  digitalWrite(PIN_LED, toggle); //PIN_LED상태 -- HIGH/LOW
  delay(1000); //대기
}

int toggle_state(int toggle){
  if (toggle==0){
    toggle = 1;
  }else{
    toggle = 0;
  }
  return toggle;
}
