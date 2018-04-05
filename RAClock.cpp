#include <RAClock.h>
#include <Arduino.h>

RAClock::RAClock(unsigned long duration) {
    m_duration = duration;
}

void RAClock::attachCallBack(void (*userFunc)(void)) {
    m_userFunc = userFunc;
}

void RAClock::start() {
    m_startTime = millis();
    m_running = 1;
}

void RAClock::stop() {
    m_startTime = 0;
    m_running = 0;
}

void RAClock::reset() {
    m_startTime = millis();
    m_counter = 0;
}

void RAClock::setDuration(unsigned long duration) {
    m_duration = duration;
}

void RAClock::run() {
    m_nowTime = (millis() - m_startTime);
	if (m_nowTime >= (m_lastTime + m_duration)) {
		m_counter++;
		m_lastTime = m_lastTime + m_duration;
        m_userFunc();
	}
	if (m_counter != m_lastCounter) {
		m_lastCounter = m_counter;
	}
}

unsigned long RAClock::counterValue() {
    return m_counter;
}

int RAClock::getRunning() {
    return m_running;
}
