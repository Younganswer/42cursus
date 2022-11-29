/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:37 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/29 15:39:15 by younhwan         ###   ########.fr       */
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
		std::string			getName(void);
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		// Utils
		void				incGrade(void) throw(std::exception);
		void				decGrade(void) throw(std::exception);

		class GradeTooHighException: public std::exception {
			private:
				std::string	_msg;
			public:
				GradeTooHighException(void);
				GradeTooHighException(const std::string &name);
				~GradeTooHighException(void) throw();
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
			private:
				std::string	_msg;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const std::string &name);
				~GradeTooLowException(void) throw();
				virtual const char	*what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref);

#endif