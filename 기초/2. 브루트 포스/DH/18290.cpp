#include <iostream>

using namespace std;

int		N, M, K, basic_board[10][10], selected = 0, max_sum = -40000, sum = 0;
bool	selected_board[10][10] = {false, };

bool	check_nearby(int y , int x)
{
	if (selected_board[y][x] == true)
		return (true);

	if (x + 1 < M)
	{
		if (selected_board[y][x + 1] == true)
			return (true);
	}

	if (y + 1 < N)
	{
		if (selected_board[y + 1][x] == true)
			return (true);
	}

	if (y - 1 >= 0)
	{
		if (selected_board[y - 1][x] == true)
			return (true);
	}

	if (x - 1 >= 0)
	{
		if (selected_board[y][x - 1] == true)
			return (true);
	}

	return (false);
}

void	backtracking(int y, int x)
{
	if (selected == K)
	{
		if (sum > max_sum)
			max_sum = sum;
		return ;
	}

	for (int height = y; height < N; height++)
	{
		for (int width = x; width < M; width++)
		{
			if (check_nearby(height, width))
				continue ;

			selected_board[height][width] = true;
			sum += basic_board[height][width];
			selected++;

			if (x + 1 < M)
				backtracking(y, x + 1);
			else
				backtracking(y + 1, 0);

			sum -= basic_board[height][width];
			selected_board[height][width] = false;
			selected--;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int height = 0; height < N; height++)
	{
		for (int width = 0; width < M; width++)
		{
			int tmp;

			cin >> tmp;
			basic_board[height][width] = tmp;
		}
	}

	backtracking(0, 0);

	cout << max_sum << '\n';

	return (0);
}
