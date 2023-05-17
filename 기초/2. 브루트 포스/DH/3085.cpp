/*
	그냥 풀이방법을 모르겠어서 실패했던 케이스

	해당 문제에 대한 자료 찾아보고 로직만 참고

	void	calculate_width(void)은 행에 있는 요소를 교체해서 가로줄 내에 일치하는 최대값을 찾는 것이고
	void	calculate_height(void)은 열에 있는 요소를 교체하는 방식으로 풀이 했으나

	행에 있는 요소를 교체했을 때는 열에 대해서 브루트 포스를 사용하였고 열에 있는 요소에는 행에 대해서만 브루트 포스를 사용하였는데 문제가 있었다.
	생각해보니 행에있는 요소가 서로 다를 경우 행에 대해서도 탐색을 해야하기 때문에 그 점을 놓치고 있었다. 요소 교체 후 모든 요소에 대한 체크를 하니 통과
*/

#include <iostream>

using namespace std;

char	board[51][51];
char	color;
int		cnt, max_cnt = 0;;
int		N;

void	check_width(void)
{
	for (int height = 0; height < N; height++)
	{
		color = board[height][0];
		cnt = 1;

		for (int width = 1; width < N; width++)
		{
			if (color == board[height][width])
				cnt++;
			else
			{
				cnt = 1;
				color = board[height][width];
			}
			if (cnt > max_cnt)
				max_cnt = cnt;
		}
	}
}

void	check_height(void)
{
	for (int width = 0; width < N; width++)
	{
		color = board[0][width];
		cnt = 1;

		for (int height = 1; height < N; height++)
		{
			if (color == board[height][width])
				cnt++;
			else
			{
				cnt = 1;
				color = board[height][width];
			}
			if (cnt > max_cnt)
				max_cnt = cnt;
		}

	}
}

void	check(void)
{
	check_width();
	check_height();
}

void	calculate_width(void)
{
	for (int height = 0; height < N; height++)
	{
		for (int width = 0; width < N - 1; width++)
		{
			swap(board[height][width], board[height][width + 1]);
			check();
			swap(board[height][width], board[height][width + 1]);
		}
	}
}

void	calculate_height(void)
{
	for (int width = 0; width < N; width++)
	{
		for (int height = 0; height < N - 1; height++)
		{
			swap(board[height][width], board[height + 1][width]);
			check();
			swap(board[height][width], board[height + 1][width]);
		}
	}
}


void	calculate(void)
{
	calculate_width();
	calculate_height();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int height = 0; height < N; height++)
		for (int width = 0; width < N; width++)
			cin >> board[height][width];

	calculate();

	cout << max_cnt << "\n";

	return (0);
}
