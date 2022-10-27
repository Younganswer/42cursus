/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:40:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:42:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		std::string ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &ref);
		Brain	&operator=(const Brain& ref);
		~Brain(void);
		
		std::string	*getIdeas(void) const;
};

#endif