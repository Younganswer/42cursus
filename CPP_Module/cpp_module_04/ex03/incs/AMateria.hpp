#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
class ICharacter;

class AMateria {
	protected:
		std::string		_type;
		unsigned int	_xp;
		bool			_equipped;
		
	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &ref);
		virtual		~AMateria(void);
		AMateria	&operator=(const AMateria &ref);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;
		unsigned int		getXp(void) const;
		bool				getEquipped(void) const;

		// Setter
		void				setEquipped(bool equipped);

		// Utils	
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif