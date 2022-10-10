/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:32:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/10 14:01:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
private:
	static const size_t	FUNC_ARR_SIZE = 3001;
	void	(Harl::*func[FUNC_ARR_SIZE])(void);
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
	void	complain(const std::string &level);
};

#endif