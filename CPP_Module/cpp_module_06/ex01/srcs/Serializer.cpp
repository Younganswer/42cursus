#include "../incs/Serializer.hpp"
#include <iostream>

_Data::_Data(void) {}
_Data::~_Data(void) {}
_Data::_Data(const std::string &s1, const std::string &s2, int n): s1(s1), s2(s2), n(n) {}

Serializer::Serializer(void) {}
Serializer::~Serializer(void) {}
Serializer::Serializer(const Serializer &ref) { (void) ref; }
Serializer	&Serializer::operator=(const Serializer &rhs) {
	(void) rhs;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deSerialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}