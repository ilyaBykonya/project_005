#include "GetSomeTextRepository.h"

shared_ptr<string> GetSomeTextRepository::getValue(const int& key) {
	return to_string(key);
}
