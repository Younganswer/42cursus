/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:33:44 by younhwan          #+#    #+#             */
/*   Updated: 2022/12/29 20:39:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/Replace.hpp"
#include "../../incs/utils.hpp"

Replace::Replace(void) {
	this->_fileName = std::string();
	this->_s1 = std::string();
	this->_s2 = std::string();
	return;
}

Replace::Replace(const std::string &fileName, const std::string &s1, const std::string &s2) {
	this->_fileName = std::string(fileName.c_str());
	this->_s1 = std::string(s1.c_str());
	this->_s2 = std::string(s2.c_str());
	return;
}

Replace::~Replace(void) {}

bool	Replace::replaceLine(std::string &line) {
	std::string::size_type	iter = line.find(this->_s1);
	while (iter != std::string::npos) {
		line.erase(iter, this->_s1.length());
		line.insert(iter, this->_s2);
		iter = line.find(this->_s1);
	}
	return (true);
}

bool	Replace::replace(void) {
	std::ifstream	fin(this->_fileName.c_str());
	if (!fin.is_open())
		exit_with_error(std::string("Fail to open file ") + "'" + this->_fileName + "'", 1);

	std::ofstream	fout(std::string(this->_fileName + ".replace").c_str());
	if (!fout.is_open())
		exit_with_error(std::string("Fail to open file ") + "'" + this->_fileName + ".replace" + "'", 1);
	
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