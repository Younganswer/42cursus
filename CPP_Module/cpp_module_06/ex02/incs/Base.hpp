/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:43:13 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/15 12:07:44 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base(void);
};

Base	*generate(void);
void	identify_from_pointer(Base *p);
void	identify_from_reference(Base &p);

#endif