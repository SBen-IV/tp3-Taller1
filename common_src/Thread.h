#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
private:
	std::thread thread;
public:
	Thread();
	Thread(const Thread& otro) = delete;
	Thread& operator=(const Thread& otro) = delete;
	Thread(Thread&& otro);
	Thread& operator=(Thread&& otro);
	void start();
	void join();
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual ~Thread();
};

#endif