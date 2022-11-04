/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:56:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:59:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

Form::Form(void): _name("younhwan"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute) throw(std::exception): _name(std::string(name.c_str())), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException(_name);
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException(_name);
}

Form::Form(const Form &ref): _name(std::string(ref.getName().c_str())), _is_signed(ref.getIsSigned()), _grade_to_sign(ref.getGradeToSign()), _grade_to_execute(ref.getGradeToExecute()) {}

Form	&Form::operator=(const Form &ref) {
	if (this != &ref) {
		this->_is_signed = ref._is_signed;
	}
	return (*this);
}

Form::~Form(void) {}

const std::string	&Form::getName(void) const {
	return (this->_name);
}

bool Form::getIsSigned(void) const {
	return (this->_is_signed);
}

int Form::getGradeToSign(void) const {
	return (this->_grade_to_sign);
}

int Form::getGradeToExecute(void) const {
	return (this->_grade_to_execute);
}

void	Form::beSigned(const Bureaucrat &ref) throw(std::exception) {
	if (this->_grade_to_sign < ref.getGrade())
		throw Form::GradeTooLowException(ref.getName());
	else
		this->_is_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(void): _msg("Grade is too high") {}

Form::GradeTooHighException::GradeTooHighException(const std::string &name) {
	this->_msg = std::string(name.c_str()) + "\'s grade is too high";
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return (this->_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(void): _msg("Grade is too low") {}

Form::GradeTooLowException::GradeTooLowException(const std::string &name) {
	this->_msg = std::string(name.c_str()) + "\'s grade is too low";
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return (this->_msg.c_str());
}

Form::FormNotSignedException::FormNotSignedException(void): _msg("Form is not signed") {}

Form::FormNotSignedException::FormNotSignedException(const std::string &name) {
	this->_msg = std::string(name.c_str()) + " is not signed";
}

Form::FormNotSignedException::~FormNotSignedException(void) throw() {}

const char	*Form::FormNotSignedException::what(void) const throw() {
	return (this->_msg.c_str());
}

std::ostream	&operator<<(std::ostream &os, const Form &ref) {
	os << ref.getName() << "\'s form is " << (ref.getIsSigned() ? "signed" : "unsigned") << " and grade to sign is " << ref.getGradeToSign() << " and grade to execute is " << ref.getGradeToExecute() << '\n';
	return (os);
}