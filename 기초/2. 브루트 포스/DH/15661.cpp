#include <iostream>
#include <cmath>

using namespace std;

int		N, ability_board[21][21], team_start[21], ability_min = 2147483647;
bool	selected[21];

int	calculate(void)
{
	int start_sum = 0, link_sum = 0;

	for (int height = 1; height <= N; ++height)
	{
		for (int width = 1; width <= N; ++width)
		{
			if (selected[height] == true && selected[width] == true)
			{
				start_sum += ability_board[height][width];
			}
			else if (selected[height] == false && selected[width] == false)
			{
				link_sum += ability_board[height][width];
			}
		}
	}
	return (abs(start_sum - link_sum));
}

void findMin(int num_of_member)
{
	bool check = false;

	if (num_of_member == N)
		return ;

	if (num_of_member > 0)
	{
		int diff = abs(calculate());

		if (diff < ability_min)
			ability_min = diff;
	}

	for (int member = num_of_member + 1; member <= N; ++member)
	{
		if (num_of_member > 0 && team_start[num_of_member - 1] >= member)
			continue ;

		selected[member] = true;
		team_start[num_of_member] = member;
		findMin(num_of_member + 1);

		selected[member] = false;

		if (num_of_member == 0)
			return ;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int height = 1; height <= N; ++height)
	{
		for (int width = 1; width <= N; ++width)
		{
			cin >> ability_board[height][width];
		}
	}

	findMin(0);

	cout << ability_min << '\n';

	return (0);
}
