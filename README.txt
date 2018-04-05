RAClock

This is a sudo non blocking clock function.  It operates like a sudo timed interrupt.
You set it up like
RAClock clk(100); // 100 is the number of millis() between clock ticks.

Then you attach a callback to run when a tick happens like
clk.attachCallBack(clkCallBackFunction);  normal function with no params.

Inside your loop you call the run function like
clk.run();

You can also use start() stop() and reset() to control the clock and embedded counter;

The clock also has a counter built in and you can access the unsigned long value by calling...
clk.counterValue();
