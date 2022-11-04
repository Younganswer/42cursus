/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:32:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/04 19:53:37 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		static Form	*makePresidentialPardonForm(const std::string &target);
		static Form	*makeRobotomyRequestForm(const std::string &target);
		static Form	*makeShrubberyCreationForm(const std::string &target);
		
		static const Form			*(*_form[3])(const std::string &target);
		static const std::string	_form_name[3];
		
	public:
		Intern(void);
		Intern(const Intern &ref);
		Intern	&operator=(const Intern &rhs);
		~Intern(void);

		Form	*makeForm(const std::string &name, const std::string &target);
};

#endif