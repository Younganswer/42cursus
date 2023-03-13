#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target(std::string()) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref): AForm(ref), _target(ref._target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(rhs);
	}
	return (*this);
}

// Getter
std::string			PresidentialPardonForm::getTarget(void) { return (this->_target); }
const std::string	&PresidentialPardonForm::getTarget(void) const { return (this->_target); }

// Utils
void	PresidentialPardonForm::execute(const Bureaucrat &ref) const throw(std::exception) {
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException(this->getName());
	std::cout << this->getTarget() << " has been pardoned by " << ref.getName() << '\n';
}