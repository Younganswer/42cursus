/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:44:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 17:01:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_darkest_secret;
		std::string	_phone_number;
		bool		_initialized;

	public:
		Contact(void);
		~Contact(void);

		// Getter
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getDarkestSecret(void);
		std::string	getPhoneNumber(void);

		const std::string	&getFirstName(void) const;
		const std::string	&getLastName(void) const;
		const std::string	&getNickName(void) const;
		const std::string	&getDarkestSecret(void) const;
		const std::string	&getPhoneNumber(void) const;

		bool				getInitialized(void) const;
		
		// Setter
		void	setFirstName(const std::string &first_name);
		void	setLastName(const std::string &last_name);
		void	setNickName(const std::string &nick_name);
		void	setDarkestSecret(const std::string &darkest_secret);
		void	setPhoneNumber(const std::string &phone_number);
		void	setInitialized(const bool &initialized);
};

#endif
