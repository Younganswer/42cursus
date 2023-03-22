#include "../incs/AMateria.hpp"

AMateria::AMateria(void): _type(std::string()), _xp(0), _equipped(false) {}
AMateria::AMateria(const std::string &type): _type(type), _xp(0), _equipped(false) {}
AMateria::AMateria(const AMateria &ref): _type(ref._type), _xp(ref._xp), _equipped(ref._equipped) {}
AMateria::~AMateria(void) {}

AMateria	&AMateria::operator=(const AMateria &rhs) {
	(void) rhs;
	return (*this);
}

// Getter
std::string			AMateria::getType(void) { return (this->_type); }
const std::string	&AMateria::getType(void) const { return (this->_type); }
unsigned int		AMateria::getXp(void) const { return (this->_xp); }
bool				AMateria::getEquipped(void) const { return (this->_equipped); }

// Setter
void				AMateria::setEquipped(bool equipped) { this->_equipped = equipped; }

// Utils
void				AMateria::use(ICharacter &target) { (void) target; this->_xp += 10; }