#ifndef FORM_HPP
# define FORM_HPP

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

		class GradeTooHighException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooHighException(void);
				GradeTooHighException(const std::string &form);
				virtual	~GradeTooHighException(void) throw();
				virtual const char* what() const throw();
		};
		
		// Exception: GradeTooLowException
		class GradeTooLowException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const std::string &form);
				virtual	~GradeTooLowException(void) throw();
				virtual const char* what() const throw();
		};

		// Exception: FormAlreadySignedException
		class FormAlreadySignedException: public std::exception {
			private:
				std::string _msg;

			public:
				FormAlreadySignedException(void);
				FormAlreadySignedException(const std::string &form);
				virtual	~FormAlreadySignedException(void) throw();
				virtual const char* what() const throw();
		};
};

// operator overload
std::ostream	&operator<<(std::ostream &os, const Form &ref);

#endif