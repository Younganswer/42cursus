/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:08:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/12 21:10:51 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

class Convert {
	private:
		std::string	_str;
		int			_int;
		char		_char;

		float		_float;
		bool		_is_nanf;
		bool		_is_positive_inff;
		bool		_is_negative_inff;

		double		_double;
		bool		_is_nan;
		bool		_is_positive_inf;
		bool		_is_negative_inf;

		bool	parameterIsChar(const std::string &str);
		bool	parameterIsInt(const std::string &str);
		bool	parameterIsFloat(const std::string &str);
		bool	parameterIsDouble(const std::string &str);
		
	public:
		Convert(void);
		Convert(const std::string &str);
		Convert(const Convert &ref);
		Convert	&operator=(const Convert &rhs);
		~Convert(void);

		// Utils
		void	convert(const std::string &str);
		void	print(void);
};

#endif