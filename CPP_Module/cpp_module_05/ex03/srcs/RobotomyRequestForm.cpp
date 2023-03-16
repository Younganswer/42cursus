#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target(std::string()) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Getter
std::string			RobotomyRequestForm::getTarget(void) { return (this->_target); }
const std::string	&RobotomyRequestForm::getTarget(void) const { return (this->_target); }

// Utils
void				RobotomyRequestForm::execute(const Bureaucrat &ref) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	}
	std::cout << ref.getName() << " robotomizes " << this->getTarget() << '\n';
	std::cout << "Drilling noises" << '\n';
	srand(time(NULL));
	if (rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully" << '\n';
	} else {
		std::cout << this->getTarget() << " fail to have been robotomized" << '\n';
	}
}