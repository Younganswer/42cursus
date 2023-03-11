#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	private:
		std::string _ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &ref);
		~Brain(void);
		Brain	&operator=(const Brain& ref);
		
		// Getter
		std::string			getIdea(int idx);
		const std::string	&getIdea(int idx) const;
};

#endif