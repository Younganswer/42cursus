#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base(void);
};

Base	*generate(void);
void	identify_from_pointer(Base *p);
void	identify_from_reference(Base &p);

#endif