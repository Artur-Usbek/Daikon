
#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>

/*
// Used for empty line
void logging(){
	std::cout << std::endl;
};
*/

// Used for printing out one right value
template<typename T>
void logging(T &input)
{
	std::cout << input << std::endl;
};

// Printing out multiple right values
// -> Splitting up
template <typename T, typename ... Args>
void logging(T &first, Args & ... rest)
{
	logging(first);
	logging(rest...);
};

// Used for printing out one left value
template<typename T>
void logging(T &&input)
{
	std::cout << input << std::endl;
};

// Printing out multiple left values
// -> Splitting up 
template <typename T, typename ... Args>
void logging(T &&first, Args && ... rest)
{
	logging(first);
	logging(rest...);
};

#endif //LOG_HPP