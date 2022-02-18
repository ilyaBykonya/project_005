#include "AsyncLogger.h"
#include <iostream>

void AsyncLogger::receiveMessage(const string& message) {
	lock_guard lk{ _locker };
	_messagesQueue.push(message);
	_newMessagesAwaiter.notify_one();
}
void AsyncLogger::executeLogger(ostream& outStream) {
	outStream << "On logger" << std::endl;
	unique_lock<mutex> mutexLocker{ _locker };
	while (_finishWorkFlag == false || _messagesQueue.size() > 0) {
		if (_messagesQueue.size() > 0) {
			outStream << _messagesQueue.front() << std::endl;
			_messagesQueue.pop();
			continue;
		} else {
			_newMessagesAwaiter.wait_until(mutexLocker, chrono::steady_clock::now() + chrono::microseconds(100), [this]() {
				return _messagesQueue.size() > 0;
			});
		}
	}
	_finishWorkFlag = false;//На случай перезапуска
	outStream << "Off logger" << std::endl;
}
void AsyncLogger::notifyFinishWork() {
	_finishWorkFlag = true;
}
