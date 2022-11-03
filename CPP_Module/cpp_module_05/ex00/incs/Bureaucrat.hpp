/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:37 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 12:29:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade) throw(std::exception);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat	&operator=(const Bureaucrat &ref);
		~Bureaucrat(void);

		// Getter
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void				incGrade(void) throw(std::exception);
		void				decGrade(void) throw(std::exception);

		class GradeTooHighException: public std::exception {
			private:
				std::string	_msg;
			public:
				GradeTooHighException(void) {}
				GradeTooHighException(const std::string &name) { _msg = std::string("\033[31mError: ") + name.c_str() + "\'s grade is too high\033[0m"; }
				~GradeTooHighException(void) throw() {}
				virtual const char	*what(void) const throw() {
					return (_msg.c_str());
				}
		};

		class GradeTooLowException: public std::exception {
			private:
				std::string	_msg;

			public:
				GradeTooLowException(void) {}
				GradeTooLowException(const std::string &name) { _msg = std::string("\033[31mError: ") + name.c_str() + "\'s grade is too low\033[0m"; }
				~GradeTooLowException(void) throw() {}
				virtual const char	*what(void) const throw() {
					return (_msg.c_str());
				}
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref);

#endif