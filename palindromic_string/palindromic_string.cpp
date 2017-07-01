#include <string>
#include <iostream>
#include <cstdlib>

std::string		ft_make_string(std::string init)
{
	std::string result;
	int 		i;

	i = 0;
	while (i < init.length())
	{
		if (isalpha(init[i]))
			result.push_back(tolower(init[i]));
		if (isdigit(init[i]))
			result.push_back(init[i]);
		i++;
	}
	return (result);
}

std::string 	ft_reverse_string(std::string init)
{
	std::string reverse;
	int 		i;

	i = init.length() - 1;
	while (i >= 0)
	{
		reverse.push_back(init[i]);
		i--;
	}
	return (reverse);
}

int 	ft_is_palindromic(std::string str1, std::string str2)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int		main(void)
{
	std::string initial;
	std::string reverse;

	std::cout << "Enter a string to check whether it is palindromic or not:\n\n";
	getline(std::cin, initial);	
	initial = ft_make_string(initial);
	reverse = ft_reverse_string(initial);
	if (ft_is_palindromic(initial, reverse))
		std::cout << "\nThis string is palindromic\n\n";
	else
		std::cout << "\nThis string is not palindromic\n\n";
	return (0);
}