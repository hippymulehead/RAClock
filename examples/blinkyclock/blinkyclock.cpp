#include <Arduino.h>
#include <RAClock.h>

RAClock clk(100);
int state = 0;

void clkRun() {
    state = !state;
    digitalWrite(13,state);
}

void setup() {
    clk.attachCallBack(clkRun);
    pinMode(13, OUTPUT);
}

void loop() {
    clk.run();
}
