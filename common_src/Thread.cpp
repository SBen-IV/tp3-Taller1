#include "Thread.h"

Thread::Thread() {}

Thread::Thread(Thread&& otro) {
	this->thread = std::move(otro.thread);
}

Thread& Thread::operator=(Thread&& otro) {
	this->thread = std::move(otro.thread);

	return *this;
}

void Thread::start() {
	this->thread = std::thread(&Thread::run, this);
}

void Thread::join() {
	this->thread.join();
}

Thread::~Thread() {}