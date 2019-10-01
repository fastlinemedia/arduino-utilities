#ifndef Led_h
#define Led_h

class Led {
  public:
    Led(int pin);
    void on();
    void off();
  private:
    int _pin;
};

#endif
