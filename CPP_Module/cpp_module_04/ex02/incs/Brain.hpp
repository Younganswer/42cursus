/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:40:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:38:53 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		std::string _ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &ref);
		~Brain(void);
		Brain	&operator=(const Brain& ref);
		
		// Getter
		std::string			getIdea(int idx);
		const std::string	&getIdea(int idx) const;
};

#endif