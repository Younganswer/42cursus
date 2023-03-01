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
		bool	setFirstName(std::string first_name);
		bool	setLastName(std::string last_name);
		bool	setNickName(std::string nick_name);
		bool	setDarkestSecret(std::string darkest_secret);
		bool	setPhoneNumber(std::string phone_number);
		bool	setInitialized(bool initialized);
};

#endif
