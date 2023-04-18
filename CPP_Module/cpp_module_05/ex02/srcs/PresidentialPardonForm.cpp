#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target(std::string()) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Getter
const std::string	&PresidentialPardonForm::getTarget(void) const { return (this->_target); }

// Utils
void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException(this->getName());
	}
	std::cout << this->getTarget() << " has been pardoned by " << bureaucrat.getName() << '\n';
}