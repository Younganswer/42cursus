/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 18:19:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];
		int		_first_pos;
		int		_cur_pos;
		
		int		getIndex(void);
		bool	printPhoneBook(void);
		bool	printRecord(int idx);
		bool	printField(const std::string &str);
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		bool	add(void);
		bool	search(void);
};

#endif