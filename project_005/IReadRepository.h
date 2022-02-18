#pragma once

template<typename Key, typename Value>
struct IReadRepository {
	virtual Value getValue(const Key& key) = 0;
};

template<typename Value>
struct IReadRepository<void, Value> {
	virtual Value getValue() = 0;
};
