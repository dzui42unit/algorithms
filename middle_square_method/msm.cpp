#include <iostream>
#include <cstdlib>
#include <cmath>

unsigned long long	ft_count_digits(unsigned long long nb)
{
	unsigned long long counter;

	counter = 1;
	while (nb / 10 != 0)
	{
		counter++;
		nb /= 10;
	}
	return (counter);
}

unsigned long long	ft_generate_number(unsigned long long nb)
{
	unsigned long long middle;
	unsigned long long counter;

	nb = pow(nb, 2);
	counter = ft_count_digits(nb);
	middle = (nb / pow(10, 6));
	middle *= pow(10, 6);
	middle = nb - middle;
	middle /= 100;
	return (middle);
}

int		main(void)
{
	unsigned long long number;
	unsigned long long n;
	unsigned long long *arr;
	unsigned long long i;

	std::cout << "Enter a positive number that consists of 4 digits: ";
	while (!(std::cin >> number) || ft_count_digits(number) != 4)
	{
		system("clear");
		std::cout << "Invalid input, please use positive number that consists of 4 digits:\n\n";
		std::cout << "Enter a number: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue ; 
	}
	std::cout << "Enter a positive number of elements in array: ";
	while (!(std::cin >> n))
	{
		system("clear");
		std::cout << "Invalid input, please use positive integers:\n\n";
		std::cout << "Enter a number: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue ; 
	} 
	ft_generate_number(number);
	i = 1;
	arr = new unsigned long long[n];
	arr[0] = ft_generate_number(number);
	while (i < n)
	{
		arr[i] = ft_generate_number(arr[i - 1]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << "\n";
		i++;
	}
	std::cout << std::endl;
	delete []arr;
	return (0);
}