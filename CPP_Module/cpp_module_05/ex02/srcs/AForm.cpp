#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void): _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}
AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute) throw(std::exception): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException(_name);
	if (150 < grade_to_sign || 150 < grade_to_execute)
		throw AForm::GradeTooLowException(_name);
}
AForm::AForm(const AForm &ref): _name(ref._name), _is_signed(ref.getIsSigned()), _grade_to_sign(ref._grade_to_sign), _grade_to_execute(ref._grade_to_execute) {}
AForm::~AForm(void) {}

AForm	&AForm::operator=(const AForm &ref) {
	if (this != &ref) {
		this->_is_signed = ref.getIsSigned();
	}
	return (*this);
}

// Getter
std::string			AForm::getName(void) { return (this->_name); }
const std::string	&AForm::getName(void) const { return (this->_name); }
bool 				AForm::getIsSigned(void) const { return (this->_is_signed); }
int 				AForm::getGradeToSign(void) const { return (this->_grade_to_sign); }
int 				AForm::getGradeToExecute(void) const { return (this->_grade_to_execute); }

// Util
void	AForm::beSigned(const Bureaucrat &ref) throw(std::exception) {
	if (this->_grade_to_sign < ref.getGrade())
		throw AForm::GradeTooLowException(ref.getName());
	if (this->_is_signed)
		throw AForm::FormAlreadySignedException(this->_name);
	this->_is_signed = true;
}

// Exception: GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException(void): _msg("Grade is too high") {}
AForm::GradeTooHighException::GradeTooHighException(const std::string &AForm) { this->_msg = AForm + " \'s grade is too high"; }
AForm::GradeTooHighException::~GradeTooHighException(void) throw() {}
const char	*AForm::GradeTooHighException::what(void) const throw() { return (this->_msg.c_str()); }

// Exception: GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(void): _msg("Grade is too low") {}
AForm::GradeTooLowException::GradeTooLowException(const std::string &AForm) { this->_msg = AForm + " \'s grade is too low"; }
AForm::GradeTooLowException::~GradeTooLowException(void) throw() {}
const char	*AForm::GradeTooLowException::what(void) const throw() { return (this->_msg.c_str()); }

// Exception: FormAlreadySignedException
AForm::FormAlreadySignedException::FormAlreadySignedException(void): _msg("AForm is already signed") {}
AForm::FormAlreadySignedException::FormAlreadySignedException(const std::string &name) { this->_msg = name + " is already signed"; }
AForm::FormAlreadySignedException::~FormAlreadySignedException(void) throw() {}
const char	*AForm::FormAlreadySignedException::what(void) const throw() { return (this->_msg.c_str()); }

// Exception: FormNotSignedException
AForm::FormNotSignedException::FormNotSignedException(void): _msg("AForm is not signed") {}
AForm::FormNotSignedException::FormNotSignedException(const std::string &name) { this->_msg = std::string(name.c_str()) + " is not signed"; }
AForm::FormNotSignedException::~FormNotSignedException(void) throw() {}
const char	*AForm::FormNotSignedException::what(void) const throw() { return (this->_msg.c_str()); }

// operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &ref) {
	os << ref.getName() << "\'s AForm is " << (ref.getIsSigned() ? "signed" : "unsigned");
	os << ", grade to sign is " << ref.getGradeToSign();
	os << " and grade to execute is " << ref.getGradeToExecute();
	return (os);
}