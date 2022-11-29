/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:05:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/29 16:39:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"
#include "../incs/ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat(void): _name("younhwan"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name, int grade) throw(std::exception): _name(std::string(name.c_str())), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(_name);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(_name);
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(std::string(ref.getName().c_str())), _grade(ref.getGrade()) {}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref) {
	if (this != &ref) {
		this->_grade = ref._grade;
	}
	return (*this);
}

// Getter
std::string			Bureaucrat::getName(void) { return (this->_name); }
const std::string	&Bureaucrat::getName(void) const { return (this->_name); }
int Bureaucrat::getGrade(void) const { return (this->_grade); }

// Utils
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

void	Bureaucrat::signForm(Form &ref) throw(std::exception) {
	try {
		ref.beSigned(*this);
		std::cout << this->_name << " signs " << ref.getName() << '\n';
	} catch (std::exception &e) {
		throw Bureaucrat::GradeTooLowException(this->_name + " cannot sign " + ref.getName() + " because " + this->_name);
	} catch (...) {
		throw "Error: Unknown Error";
	}
}

void	Bureaucrat::executeForm(Form const &form) throw(std::exception) {
	try {
		std::cout << this->_name << " executes " << form.getName() << '\n';
		form.execute(*this);
	} catch (Form::FormNotSignedException &e) {
		throw e;
	} catch (ShrubberyCreationForm::FileOpenException &e) {
		throw e;
	} catch (std::exception &e) {
		throw Bureaucrat::GradeTooLowException(this->_name + " cannot execute " + form.getName() + " because " + this->_name);
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
}

// Exception: GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(void): _msg("Grade is too high") {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name) { this->_msg = std::string(name.c_str()) + "\'s grade is too high"; }
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
const char	*Bureaucrat::GradeTooHighException::what() const throw() { return (this->_msg.c_str()); }

// Exception: GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(void): _msg("Grade is too low") {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name) { this->_msg = std::string(name.c_str()) + "\'s grade is too low"; }
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
const char	*Bureaucrat::GradeTooLowException::what() const throw() { return (this->_msg.c_str()); }

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &ref) {
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << '\n';
	return (os);
}