#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		virtual	~RobotomyRequestForm(void);

		// Getter
		const std::string	&getTarget(void) const;

		// Utils
		void	execute(const Bureaucrat &bureaucrat) const throw(std::exception);
};

#endif