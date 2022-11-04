/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:26:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:35:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm(void);

		// Getter
		const std::string	&getTarget(void) const;

		// Utils
		void				execute(const Bureaucrat &ref) const throw(std::exception);
};

#endif