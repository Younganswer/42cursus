#include "../incs/Replace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replace::Replace(void) {
	this->_fileName = std::string();
	this->_s1 = std::string();
	this->_s2 = std::string();
}

Replace::Replace(const std::string &fileName, const std::string &s1, const std::string &s2) {
	this->_fileName = std::string(fileName.c_str());
	this->_s1 = std::string(s1.c_str());
	this->_s2 = std::string(s2.c_str());
}

Replace::~Replace(void) {}

bool	Replace::replaceLine(std::string &line) {
	std::string::size_type	iter = line.find(this->_s1);
	while (iter != std::string::npos) {
		line.erase(iter, this->_s1.length());
		line.insert(iter, this->_s2);
		iter += this->_s2.length();
		iter = line.find(this->_s1);
	}
	return (true);
}

bool	Replace::replace(void) {
	std::ifstream	fin(this->_fileName.c_str());
	if (!fin.is_open()) {
		std::cerr << "Fail to open file " << "'" << this->_fileName << "'" << '\n'; 
		return (false);
	}

	std::ofstream	fout(std::string(this->_fileName + ".replace").c_str());
	if (!fout.is_open()) {
		std::cerr << "Fail to open file " << "'" << this->_fileName << ".replace" << "'" << '\n';
		return (false);
	}
	
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