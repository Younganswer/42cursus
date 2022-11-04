/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:36:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/04 22:10:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"

Form	*(*const Intern::_form[3])(const std::string &target) = {
	makePresidentialPardonForm,
	makeRobotomyRequestForm,
	makeShrubberyCreationForm
};

const std::string	Intern::_form_name[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern(void) {}

Intern::Intern(const Intern &ref) {
	(void)ref;
}

Intern	&Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return (*this);
}

Intern::~Intern(void) {}

Form	*Intern::makePresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(const std::string &name, const std::string &target) {
	for (int i=0; i<3; i++) {
		if (name == _form_name[i]) {
			std::cout << "Intern creates " << name << '\n';
			return (_form[i](target));
		}
	}
	std::cout << "Intern can't create " << name << '\n';
	return (NULL);
}