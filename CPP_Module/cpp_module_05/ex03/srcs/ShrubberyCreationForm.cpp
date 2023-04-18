#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target(std::string()) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(std::string(target.c_str())) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Getter
const std::string	&ShrubberyCreationForm::getTarget(void) const { return (this->_target); }

// Setter
bool	ShrubberyCreationForm::setTarget(const std::string &target) {
	this->_target = target;
	return (true);
}

// Utils
void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const throw(std::exception) {
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	}
	std::ofstream fout(this->_target + "_shrubbery");
	if (!fout.is_open()) {
		throw ShrubberyCreationForm::FileOpenFailedException(this->_target + "_shruberry");
	}
	std::cout << bureaucrat.getName() << " trimmed a tree and created a shrubbery at " << this->_target << '\n';
	fout << "               .@@@@@@@." << '\n';
	fout << "       ,,,.  .@@@@@/@@@@@..o8888888o." << '\n';
	fout << "    ,&%%&%&%o@@@@@/@@@@@@@88\\88/8o8o." << '\n';
	fout << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88888\\88/88o" << '\n';
	fout << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888o" << '\n';
	fout << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << '\n';
	fout << "   `&%\\ ` /%&'    |.|        \\ '|8'" << '\n';
	fout << "       |o|        | |         | |" << '\n';
	fout << "       |.|        | |         | |" << '\n';
	fout << "     \\/ ._\\//_/__/  ,\\_//__.\\/.  \\_//__/_" << '\n';
	fout.close();
}

// Exception: FileOpenFailedException
ShrubberyCreationForm::FileOpenFailedException::FileOpenFailedException(void) {}
ShrubberyCreationForm::FileOpenFailedException::FileOpenFailedException(const std::string &name): std::exception() { this->_msg = std::string("Fail to open file: ") + name; }
ShrubberyCreationForm::FileOpenFailedException::~FileOpenFailedException(void) throw() {}
const char	*ShrubberyCreationForm::FileOpenFailedException::what(void) const throw() { return (this->_msg.c_str()); }