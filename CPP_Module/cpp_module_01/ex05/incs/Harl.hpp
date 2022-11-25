/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:32:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:34:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	private:
		static const size_t	_FUNC_ARR_SIZE = 3001;
		void	(Harl::*_func[_FUNC_ARR_SIZE])(void);

		// Utils
		size_t	hash(const std::string &level);
		size_t	my_pow(size_t base, int power);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	undefined_behavior(void);
	
	public:
		Harl(void);
		~Harl(void);

		// Utils
		void	complain(const std::string &level);
};

#endif