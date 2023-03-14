#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

class Intern {
	private:
		static const size_t	_FUNC_ARR_SIZE = 10003;
		static AForm		*(* _form[Intern::_FUNC_ARR_SIZE])(const std::string &target);

		static AForm		*makePresidentialPardonForm(const std::string &target);
		static AForm		*makeRobotomyRequestForm(const std::string &target);
		static AForm		*makeShrubberyCreationForm(const std::string &target);
		static AForm		*cannotMakeForm(const std::string &target);

		static size_t		hash(const std::string &str);
		static size_t		ft_pow(int base, int exp);
		
		Intern(const Intern &ref);
		Intern	&operator=(const Intern &rhs);

	public:
		Intern(void);
		~Intern(void);

		AForm	*makeForm(const std::string &name, const std::string &target);
};

#endif