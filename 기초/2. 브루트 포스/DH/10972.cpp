#include <iostream>

using namespace std;

int		N, permutation[10001], goal[10001];
bool	visited[10001], find_goal;

void	find(int position)
{
	if (position == N + 1)
	{
		if (find_goal == true)
		{
			for (int print = 1; print <= N; ++print)
				cout << permutation[print] << ' ';
			cout << '\n';
			exit(0);
		}

		find_goal = true;
		return ;
	}

	for (int num = 1; num <= N; ++num)
	{
		if (find_goal == false && num < goal[position])
			continue ;

		if (visited[num] == true)
			continue ;

		visited[num] = true;
		permutation[position] = num;

		find(position + 1);

		visited[num] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int loop = 1; loop <= N; ++loop)
		cin >> goal[loop];

	find(1);

	if (find_goal == true)
		cout << -1 << '\n';

	return (0);
}
