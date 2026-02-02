const int p1Btn = 2;  // Red button Player 1 (left)
const int p2Btn = 3;  // Yellow button Player 2 (right)
const int ledLeftRed = 4;
const int ledLeftBlue = 5;
const int ledGreen = 6;
const int ledRightBlue = 7;
const int ledRightRed = 8;
const int buzzer = 9;

bool gameActive = false;
bool readyToStart = false;

void setup() {
  pinMode(p1Btn, INPUT_PULLUP);
  pinMode(p2Btn, INPUT_PULLUP);
  pinMode(ledLeftRed, OUTPUT); pinMode(ledLeftBlue, OUTPUT); 
  pinMode(ledGreen, OUTPUT); pinMode(ledRightBlue, OUTPUT); 
  pinMode(ledRightRed, OUTPUT); pinMode(buzzer, OUTPUT);
  allLEDsOff();
  delay(1000);
  
  // Wait for BOTH buttons
  waitForBothButtons();
}

void loop() {
  if (gameActive) {
    if (digitalRead(p1Btn) == LOW) { 
      winner(1); 
    }
    else if (digitalRead(p2Btn) == LOW) { 
      winner(2); 
    }
  }
  delay(50);
}

void waitForBothButtons() {
  while(true) {
    if (digitalRead(p1Btn) == LOW && digitalRead(p2Btn) == LOW) {
      readyToStart = true;
      loudBeep(300); loudBeep(300);  // BOTH PRESSED - READY!
      delay(500);
      startCountdown();
      break;
    }
    delay(100);
  }
}

void startCountdown() {
  gameActive = false;
  allLEDsOff();
  
  // BOTH REDS
  digitalWrite(ledLeftRed, HIGH); digitalWrite(ledRightRed, HIGH);
  loudBeep(600); delay(200); allLEDsOff();
  
  // BOTH BLUES  
  digitalWrite(ledLeftBlue, HIGH); digitalWrite(ledRightBlue, HIGH);
  loudBeep(600); delay(200); allLEDsOff();
  
  // GREEN CENTER
  digitalWrite(ledGreen, HIGH);
  loudBeep(600); delay(200); allLEDsOff();
  
  // GO! - ZERO DELAY
  loudBeep(800);
  gameActive = true;  // INSTANT START
}

void winner(int player) {
  gameActive = false;
  allLEDsOff();
  
  if (player == 1) {
    digitalWrite(ledLeftRed, HIGH);
  } else {
    digitalWrite(ledRightRed, HIGH);
  }
  
  for(int i = 0; i < 7; i++) {
    loudBeep(100); delay(100);
  }
  
  delay(2000);
  waitForBothButtons();  // Wait for both again!
}

void loudBeep(int duration) {
  digitalWrite(buzzer, HIGH);
  delay(duration);
  digitalWrite(buzzer, LOW);
}

void allLEDsOff() {
  digitalWrite(ledLeftRed, LOW); digitalWrite(ledLeftBlue, LOW); 
  digitalWrite(ledGreen, LOW); digitalWrite(ledRightBlue, LOW); 
  digitalWrite(ledRightRed, LOW);
}
