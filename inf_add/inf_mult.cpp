#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int 	ft_check_input(char *nb_1, char *nb_2)
{
	int i;

	i = 0;
	while (nb_1[i])
	{
		if (!isdigit(nb_1[i]))
			return (0);
		i++;
	}
	i = 0;
	while (nb_2[i])
	{
		if (!isdigit(nb_2[i]))
			return (0);
		i++;
	}
	return (1);
}

std::string 	ft_inf_add(const std::string nb_1, const std::string nb_2)
{
	std::string result;
	int 		i_1;
	int 		i_2;
	int 		to_add;
	int 		remain;

	i_1 = nb_1.length() - 1;
	i_2 = nb_2.length() - 1;
	remain = 0;
	while (i_2 >= 0)
	{
		to_add = (nb_2[i_2] - '0') + (nb_1[i_1] - '0') + remain;
		remain = to_add / 10;
		result.push_back((to_add + '0') - remain * 10);
		i_2--;
		i_1--;
	}
	if ((i_1 == -1 && i_2 == -1) && (remain > 0))
	{
		result.push_back(remain + '0');
		std::reverse(result.begin(), result.end());
		return (result);
	}
	while (i_1 >= 0)
	{
		to_add = (nb_1[i_1] - '0') + remain;
		remain = to_add / 10;
		result.push_back((to_add + '0') - remain * 10);
		i_1--;
	}
	if (i_1 == -1 && remain > 0)
		result.push_back(remain + '0');
	std::reverse(result.begin(), result.end());
	return (result);
}

int 	main(int argc, char **argv)
{
	std::string res;

	if (argc != 3)
	{
		std::cout << "Invalid number of parameters." << std::endl;
		std::cout << "Terminating ..." << std::endl << std::endl;
		return (-1);
	}
	if (!ft_check_input(argv[1], argv[2]))
	{
		std::cout << std::endl << "Invalid usage of the prigram." << std::endl;
		std::cout << "First argument is a positive integer number" << std::endl;
		std::cout << "Second argument is a positive integer number" << std::endl;
		std::cout << "Terminating ..." << std::endl << std::endl;
		return (-1);
	}
	std::string number_1(argv[1]);
	std::string number_2(argv[2]);
	if (number_1.length() >= number_2.length())
		res = ft_inf_add(number_1, number_2);
	else
		res = ft_inf_add(number_2, number_1);
	std::cout << "RESULT OF " << number_1 << " + " << number_2 << " = " << res << std::endl;
	return (0);
}