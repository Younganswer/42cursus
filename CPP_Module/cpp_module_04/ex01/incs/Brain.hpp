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
		Brain	&operator=(const Brain &rhs);
		
		// Getter
		const std::string	&getIdea(int idx) const;

		// Setter
		bool	setIdea(int idx, const std::string &idea);
};

#endif