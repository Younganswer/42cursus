#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		virtual	~PresidentialPardonForm(void);

		// Getter
		const std::string	&getTarget(void) const;

		// Utils
		void	execute(const Bureaucrat &bureaucrat) const throw(std::exception);
};

#endif