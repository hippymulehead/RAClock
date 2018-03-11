#define RAClock_h
#ifdef RAClock_h

/*
(C) 2018 Mike Romans of Romans Audio

This is a sudo non blocking clock function.  It operates like a sudo timed interut.
You set it up like
RAClock clk(100); // 100 is the number of millis between clock ticks.

Then you attach a callback to run when a tick happens like
clk.attachCallBack(clkCallBackFunction);  normal function with no paramaters.

Inside your loop you call the run function like
clk.run();

you can also use start() stop() and reset() to control the clock;
*/

class RAClock {
    public:
        RAClock(unsigned long duration);
        void attachCallBack(void (*userFunc)(void));
        void start();
        void stop();
        void reset();
        void run();
        int counterValue();
        int getRunning();
        void setDuration(unsigned long duration);
    private:
        unsigned long   m_duration;
        unsigned long   m_nowTime = 0;
        unsigned long   m_lastTime = 0;
        unsigned long   m_startTime = 0;
        unsigned long   m_counter = 0;
        unsigned long   m_lastCounter = 99;
        int             m_running;
        void            (*m_userFunc)(void);
};
#endif
