#include <IRremote.h>

class Remote {
private:
  byte IR_RECEIVE_PIN;

public:
  Remote(byte IR_RECEIVE_PIN)
    : IR_RECEIVE_PIN(IR_RECEIVE_PIN) {
  }

  void begin() {  //must call in setup()
    IrReceiver.begin(IR_RECEIVE_PIN);
  }

  bool hasSignal() {
    return IrReceiver.decode();
  }

  char decodeSignal() {
    IrReceiver.resume();
    uint32_t signal = IrReceiver.decodedIRData.decodedRawData;
    if (signal == 3125149440) return 'p';       // power
    else if (signal == 3091726080) return 'm';  // menu
    else if (signal == 3141861120) return 't';  // test
    else if (signal == 3158572800) return 'r';  // return
    else if (signal == 3927310080) return 'p';  // play
    else if (signal == 3208707840) return '+';
    else if (signal == 3860463360) return '-';
    else if (signal == 4161273600) return 'b';  // before
    else if (signal == 4127850240) return 'a';  // after
    else if (signal == 3910598400) return '0';
    else if (signal == 4077715200) return '1';
    else if (signal == 3877175040) return '2';
    else if (signal == 2707357440) return '3';
    else if (signal == 4144561920) return '4';
    else if (signal == 3810328320) return '5';
    else if (signal == 2774204160) return '6';
    else if (signal == 3175284480) return '7';
    else if (signal == 2907897600) return '8';
    else if (signal == 3041591040) return '9';
    else if (signal == 4061003520) return 'c';
    else return '?';  // invalid
  }
};
