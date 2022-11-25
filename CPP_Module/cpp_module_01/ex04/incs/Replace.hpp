/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:30:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:27:28 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class Replace {
	private:
		std::string	_fileName;
		std::string	_s1;
		std::string	_s2;

		// Util
		bool	replaceLine(std::string &line);

	public:
		Replace(void);
		Replace(const std::string &fileName, const std::string &s1, const std::string &s2);
		~Replace(void);

		// Util	
		bool	replace(void);
};

#endif