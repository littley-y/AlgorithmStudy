#include <iostream>

using namespace std;

int		k, number[11], max_number[11] = {0, }, min_number[11] = {0, }, max_sum = 0, min_sum = 2147283647;
char 	inequality_sign[9] = {0, };
bool	visited[11] = {false, };

void	printArr(const int* arr)
{
	for (int index = 0; index < k + 1; ++index)
		cout << arr[index];
	cout << '\n';
}

void	printArr(const char* arr)
{
	for (int index = 0; index < k + 1; ++index)
		cout << arr[index];
	cout << '\n';
}

void	setMax(void)
{
	int sum = 0;

	for (int index = 0; index < k + 1; ++index)
	{
		sum += number[index];
	}

	if (sum >= max_sum)
	{
		max_sum = sum;
		for (int index = 0; index < k + 1; ++index)
			max_number[index] = number[index];
	}
}

void	setMin(void)
{
	int sum = 0;

	for (int index = 0; index < k + 1; ++index)
	{
		sum += number[index];
	}

	if (sum < min_sum)
	{
		min_sum = sum;
		for (int index = 0; index < k + 1; ++index)
			min_number[index] = number[index];
	}
}

void	calculate(int num_position, int sign_position)
{
	if (num_position == k + 1)
	{
		setMax();
		setMin();
		return ;
	}

	for (int num = 0; num < 10; ++num)
	{
		if (visited[num] == true)
			continue ;

		if (sign_position >= 0)
		{
			if (inequality_sign[sign_position] == '<')
			{
				if (number[num_position - 1] >= num)
					continue ;
			}
			else if (inequality_sign[sign_position] == '>')
			{
				if (number[num_position - 1] <= num)
					continue ;
			}
		}

		number[num_position] = num;
		visited[num] = true;

		calculate(num_position + 1, sign_position + 1);

		visited[num] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	for (int index = 0; index < k; ++index)
		cin >> inequality_sign[index];

	calculate(0, -1);

	printArr(max_number);
	printArr(min_number);

	return (0);
}
