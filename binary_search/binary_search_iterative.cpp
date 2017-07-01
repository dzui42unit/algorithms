#include <iostream>
#include <cstdlib>

void	ft_fill_array(int *arr, int n)
{
	using std::cin;
	using std::cout;
	using std::endl;

	int i;

	i = 0;
	cout << "------------| FULL FILL THE ARRAY |------------" << endl;
	cout << "---|ENTER A SORTED ARRAY IN ASCENDING ORDER|---" << endl;
	cout << "---|TO INMPLEMENT BINARY A SEARCH OPERATION|---" << endl << endl;
	while (i < n)
	{
		cout << "Arr[" << i << "] = ";
		cin >> arr[i];
		if (!cin >> arr[i])
		{
			cout << "Invalid input .... " << endl;
			cout << "Please use integer numbers for elements of the array." << endl << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			continue ;
		}
		i++;
	}
	system("clear");
}

void	ft_print_array(int *arr, int n)
{
	using std::endl;
	using std::cout;

	int i;

	i = 0;
	cout << "----------| YOUR ARRAY |----------" << endl << endl;
	while (i < n)
	{
		cout << "Arr[" << i << "] = " << arr[i] << endl;
		i++;
	}
	cout << endl;
}

int	ft_is_sorted(int *arr, int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_enter_number(int *n)
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter a number of elements in array: ";
	while (!(cin >> *n) || *n <= 0)
	{
		cout << "Invalid input .... " << endl;
		cout << "Please use positive numbers to represent the number of elements in array." << endl << endl;
		cout << "Enter a number of elements in array: ";
		cin.clear();
		while (cin.get() != '\n')
			continue ;
	}
}

void	ft_enter_what_to_find(int *find)
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter a number to find in array: ";
	while (!(cin >> *find))
	{
		cout << "Invalid input ..... " << endl;
		cout << "Please use decimal numbers to represent the number to find." << endl << endl;
		cout << "Enter a number to find in array: ";
		cin.clear();
		while (cin.get() != '\n')
			continue ;
	}
}

int	ft_binary_search(int *arr, int n, int find)
{
	int p;
	int r;
	int q;

	p = 0;
	r = n - 1;
	while (p <= r)
	{
		q = (r + p) / 2;
		if (arr[q] == find)
			return (q);
		if (arr[q] > find)
			r = q - 1;
		if (arr[q] < find)
			p  = q + 1;
	}
	return (-1);
}

int	main(void)
{
	using std::cout;
	using std::endl;
	
	int n;
	int find;
	int *arr;
	int position;

	ft_enter_number(&n);
	arr = new int[n];
	system("clear");
	ft_fill_array(arr, n);
	ft_print_array(arr, n);
	if (ft_is_sorted(arr, n))
	{
		cout << "----------| IS SORTED |----------" << endl << endl;
		ft_enter_what_to_find(&find);
		cout << endl << "ELEMENT YOU WANT FIND IS : " << find << endl << endl;
		position = ft_binary_search(arr, n, find);
		if (position != -1)
			cout << "VALUE " << find << " IS ON THE " << position << " position." << endl << endl;
		else
			cout << "VALUE " << find << " WAS NOT FOUND IN ARRAY." << endl << endl;
	}
	else
		cout << "---------| YOU HAVE ENTERED USORTED ARRAY |-----------" << endl;
	delete []arr;
	return (0);
}
