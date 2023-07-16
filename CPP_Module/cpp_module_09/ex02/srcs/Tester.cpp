#include "../incs/Tester.hpp"

Tester::Tester(void) {}
Tester::~Tester(void) {}
Tester::Tester(const Tester &other) { (void) other; }
Tester	&Tester::operator=(const Tester &other) { (void) other; return (*this); }

const char	*Tester::InvalidTypeException::what(void) const throw() { return ("Tester: Invalid type"); }