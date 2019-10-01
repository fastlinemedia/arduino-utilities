#ifndef Button_h
#define Button_h

class Button {
  public:
    Button(int pin);
    void saveState();
    bool stateChangedHigh();
    bool stateIsHigh();
    bool stateChangedLow();
    bool stateIsLow();
  private:
    int _pin;
    int _state;
    int _prevState;
};

#endif
