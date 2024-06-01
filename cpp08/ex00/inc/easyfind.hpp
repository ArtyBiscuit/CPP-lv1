#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iterator>
# include <algorithm>

class NotFound : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("Target Not Found.");
        }; 
};

template<typename T>
typename T::iterator easyfind(T container, int target){
    typename T::iterator it = find(container.begin(), container.end(), target);;
    if(it != container.end())
        return (it);
    throw NotFound();
};

#endif