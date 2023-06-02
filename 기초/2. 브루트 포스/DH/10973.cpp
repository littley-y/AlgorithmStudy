#include <iostream>

using namespace std;

int		N, goal[10001], permutation[10001];
bool	visited[10001], find_goal;

void	findPrev(int position)
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

	for (int num = N; num > 0; --num)
	{
		if (find_goal == false && goal[position] < num)
			continue ;

		if (visited[num] == true)
			continue ;

		permutation[position] = num;
		visited[num] = true;

		findPrev(position + 1);

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

	findPrev(1);

	if (find_goal == true)
		cout << -1 << '\n';

	return (0);
}
