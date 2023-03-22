#include "../incs/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name, int grade) throw(std::exception): _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(_name);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException(_name);
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref._name), _grade(ref._grade) {}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		this->~Bureaucrat();
		new (this) Bureaucrat(rhs);
	}
	return (*this);
}

// Getter
std::string			Bureaucrat::getName(void) { return (this->_name); }
const std::string	&Bureaucrat::getName(void) const { return (this->_name); }
int 				Bureaucrat::getGrade(void) const { return (this->_grade); }

// Utils
void Bureaucrat::incGrade(void) throw(std::exception) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException(_name);
	this->_grade--;
}

void Bureaucrat::decGrade(void) throw(std::exception) {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException(_name);
	this->_grade++;
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

// operator overload
std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref) {
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (os);
}