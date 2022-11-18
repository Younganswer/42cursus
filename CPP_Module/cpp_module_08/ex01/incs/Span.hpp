/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 17:03:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
	private:
		std::vector<int>	_vec;
		unsigned int		_size;
		Span(void);

	public:
		Span(unsigned int n);
		Span(const Span &ref);
		Span	&operator=(const Span &rhs);
		~Span(void);

		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
		
		void	printVec(void);
};

#endif