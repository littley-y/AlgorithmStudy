#include <iostream>

using namespace std;

int		N, cost[11][11], route[11], min_total = 2147483647, start_city, end_city;
bool	visited[11];

void	sumCost(void)
{
	int total = cost[end_city][start_city];
	if (total == 0)
		return ;

	for (int index = 0; index < N - 1; ++index)
	{
		int now_cost  = cost[route[index]][route[index + 1]];
		if (now_cost == 0)
			return ;
		total += now_cost;
	}

	if (total < min_total)
		min_total = total;
}

void	findRoute(int position)
{
	if (position == N)
	{
		sumCost();
		return ;
	}

	for (int width = 0; width < N; ++width)
	{
		if (visited[width] == true)
			continue ;

		if (position == 0)
			start_city = width;

		if (position == N - 1)
			end_city = width;

		visited[width] = true;

		route[position] = width;

		findRoute(position + 1);

		visited[width] = false;

	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int height = 0; height < N; ++height)
	{
		for (int width = 0; width < N; ++width)
			cin >> cost[height][width];
	}

	findRoute(0);

	cout << min_total << '\n';

	return (0);
}
