/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:30:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:52:51 by younhwan         ###   ########.fr       */
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
	std::string	fileName;
	std::string	s1;
	std::string	s2;
	bool	replaceLine(std::string &line);

public:
	Replace(void);
	Replace(const std::string &fileName, const std::string &s1, const std::string &s2);
	~Replace(void);
	
	bool	replace(void);
};

#endif