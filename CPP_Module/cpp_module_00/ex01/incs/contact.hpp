/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:44:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 21:06:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact {
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	darkest_secret;
	std::string	phone_number;
	bool		initialized;

	Contact(void) {}
	~Contact(void) {}
};

#endif // CONTACT_HPP
