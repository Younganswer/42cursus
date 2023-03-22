#include "../incs/Serialize.hpp"
#include <iostream>

_Data::_Data(void) {}
_Data::_Data(const std::string &s1, const std::string &s2, int n): s1(s1), s2(s2), n(n) {}
_Data::~_Data(void) {}

Serialize::Serialize(void) {}
Serialize::Serialize(const Serialize &src) { (void) src; }
Serialize::~Serialize(void) {}
Serialize	&Serialize::operator=(const Serialize &rhs) {
	(void) rhs;
	return (*this);
}

uintptr_t	Serialize::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serialize::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}