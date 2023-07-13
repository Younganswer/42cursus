#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <exception>

class Converter {
	private:
		Converter(void);
		~Converter(void);
		Converter(Converter const &other);
		Converter &operator=(Converter const &other);
	
	public:
		static int	convert(const char *arg) throw(std::exception);
	
	public:
		class InvalidInputException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class NegativeValueException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

#endif