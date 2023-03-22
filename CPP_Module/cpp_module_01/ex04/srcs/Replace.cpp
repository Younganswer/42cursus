#include "../incs/Replace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replace::Replace(void) {}
Replace::~Replace(void) {}

bool	Replace::replaceLine(std::string &line, const std::string &s1, const std::string &s2) {
	std::string::size_type	pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return (true);
}

bool	Replace::replace(const std::string &fileName, const std::string &s1, const std::string &s2) {
	std::ifstream	fin(fileName.c_str());
	if (!fin.is_open()) {
		throw (FileOpenError(fileName));
	}

	std::ofstream	fout(std::string(fileName + ".replace").c_str());
	if (!fout.is_open()) {
		throw (FileOpenError(fileName));
	}
	
	std::string	line, stream;

	while (getline(fin, line)) {
		replaceLine(line, s1, s2);
		stream.append(line);
	}
	
	fout << stream;
	fin.close();
	fout.close();
	return (true);
}

// Exception: FileOpenError
Replace::FileOpenError::FileOpenError(void): _msg("Error: Fail to open file") {}
Replace::FileOpenError::FileOpenError(const std::string &fileName): _msg("Error: Fail to open file: " + fileName) {}
Replace::FileOpenError::~FileOpenError(void) throw() {}
const char *Replace::FileOpenError::what(void) const throw() {
	return (_msg.c_str());
}