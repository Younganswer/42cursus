/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:33:44 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:57:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/Replace.hpp"
#include "../../incs/utils.hpp"

Replace::Replace(void) {
	fileName = std::string();
	s1 = std::string();
	s2 = std::string();
	return;
}

Replace::Replace(const std::string &fileName, const std::string &s1, const std::string &s2) {
	this->fileName = fileName.c_str();
	this->s1 = s1.c_str();
	this->s2 = s2.c_str();
	return;
}

Replace::~Replace(void) {
	return;
}

bool	Replace::replaceLine(std::string &line) {
	std::string::size_type	iter = line.find(s1);
	while (iter != std::string::npos) {
		line.erase(iter, s1.length());
		line.insert(iter, s2);
		iter = line.find(s1);
	}
	return (true);
}

bool	Replace::replace(void) {
	std::ifstream	fin(fileName);
	if (!fin.is_open())
		exit_with_error("Fail to open file \'" + fileName + "\'", 1);
	std::ofstream	fout(fileName + ".replace");
	if (!fout.is_open())
		exit_with_error("Fail to open file \'" + fileName + ".replace\'", 1);
	
	std::string	line, stream;
	while (getline(fin, line)) {
		replaceLine(line);
		stream.append(line);
	}
	fout << stream;
	fin.close();
	fout.close();
	return (true);
}