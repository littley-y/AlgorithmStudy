#include <iostream>
#include <vector>

using namespace std;

int 		N, ability_board[21][21], ability_min = 2147483647;
bool		selected[21];
vector<int> team_start;
int			team_start_ability = 0, team_link_ability = 0;

int		sumAbility(bool select)
{
	int sum = 0;

	for (int height = 1; height <= N; ++height)
	{
		for (int width = 1; width <= N; ++width)
		{
			if (selected[height] == select && selected[width] == select)
			{
				sum += ability_board[height][width];
			}
		}
	}

	return (sum);
}

void	calculateTeamStart()
{
	team_start_ability = sumAbility(true);
}

void	calculateTeamLink()
{
	vector<int> team_link;

	for (int member = 1; member <= N; member++)
	{
		if (selected[member] == true)
			continue ;
		team_link.push_back(member);
	}

	team_link_ability = sumAbility(false);
}

void	findMin(int member_index)
{
	if (member_index == N / 2)
	{
		calculateTeamStart();
		calculateTeamLink();

		int diff;
		diff = abs(team_start_ability - team_link_ability);
		if (diff < ability_min)
		{
			ability_min = diff;
		}
		return ;
	}

	for (int member = 1; member <= N; member++)
	{
		if (member_index > 0 && team_start[member_index - 1] >= member)
			continue ;

		selected[member] = true;
		team_start.push_back(member);

		findMin(member_index + 1);

		selected[member] = false;
		team_start.pop_back();

		if (member_index == 0)
			return ;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int S;
	for (int height = 1; height <= N; ++height)
	{
		for (int width = 1; width <= N; ++width)
		{
			cin >> S;
			ability_board[height][width] = S;
		}
	}

	findMin(0);

	cout << ability_min << '\n';

	return (0);
}
