#include <iostream>

using namespace std;

int	M, N, x, y, T, year;

void	calculate_date(void)
{
	int	min_xy, min_MN, loop_M = M, loop_N = N;
	year = 0;

	while (1)
	{
		min_xy = x > y ? y : x;
		min_MN = loop_M > loop_N ? loop_N : loop_M;

		// cout<< "<" << x << ":" << y << ">" << "\n";

		x -= min_xy;
		y -= min_xy;

		year += min_xy;

		if (x == 0 && y == 0)
			break ;

		if (x == 0)
			x = M;

		if (y == 0)
			y = N;

		loop_M -= min_MN;
		loop_N -= min_MN;

		if (loop_M == 0 && loop_N == 0)
		{
			year = -1;
			break ;
		}

		if (loop_M == 0)
			loop_M = M;

		if (loop_N == 0)
			loop_N = N;
	}
	cout << year << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T)
	{
		cin >> M >> N >> x >> y;
		if(M == N)
			std::cout<<(x == y ? x : -1)<<'\n';
		else
			calculate_date();
		--T;
	}

	return (0);
}
