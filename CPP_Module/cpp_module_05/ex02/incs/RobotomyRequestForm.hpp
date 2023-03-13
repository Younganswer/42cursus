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
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		virtual	~RobotomyRequestForm(void);
		virtual RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

		// Getter
		std::string			getTarget(void);
		const std::string	&getTarget(void) const;

		// Utils
		void	execute(const Bureaucrat &ref) const throw(std::exception);
};

#endif