#include "../incs/Harl.hpp"

Harl::Harl(void) {
	for (size_t i=0; i<FUNC_ARR_SIZE; i++) {
		this->_func[i] = &Harl::undefined_behavior;
	}

	this->_func[hash("DEBUG")] = &Harl::debug;
	this->_func[hash("INFO")] = &Harl::info;
	this->_func[hash("WARNING")] = &Harl::warning;
	this->_func[hash("ERROR")] = &Harl::error;
	return;
}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << '\n';
	std::cout << "Message about debug" << '\n';
	return;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << '\n';
	std::cout << "Message about info" << '\n';
	return;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << '\n';
	std::cout << "Message about warning" << '\n';
	return;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << '\n';
	std::cout << "Message about error" << '\n';
	return;
}

void	Harl::undefined_behavior(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
	return;
}

void	Harl::complain(std::string level) { (this->*_func[hash(level)])(); }

static size_t	ft_pow(size_t base, int power) {
	size_t	ret = 1;

	while (power--) {
		ret = (ret * base) % FUNC_ARR_SIZE;
	}
	return (ret);
}

size_t	hash(const std::string &level) {
	const size_t	PRIME = 31;
	size_t			ret = 0;

	for (size_t i=0; i<level.length(); i++) {
		ret += (level[i] * ft_pow(PRIME, i)) % FUNC_ARR_SIZE;
	}
	return (ret % FUNC_ARR_SIZE);
}