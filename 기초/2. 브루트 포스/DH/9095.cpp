#include <iostream>

using namespace std;

int	test_case, n, arr[12], sum_case = 0;

void	setArr(void)
{
	for (int index = 0; index < n; index++)
		arr[index] = 1;
}

int sum(void)
{
	int sum = 0;

	for (int index = 0; arr[index]; index++)
		sum += arr[index];

	return (sum);
}

bool checkAllSame(void)
{
	int tmp = arr[0];
	for (int index = 0; arr[index]; index++)
	{
		if (tmp != arr[index])
			return(false);
	}
	return (true);
}

int size(void)
{
	int size = 0;

	for (int index = 0; arr[index]; index++)
		size++;

	return (size);
}

void	calculate(void)
{
	setArr();
	sum_case = 0;
	while (size() != 1)
	{
		if (sum() == n)
		{
			if (checkAllSame())
				sum_case++;
			else
				sum_case += size();
		}

		for (int i = 0; arr[i]; i++)
			cout << arr[i] << " ";
		cout << '\n';

		arr[size() - 1] = 0;
		if (size())
			arr[0]++;
	}
	if (n == 1)
		sum_case = 1;
	cout << sum_case << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> test_case;

	while(test_case)
	{
		cin >> n;
		bzero(arr, 12);
		calculate();
		test_case--;
	}

	return (0);
}
