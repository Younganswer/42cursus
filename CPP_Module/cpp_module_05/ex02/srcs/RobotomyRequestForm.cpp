/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:38:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:42:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45), _target(std::string()) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("RobotomyRequestForm", 72, 45), _target(std::string(target.c_str())) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref): Form(ref), _target(std::string(ref.getTarget().c_str())) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
		this->_target = std::string(rhs.getTarget().c_str());
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Getter
const std::string	&RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

// Utils
void				RobotomyRequestForm::execute(const Bureaucrat &ref) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw Form::FormNotSignedException();
	} else if (ref.getGrade() > this->getGradeToExecute()) {
		throw Form::GradeTooLowException();
	} else {
		std::cout << "Drilling noises" << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 0) {
			std::cout << this->getTarget() << " has been robotomized successfully" << '\n';
		} else {
			std::cout << this->getTarget() << " fail to have been robotomized" << '\n';
		}
	}
}