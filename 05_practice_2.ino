// 05_practice_2.ino  (실습 3: GPIO를 통한 LED 제어)
// 회로: 5V -- [220Ω] -- LED(애노드+) → LED(캐소드-) -- Pin 7
// 참고: active-low (LOW일 때 켜짐, HIGH일 때 꺼짐)

#define LED_PIN 7

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); // 시작은 꺼짐(Active-Low이라 HIGH=OFF)
}

void loop() {
  // 1) 처음 1초 동안 LED 켜기
  digitalWrite(LED_PIN, LOW);   // ON
  delay(1000);                  // 1초

  // 2) 다음 1초 동안 5회 깜빡이기
  // 1초 / 5회 = 200ms 주기(ON 100ms + OFF 100ms)
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN, LOW);   // ON
    delay(100);
    digitalWrite(LED_PIN, HIGH);  // OFF
    delay(100);
  }

  // 3) LED 끄고 무한루프 종료
  digitalWrite(LED_PIN, HIGH); // OFF
  while (1) { /* infinite loop */ }
}
