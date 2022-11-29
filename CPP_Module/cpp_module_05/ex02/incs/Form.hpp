/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:47:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/29 16:36:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	public:
		Form(void);
		Form(const std::string &name, const int grade_to_sign, const int grade_to_execute) throw(std::exception);
		Form(const Form &ref);
		~Form(void);
		Form	&operator=(const Form &ref);

		// Getter
		std::string			getName(void);
		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		// Util
		void				beSigned(const Bureaucrat &ref) throw(std::exception);
		virtual void		execute(const Bureaucrat &ref) const throw(std::exception) = 0;

		// Exception: GradeTooHighException
		class GradeTooHighException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooHighException(void);
				GradeTooHighException(const std::string &name);
				~GradeTooHighException(void) throw();
				virtual const char* what() const throw();
		};

		// Exception: GradeTooLowException
		class GradeTooLowException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const std::string &name);
				~GradeTooLowException(void) throw();
				virtual const char* what() const throw();
		};

		// Exception: FormNotSignedException
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

// operator overload
std::ostream	&operator<<(std::ostream &os, const Form &ref);

#endif