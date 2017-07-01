#include <iostream>
#include <cstdlib>
#include <ctime>

struct r_numb
{
	unsigned long seed;
	unsigned long multiplier;
	unsigned long	increment;
	unsigned long modulo;
};

void	ft_error()
{
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue ;
	std::cout << "Invalid input. Please use positive integer numbers.\n\n";
}

void   ft_make_number(r_numb *numb)
{
	numb->seed = (numb->multiplier * numb->seed + numb->increment) % numb->modulo;
}

void	ft_generate(r_numb *numb, unsigned long *arr, unsigned long n)
{
	int i;

	i = 0;
	std::cout << "Number of elements: " << n << "\n";
	std::cout << "Seed: " << numb->seed << "\n";
	std::cout << "Multiplier: " << numb->multiplier << "\n";
	std::cout << "Increment: " << numb->increment << "\n";
	std::cout << "Modulo: " << numb->modulo << "\n"; 
	while (i < n)
	{
		ft_make_number(numb);
		arr[i] = numb->seed;
		i++;
	}
}

void	ft_print_array(unsigned long *arr, unsigned long n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		std::cout << "arr[" << i << "] = ";
		std::cout << arr[i] << "\n";
		i++;
	}
	std::cout << std::endl;
}

int		main(void)
{
	r_numb 			number;
	unsigned long 	n;
	unsigned long 	i;
	unsigned long 	*arr;
	unsigned long 	temp;

	std::cout << "Enter a number of elements you want obtain: ";
	while (!(std::cin >> n) || n <= 0)
	{
		ft_error();
		std::cout << "Enter a number of elements you want obtain: ";
	}
	system("clear");
	std::cout << "Enter a number for seed: ";
	while (!(std::cin >> number.seed) || number.seed <= 0)
	{
		ft_error();
		std::cout << "Enter a number for seed: ";
	}
	system("clear");
	std::cout << "Enter a number for multipler: ";
	while (!(std::cin >> number.multiplier) || number.multiplier <= 0)
	{
		ft_error();
		std::cout << "Enter a number for multipler: ";
	}
	system("clear");
	std::cout << "Enter a number for increment: ";
	while (!(std::cin >> number.increment) || number.increment <= 0)
	{
		ft_error();
		std::cout << "Enter a number for increment: ";
	}
	system("clear");
	std::cout << "Enter a number for modulo: ";
	while (!(std::cin >> number.modulo) || number.modulo <= 0)
	{
		ft_error();
		std::cout << "Enter a number for modulo: ";
	}
	arr = new unsigned long[n];
	if (arr == NULL)
	{
		std::cout << "Memory allocation error occured!\n\n";
		exit (-1);
	}
	system("clear");
	ft_generate(&number, arr, n);
	ft_print_array(arr, n);
	delete []arr;
	return (0);
}
