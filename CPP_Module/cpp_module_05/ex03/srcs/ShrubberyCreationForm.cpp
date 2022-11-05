/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:43:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/05 17:52:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137), _target(std::string()) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("ShrubberyCreationForm", 145, 137), _target(std::string(target.c_str())) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref): Form("ShrubberyCreationForm", 145, 137), _target(std::string(ref.getTarget().c_str())) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
		this->_target = std::string(rhs.getTarget().c_str());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Getter
const std::string	&ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

// Setter
void				ShrubberyCreationForm::setTarget(const std::string &target) {
	this->_target = std::string(target.c_str());
}

// Utils
void				ShrubberyCreationForm::execute(const Bureaucrat &ref) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw Form::FormNotSignedException();
	}
	else if (ref.getGrade() > this->getGradeToExecute()) {
		throw Form::GradeTooLowException();
	}
	else {
		std::ofstream fout(this->_target + "_shrubbery");
		if (!fout.is_open()) {
			throw ShrubberyCreationForm::FileOpenException(this->_target + "_shruberry");
		}
		fout << "               .@@@@@@@." << '\n';
		fout << "       ,,,.  .@@@@@/@@@@@..o8888888o." << '\n';
		fout << "    ,&%%&%&%o@@@@@/@@@@@@@88\\88/8o88o." << '\n';
		fout << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88888\\88/88o" << '\n';
		fout << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888o" << '\n';
		fout << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << '\n';
		fout << "   `&%\\ ` /%&'    |.|        \\ '|8'" << '\n';
		fout << "       |o|        | |         | |" << '\n';
		fout << "       |.|        | |         | |" << '\n';
		fout << "  __\\\\/ ._\\//_/__/  ,\\_//__.\\/.  \\_//__/_" << '\n';
		fout.close();
	}
}

ShrubberyCreationForm::FileOpenException::FileOpenException(void) {}

ShrubberyCreationForm::FileOpenException::FileOpenException(const std::string &name): std::exception() {
	this->_msg = std::string("Fail to open file: ") + name;
}

ShrubberyCreationForm::FileOpenException::~FileOpenException(void) throw() {}

const char	*ShrubberyCreationForm::FileOpenException::what(void) const throw() {
	return (this->_msg.c_str());
}