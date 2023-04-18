#ifndef AForm_HPP
# define AForm_HPP

# include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	protected:
		AForm(void);
		AForm(const std::string &name, const int grade_to_sign, const int grade_to_execute) throw(std::exception);
		AForm(const AForm &ref);
		virtual AForm	&operator=(const AForm &rhs);

	public:
		virtual	~AForm(void);
		
		// Getter
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
				virtual	~GradeTooHighException(void) throw();
				virtual const char* what() const throw();
		};
		
		// Exception: GradeTooLowException
		class GradeTooLowException: public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const std::string &AForm);
				virtual	~GradeTooLowException(void) throw();
				virtual const char* what() const throw();
		};

		// Exception: FormAlreadySignedException
		class FormAlreadySignedException: public std::exception {
			private:
				std::string _msg;

			public:
				FormAlreadySignedException(void);
				FormAlreadySignedException(const std::string &name);
				virtual	~FormAlreadySignedException(void) throw();
				virtual const char* what() const throw();
		};

		// Exception: FormNotSignedException
		class FormNotSignedException: public std::exception {
			private:
				std::string _msg;

			public:
				FormNotSignedException(void);
				FormNotSignedException(const std::string &name);
				virtual	~FormNotSignedException(void) throw();
				virtual const char* what() const throw();
		};
};

// operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &ref);

#endif