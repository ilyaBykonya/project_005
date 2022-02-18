#include "LRUCacheSomeTextRepository.h"

LRUCacheSomeTextRepository::LRUCacheSomeTextRepository(milliseconds delay)
    :waitingDelay{ delay }
    {
    }

const string& LRUCacheSomeTextRepository::getValue(const int& key) {
    auto currentTime = steady_clock::now();
    if (currentTime - lastRequestTime < waitingDelay)
        return bufferizeData;

    lastRequestTime = currentTime;
    return bufferizeData = GetSomeTextRepository::getValue(key);
}
