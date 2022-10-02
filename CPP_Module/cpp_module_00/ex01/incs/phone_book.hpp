/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 21:15:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include "contact.hpp"

class Phone_book {
private:
	Contact	contacts[8];
	int		first_pos;
	int		cur_pos;
	bool	print_field(const std::string &);
	
public:
	Phone_book(void);
	bool	add(void);
	bool	search(void);
	~Phone_book(void);
};

#endif