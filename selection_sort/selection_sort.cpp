#include <iostream>
#include <cstdlib>

void	ft_fill_array(int *arr, int n)
{
	using std::cout;
	using std::cin;
	using std::endl;

	int i;

	i = 0;
	while (i < n)
	{
		cout << "Arr[" << i << "] = ";
		if (!(cin >> arr[i]))
		{
			cout << "Invalid input ...." << endl;
			cout << "Please use integer numbers for representing of elements of array." << endl << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			continue ;
		}
		i++;
	}
}

void	ft_print_array(int *arr, int n)
{
	using std::cout;
	using std::endl;

	int i;
	
	i = 0;
	while (i < n)
	{
		cout << "Arr[" << i << "] = " << arr[i] << endl;
		i++;
	}
	cout << endl;
}

void	ft_selection_sort(int *arr, int n)
{
	int i;
	int temp;
	int i_min;
	int j;

	i = 0;
	while (i < n - 1)
	{
		i_min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[i_min])
				i_min = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[i_min];
		arr[i_min] = temp;
		i++;
	}
}

int	main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	int n;
	int *arr;

	cout << "Enter a number of elements in array: ";
	while (!(cin >> n) || n <= 0)
	{
		cout << "Invalid input .... " << endl;
		cout << "Please use positive integer numbers for representing of nubmer of elements in array." << endl << endl;
		cout << "Enter a number of elements in array: ";
		cin.clear();
		while (cin.get() != '\n')
			continue ;
	}
	system("clear");
	arr = new int[n];
	ft_fill_array(arr, n);
	system("clear");
	cout << "------------------ GIVEN ARRAY ---------------" << endl << endl;
	ft_print_array(arr, n);	
	cout << "------------------ SORTED ARRAY --------------" << endl << endl;
	ft_selection_sort(arr, n);
	ft_print_array(arr, n);
	delete []arr;	
	return (0);
}
