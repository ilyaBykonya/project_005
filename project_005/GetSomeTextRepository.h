#pragma once
#include "IReadRepository.h"
#include <memory>
#include <string>
using namespace std;


struct GetSomeTextRepository: public IReadRepository<int, shared_ptr<string>> {
	virtual shared_ptr<string> getValue(const int& key) override;
};

