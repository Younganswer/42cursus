#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void) {
	srand(time(NULL));
	{
		Base	*base = generate();

		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;
	}
	return (0);
}