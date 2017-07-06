#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

int	ft_find_sum(std::vector<int> &arr, int sum)
{
	int l;
	int r;

	std::cout << "kek\n\n";
	l = 0;
	r = arr.size() - 1;
	std::sort(arr.begin(), arr.end());
	while (l < r)
	{
		if (arr[l] + arr[r] == sum)
		{
			std::cout << "Numbers " << arr[l] << " and " << arr[r] << " make a sum = " << sum << "\n\n";
			return (1);
		}
		if (arr[l] + arr[r] < sum)
			l++;
		if (arr[l] + arr[r] > sum)
			r--;
	}
	std::cout << "Sum not found.\n\n";
	return (0);
}

int	main(void)
{
	int 				sum;
	std::vector<int> 	arr;
	int 				i;
	int					elem;

	i = 0;
	while (true)
	{
		std::cout << "Enter an element (or invalid input to stop) #" << i << ": ";
		if (!(std::cin >> elem))
			break ;
		i++;
		arr.push_back(elem);
	}
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue ;
	while (true)
	{
		std::cout << "Enter a sum to find: ";
		if (!(std::cin >> sum))
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue ;
			continue ;
		}
		break ;
	}
	ft_find_sum(arr, sum);
}
