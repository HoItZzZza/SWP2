// 핀 선언
#define PIN_LED  9  // 9번 핀이 LED를 제어하기 위해 이용
#define PIN_TRIG 12 // 12번 핀이 초음파센서 trigger에 연결, 초음파 센서에 신호를 보내서 초음파 발생 
#define PIN_ECHO 13 // 13번 핀이 초음파센서 echo에 연결, 물체에 부딪혀서 돌아오는 시간 측정

// configurable parameters
#define SND_VEL 346.0     // sound velocity at 24 celsius degree (unit: m/sec)
#define INTERVAL 100      // 초음파 센서를 읽는 간격
#define PULSE_DURATION 10 // ultra-sound Pulse Duration (unit: usec)
#define _DIST_MIN 100.0   // 인식할 수 있는 최소 거리 (mm)
#define _DIST_MAX 300.0   // 인식할 수 있는 최대 거리 (mm)

#define TIMEOUT ((INTERVAL / 2) * 1000.0) // echo신호 기다리는 최대 대기 시간
#define SCALE (0.001 * 0.5 * SND_VEL) // echo신호 지속 시간을 거리로 변환

unsigned long last_sampling_time; // 0 이상의 정수 값을 나타내기 위해 사용. 
byte brightness = 0;

void setup() { //PIN초기설정
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);  
  digitalWrite(PIN_TRIG, LOW);
  Serial.begin(57600);
}

void loop() {
  float distance; // distance float 변수 선언

  if (millis() < (last_sampling_time + INTERVAL)) // milis() : 프로그램이 시작된 이후 밀리초 단위의 시간 반환
    return; 
    // 그래서 이 코드는 last_sampling_time으로 최근 시간을 받아오고 interval 안에 loop문이 실행됐다묜
    // 센서값을 읽어오고 interval 안에 loop문이 실행이 안됐으면 센서값을 안읽어오는겨
    // (그니까 센서값을 읽어온다는게 아래의 코드가 실행된다는 뜻임!!)
    
  distance = USS_measure(PIN_TRIG, PIN_ECHO); // 초음파센서 trigger, 초음파센서 echo값 받아오기

// **과제는 이 부분을 수정해야할듯
  if (100 < distance && distance <= 200) {  
      brightness = map(distance, 100, 200, 255, 0);
      analogWrite(PIN_LED, brightness);
  } else if (200 <= distance && distance < 300) {
      brightness = map(distance, 200, 300, 0, 255);
      analogWrite(PIN_LED, brightness);
  } else { 
      brightness = 255;
  }

  // output the distance to the serial port
  Serial.print("Min:");        Serial.print(_DIST_MIN);
  Serial.print(",distance:");  Serial.print(distance);
  Serial.print(",Max:");       Serial.print(_DIST_MAX);
  Serial.println("");
  
  // do something here
  delay(25); // loop의 각 반복에서 25밀리초 동안 일시적으로 멈추도록 함, CPU를 과도하게 쓰는 것을 방지하기 위함
  
  last_sampling_time += INTERVAL; // 가장 최근 시간 업데이트
}

// get a distance reading from USS. return value is in millimeter.
float USS_measure(int TRIG, int ECHO)
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(PULSE_DURATION);
  digitalWrite(TRIG, LOW);
  
  return pulseIn(ECHO, HIGH, TIMEOUT) * SCALE; // unit: mm
}
