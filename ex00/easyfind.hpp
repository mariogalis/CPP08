#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>

# define RESET				"\x1b[0m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE 				"\x1b[34m"

class NotFoundException: public std::exception
{
	public:

		const char *what(void) const throw() 
        {
         return ("Number not found"); 
        }
};

template <typename T>
typename T::const_iterator	easyfind(T &list, int n)
{
	typename T::const_iterator	it;

	it = std::find(list.begin(), list.end(), n);
	if (it == list.end())
		throw (NotFoundException());
	return (it);
}

#endif