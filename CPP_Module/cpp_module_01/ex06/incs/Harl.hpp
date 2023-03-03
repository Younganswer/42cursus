#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define FUNC_ARR_SIZE 10003

class Harl {
	private:
		void	(Harl::*_func[FUNC_ARR_SIZE])(void);

		// Utils
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	undefined_behavior(void);

	public:
		Harl(void);
		~Harl(void);

		// Util
		void	complain(std::string level);
};

size_t	hash(const std::string &level);

#endif