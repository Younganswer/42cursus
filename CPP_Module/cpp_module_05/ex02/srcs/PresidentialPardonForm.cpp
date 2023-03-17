#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target(std::string()) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Getter
std::string			PresidentialPardonForm::getTarget(void) { return (this->_target); }
const std::string	&PresidentialPardonForm::getTarget(void) const { return (this->_target); }

// Utils
void	PresidentialPardonForm::execute(const Bureaucrat &ref) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException(this->getName());
	}
	std::cout << this->getTarget() << " has been pardoned by " << ref.getName() << '\n';
}