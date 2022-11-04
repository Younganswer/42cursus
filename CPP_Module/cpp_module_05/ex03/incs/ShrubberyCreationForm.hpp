/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:42:48 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 15:53:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm: public Form {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm(void);

		// Getter
		const std::string	&getTarget(void) const;

		// Setter
		void				setTarget(const std::string &target);

		// Utils
		void				execute(const Bureaucrat &ref) const throw(std::exception);

		// Exception
		class FileOpenException: public std::exception {
			private:
				std::string	_msg;
				
			public:
				FileOpenException(void);
				FileOpenException(const std::string &name);
				~FileOpenException(void) throw();
				virtual const char	*what(void) const throw();
		};
};

#endif