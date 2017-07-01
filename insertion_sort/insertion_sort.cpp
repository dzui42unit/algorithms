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

void	ft_insertion_sort(int *arr, int n)
{
	int i;
	int j;
	int key;

	i = 0;
	while (i < n)
	{
		j = i - 1;
		key = arr[i];
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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
	ft_insertion_sort(arr, n);
	ft_print_array(arr, n);
	delete []arr;	
	return (0);
}
