#include <iostream>
#include <cstdlib>
#include <cmath>

void	ft_error()
{
	std::cout << "Invalid input, please use integer numbers.\n\n";
	std::cout << "Enter a number: ";
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue ; 
}

int 	ft_count_numbers(int nb)
{
	int counter;

	counter = 1;
	while ((nb / 10) != 0)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

int 	ft_reverse_number(int nb, int counter)
{
	int reverse;
	int power;
	int i;

	i = 0;
	power = 10;
	reverse = 0;
	while (i < counter)
	{
		reverse +=  ((nb - (nb / power) * power) / (power / 10)) * pow(10, counter - i - 1);
		i++;
		power *= 10;
	}
	return (reverse);
}

int 	ft_is_polindromic(int nb_1, int nb_2, int counter)
{
	int i;
	int prev_1;
	int prev_2;
	int current_1;
	int current_2;

	i = 0;
	current_1 = 0;
	prev_1 = 0;
	current_2 = 0;
	prev_2 = 0;
	while (i < counter)
	{
		current_1 = (nb_1 / pow(10, counter - i - 1));
		prev_1 = (current_1 / 10) * 10;
		current_2 = (nb_2 / pow(10, counter - i - 1));
		prev_2 = (current_2 / 10) * 10;
		if (current_1 != current_2)
			return (0);
		i++;
	}
	return (1);
}

int		main(void)
{
	int	nb;
	int	reverse;
	int counter;

	std::cout << "Enter first number: ";
	while (!(std::cin >> nb))
		ft_error();
	system("clear");
	counter = ft_count_numbers(nb);
	reverse = ft_reverse_number(nb, counter);
	if (ft_is_polindromic(nb, reverse, counter))
		std::cout << "Number " << ft_reverse_number(nb, counter) << " is polindromic!" << std::endl << std::endl;
	else
		std::cout << "Number " << ft_reverse_number(nb, counter) << " is not polindromic!" << std::endl << std::endl;
	return (0);
}