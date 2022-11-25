/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contack.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:16:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 17:08:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"

Contact::Contact(void) {}

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
void	Contact::setFirstName(const std::string &first_name) { this->_first_name = std::string(first_name.c_str()); }
void	Contact::setLastName(const std::string &last_name) { this->_last_name = std::string(last_name.c_str()); }
void	Contact::setNickName(const std::string &nick_name) { this->_nick_name = std::string(nick_name.c_str()); }
void	Contact::setDarkestSecret(const std::string &darkest_secret) { this->_darkest_secret = std::string(darkest_secret.c_str()); }
void	Contact::setPhoneNumber(const std::string &phone_number) { this->_phone_number = std::string(phone_number.c_str()); }
void	Contact::setInitialized(const bool &initialized) { this->_initialized = initialized; }