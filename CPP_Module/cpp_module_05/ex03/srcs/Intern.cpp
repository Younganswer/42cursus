/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:36:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/04 19:57:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"

const Form	*(*Intern::_form[3])(const std::string &target) = {
	&Intern::makePresidentialPardonForm,
	&Intern::makeRobotomyRequestForm,
	&Intern::makeShrubberyCreationForm
};

const std::string	Intern::_form_name[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern(void) {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &ref) {
	(void)ref;
}

Intern	&Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

Intern::~Intern(void) {
	std::cout << "Intern destroyed" << std::endl;
}

Form	*Intern::makeForm(const std::string &name, const std::string &target) {
	for (int i = 0; i < 3; i++) {
		if (name == _form_name[i])
			return (Form *)(_form[i](target));
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return NULL;
}

Form	*Intern::makePresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

Form	*Intern::makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

// Path: CPP_Module/cpp_module_05/ex03/srcs/main.cpp
// Compare this snippet from CPP_Module/cpp_module_01/ex05/srcs/main.cpp:
// #include "Harl.hpp"
// 
// int main(void) {
// 	Harl harl;
// 
// 	harl.complain("debug");
// 	harl.complain("info");
// 	harl.complain("warning");
// 	harl.complain("error");
// 	harl.complain("undefined_behavior");
// 	harl.complain("undefined_behavior");
// 	harl.complain("undefined_behavior");
// 	harl.complain("undefined_behavior");
// 	harl.complain("undefined_behavior");
// 	harl.complain("undefined_behavior");
// 	harl.complain("undefined_behavior");

const std::string	Intern::_form_name[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Form	*Intern::makePresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

