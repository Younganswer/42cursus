/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/08 23:15:34 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int		first_pos;
	int		cur_pos;
	bool	print_field(const std::string &);
	
public:
	PhoneBook(void);
	bool	add(void);
	bool	search(void);
	~PhoneBook(void);
};

#endif