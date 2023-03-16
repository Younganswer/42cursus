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

class Serialize {
	private:
		Serialize(const Serialize &src);
		Serialize	&operator=(const Serialize &rhs);

	public:
		Serialize(void);
		~Serialize(void);

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif