#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade) throw(std::exception);
		Bureaucrat(const Bureaucrat &ref);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &rhs);

		// Getter
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		// Utils
		void	incGrade(void) throw(std::exception);
		void	decGrade(void) throw(std::exception);
		void	signForm(Form &ref) throw(std::exception);

		// Exception: GradeTooHighException
		class GradeTooHighException: public std::exception {
			private:
				std::string	_msg;

			public:
				GradeTooHighException(void);
				GradeTooHighException(const std::string &name);
				virtual	~GradeTooHighException(void) throw();
				virtual const char	*what(void) const throw();
		};

		// Exception: GradeTooLowException
		class GradeTooLowException: public std::exception {
			private:
				std::string	_msg;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const std::string &name);
				virtual	~GradeTooLowException(void) throw();
				virtual const char	*what(void) const throw();
		};

		// Exception: CannotSignException
		class CannotSignException: public std::exception {
			private:
				std::string	_msg;

			public:
				CannotSignException(void);
				CannotSignException(const std::string &name, const std::exception &exception);
				virtual	~CannotSignException(void) throw();
				virtual const char	*what(void) const throw();
		};

		// UnknownException
		class UnknownException: public std::exception {
			private:
				std::string	_msg;

			public:
				UnknownException(void);
				virtual	~UnknownException(void) throw();
				virtual const char	*what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref);

#endif