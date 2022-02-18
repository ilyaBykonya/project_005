#pragma once
#include "GetSomeTextRepository.h"
#include <chrono>
using namespace std::chrono;

class LRUCacheSomeTextRepository: public GetSomeTextRepository
{
private:
    steady_clock::time_point lastRequestTime;
    milliseconds waitingDelay;
    string bufferizeData;

public:
    LRUCacheSomeTextRepository(milliseconds delay);
    virtual const string& getValue(const int& key) override;
};

