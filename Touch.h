class Touch {
private:
  byte readPin;

public:
  Touch(byte readPin)
    : readPin(readPin) {
    pinMode(readPin, INPUT);
  }

  bool isTouching() {
    return digitalRead(readPin);
  }
};
