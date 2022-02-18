#pragma once
#include <condition_variable>
#include <mutex>
#include <string>
#include <queue>
using namespace std;

class AsyncLogger
{
private:
	atomic_bool _finishWorkFlag = false;
	mutable mutex _locker;
	condition_variable _newMessagesAwaiter;
	queue<string> _messagesQueue;

public:
	AsyncLogger() = default;

	void receiveMessage(const string& message);
	void executeLogger(ostream& outStream);
	void notifyFinishWork();
};

