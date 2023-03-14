#include "../incs/Intern.hpp"
#include <iostream>

AForm *(*Intern::_form[Intern::_FUNC_ARR_SIZE])(const std::string &target) = {&Intern::cannotMakeForm, };

Intern::Intern(void) {
	Intern::_form[Intern::hash("presidential pardon")] = &Intern::makePresidentialPardonForm;
	Intern::_form[Intern::hash("robotomy request")] = &Intern::makeRobotomyRequestForm;
	Intern::_form[Intern::hash("shrubbery creation")] = &Intern::makeShrubberyCreationForm;
}
Intern::Intern(const Intern &ref) {	(void) ref; }
Intern	&Intern::operator=(const Intern &rhs) { (void) rhs; return (*this); }
Intern::~Intern(void) {}

size_t	Intern::hash(const std::string &str) {
	const size_t	prime = 31;
	size_t			ret = 0;

	for (size_t i=0; i<str.length(); i++) {
		ret = (ret + (str[i] * ft_pow(prime, i))) % Intern::_FUNC_ARR_SIZE;
	}
	return (ret);
}

size_t	Intern::ft_pow(int base, int exp) {
	size_t	ret = 1;

	while (exp--) {
		ret = (ret * base) % Intern::_FUNC_ARR_SIZE;
	}
	return (ret);
}

AForm	*Intern::makePresidentialPardonForm(const std::string &target) {
	std::cout << "Intern creates presidential pardon form\n";
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(const std::string &target) {
	std::cout << "Intern creates robotomy request form\n";
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyCreationForm(const std::string &target) {
	std::cout << "Intern creates shrubbery creation form\n";
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::cannotMakeForm(const std::string &target) {
	std::cout << "Intern can't create " << target << '\n';
	return (NULL);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) {
	return (Intern::_form[Intern::hash(name)](target));
}