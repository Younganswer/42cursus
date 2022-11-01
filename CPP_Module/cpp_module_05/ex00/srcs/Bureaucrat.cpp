/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:05:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/01 13:40:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("younhwan"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) throw(std::exception): _name(std::string(name.c_str())), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(_name);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(_name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(std::string(ref.getName().c_str())), _grade(ref.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref) {
	if (this != &ref) {
		this->_grade = ref._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string	&Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::incGrade(void) throw(std::exception) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException(_name);
	else
		this->_grade--;
}

void Bureaucrat::decGrade(void) throw(std::exception) {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException(_name);
	else
		this->_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref) {
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << '\n';
	return (os);
}