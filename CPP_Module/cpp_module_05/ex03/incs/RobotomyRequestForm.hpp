/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:38:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:38:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm: public Form {
	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm(void);

		// Getter
		const std::string	&getTarget(void) const;

		// Utils
		void				execute(const Bureaucrat &ref) const throw(std::exception);
};

#endif