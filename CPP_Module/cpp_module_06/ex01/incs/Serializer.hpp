#ifndef DATA_HPP
# define DATA_HPP

# include <string>

typedef struct _Data {
	std::string s1;
	std::string s2;
	int n;

	_Data(void);
	_Data(const std::string &s1, const std::string &s2, int n);
	~_Data(void);
}	Data;

class Serializer {
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &ref);
		Serializer	&operator=(const Serializer &rhs);

	public:
		static uintptr_t	Serializer(Data *ptr);
		static Data			*deSerializer(uintptr_t raw);
};

#endif