#include <iostream>

using namespace std;

int		N, permutation[8];
bool	visited[9];

void	printPermutation(int position)
{
	if (position == N)
	{
		for (int print = 0; print < N; ++print)
			cout << permutation[print] << ' ';
		cout << '\n';
		return ;
	}

	for (int num = 1; num <= N; ++num)
	{
		if (visited[num] == true)
			continue ;

		permutation[position] = num;
		visited[num] = true;

		printPermutation(position + 1);

		visited[num] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	printPermutation(0);

	return (0);
}
