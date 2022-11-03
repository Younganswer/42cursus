/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:30:58 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:38:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5), _target(std::string()) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("PresidentialPardonForm", 25, 5), _target(std::string(target.c_str())) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref): Form(ref), _target(std::string(ref.getTarget().c_str())) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
		this->_target = std::string(rhs.getTarget().c_str());
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Getter
const std::string	&PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

// Utils
void				PresidentialPardonForm::execute(const Bureaucrat &ref) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw Form::FormNotSignedException(this->getName());
	}
	if (this->getGradeToExecute() < ref.getGrade()) {
		throw Form::GradeTooLowException(ref.getName());
	}
	else {
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << '\n';
	}
}