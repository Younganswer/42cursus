#include "../incs/Contact.hpp"

Contact::Contact(void) {
	this->_first_name = "";
	this->_last_name = "";
	this->_nick_name = "";
	this->_darkest_secret = "";
	this->_phone_number = "";
	this->_initialized = false;
}

Contact::~Contact(void) {}

// Getter
std::string	Contact::getFirstName(void) { return this->_first_name; }
std::string	Contact::getLastName(void) { return this->_last_name; }
std::string	Contact::getNickName(void) { return this->_nick_name; }
std::string	Contact::getDarkestSecret(void) { return this->_darkest_secret; }
std::string	Contact::getPhoneNumber(void) { return this->_phone_number; }

const std::string	&Contact::getFirstName(void) const { return this->_first_name; }
const std::string	&Contact::getLastName(void) const { return this->_last_name; }
const std::string	&Contact::getNickName(void) const { return this->_nick_name; }
const std::string	&Contact::getDarkestSecret(void) const { return this->_darkest_secret; }
const std::string	&Contact::getPhoneNumber(void) const { return this->_phone_number; }

bool				Contact::getInitialized(void) const { return this->_initialized; }

// Setter
bool	Contact::setFirstName(std::string first_name) { this->_first_name = std::string(first_name.c_str()); return (true); }
bool	Contact::setLastName(std::string last_name) { this->_last_name = std::string(last_name.c_str());  return (true); }
bool	Contact::setNickName(std::string nick_name) { this->_nick_name = std::string(nick_name.c_str());  return (true); }
bool	Contact::setDarkestSecret(std::string darkest_secret) { this->_darkest_secret = std::string(darkest_secret.c_str());  return (true); }
bool	Contact::setPhoneNumber(std::string phone_number) { this->_phone_number = std::string(phone_number.c_str());  return (true); }
bool	Contact::setInitialized(bool initialized) { this->_initialized = initialized;  return (true); }