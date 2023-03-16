#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		virtual	~ShrubberyCreationForm(void);

		// Getter
		std::string			getTarget(void);
		const std::string	&getTarget(void) const;

		// Setter
		bool	setTarget(const std::string &target);

		// Utils
		void	execute(const Bureaucrat &ref) const throw(std::exception);

		// Exception: FileOpenFailedException
		class FileOpenFailedException: public std::exception {
			private:
				std::string	_msg;
				
			public:
				FileOpenFailedException(void);
				FileOpenFailedException(const std::string &name);
				~FileOpenFailedException(void) throw();
				virtual const char	*what(void) const throw();
		};
};

#endif