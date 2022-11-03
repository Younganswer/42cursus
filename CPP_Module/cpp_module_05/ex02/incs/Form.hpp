/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:47:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:33:47 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

// Form(const std::string &name, int grade_to_sign, int grade_to_execute) throw(std::exception);
class Form {
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_execute;

	public:
		Form(void);
		Form(const std::string &name, const int grade_to_sign, const int grade_to_execute) throw(std::exception);
		Form(const Form &ref);
		Form	&operator=(const Form &rhs);
		~Form(void);

		// Getter
		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		// Utils
		void				beSigned(const Bureaucrat &ref) throw(std::exception);
		virtual void		execute(const Bureaucrat &ref) const throw(std::exception) = 0;

		// Exception
		class GradeTooHighException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooHighException(void);
				GradeTooHighException(const std::string &name);
				~GradeTooHighException(void) throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const std::string &name);
				~GradeTooLowException(void) throw();
				virtual const char* what() const throw();
		};

		class FormNotSignedException: public std::exception {
			private:
				std::string _msg;

			public:
				FormNotSignedException(void);
				FormNotSignedException(const std::string &name);
				~FormNotSignedException(void) throw();
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &ref);

#endif