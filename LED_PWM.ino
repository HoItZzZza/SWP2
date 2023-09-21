/*
  Fade
  
  AnalogWrite()는 PWM함수를 사용하기때메 PWM 지원 핀을 사용해야한다
  PWM핀은 ~3, ~5, ~6, ~9, ~10, ~11핀을 이용한다.
*/

int led = 9;         // 9번 PWM 핀에 연결된 LED
int brightness = 0;  // LED가 얼마나 빛날건지
int fadeAmount = 5;  // LED 빛이 얼마나 사라질지

void setup() {  // 한 번만 실행
  pinMode(led, OUTPUT); // 핀9가 아웃풋이라고 선언
}

void loop() { // 루프문 계속 실행
  analogWrite(led, brightness); // LED가 계속 빛나게 루프문 안에 

  brightness = brightness + fadeAmount; // 루프문 안에서 LED 빛 세기가 계속 변하게

  if (brightness <= 0 || brightness >= 255) { // LED 빛 세기가 커졌다가 작아졌다가 반복
    fadeAmount = -fadeAmount;
  }
  delay(30); // N밀리세컨 이 효과 기다리기
}
