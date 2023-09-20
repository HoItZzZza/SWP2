#define PIN_LED 7 //PIN_LED를 7로 정의(7핀에 LED 꽂았으니까)
unsigned int toggle; //toggle 변수 선언

//연결된 LED가 깜빡여야함
void setup() {
  pinMode(PIN_LED, OUTPUT); //PIN_LED를 output으로 할거다
  Serial.begin(115200); //serial은 115200으로 초기화함
  while(!Serial){ //이건 뭐지
    ;
  }
  toggle = 0; //처음 한 번 LED켜기
  delay(1000); //1초동안 LED 켜기
  toggle = 1; //toggle 0으로 초기화 == 얘 입장에서는 (1 == 0)
  digitalWrite(PIN_LED, toggle);  //핀에 출력 내보내기

  for(int i = 0; i<5; i++){ //for문 이용 
     toggle = 1; //LOW, HIGH이용해서 할 수도 있긴 함
     digitalWrite(PIN_LED, toggle);
     delay(200); //1초에 5번 깜빡이기
     toggle = 0;
     digitalWrite(PIN_LED, toggle);
     delay(200);
    }
  toggle = 1; //LED끄기
  digitalWrite(PIN_LED, toggle); //상태 그대로 출력
}

void loop() {
;
}
