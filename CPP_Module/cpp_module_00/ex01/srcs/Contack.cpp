/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contack.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:16:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/08 23:18:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"

Contact::Contact(void) {
	this->first_name = std::string();
	this->last_name = std::string();
	this->nick_name = std::string();
	this->darkest_secret = std::string();
	this->phone_number = std::string();
	this->initialized = false;
	return;
}

Contact::~Contact(void) {
	return;
}