#include <iostream>

using namespace std;

int		N, arr[9], permutation[9], sum_max = -2147483648;
bool	selected[9];

void	calculate(void)
{
	int sum = 0;
	for (int index = 0; index <= N - 2; ++index)
	{
		sum += abs(permutation[index] - permutation[index + 1]);
	}

	if (sum > sum_max)
		sum_max = sum;
}

void	findMax(int position)
{
	if (position == N)
	{
		calculate();
		return ;
	}

	for (int arr_index = 0; arr_index < N; ++arr_index)
	{
		if (selected[arr_index] == true)
			continue ;

		selected[arr_index] = true;
		permutation[position] = arr[arr_index];

		findMax(position + 1);

		selected[arr_index] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for(int index = 0; index < N; ++index)
		cin >> arr[index];

	findMax(0);

	cout << sum_max << '\n';

	return (0);
}
