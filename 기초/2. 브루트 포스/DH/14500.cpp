#include <iostream>

using namespace std;

int N, M, max_sum = 0, tmp_max_sum, board[501][501];

void case1(int height, int width)
{

	if (width + 3 <= M)
	{
		tmp_max_sum = 0;
		for (int loop = width; loop <= width + 3; loop++)
			tmp_max_sum += board[height][loop];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}

	if (height + 3 <= N)
	{
		tmp_max_sum = 0;
		for (int loop = height; loop <= height + 3; loop++)
			tmp_max_sum += board[loop][width];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}
}

void case2(int height, int width)
{
	if (height + 1 <= N && width + 1 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height + 1][width] + board[height + 1][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
 	}
}

void case3(int height, int width)
{
	if (height + 1 <= N && width + 2 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height][width + 2] + board[height + 1][width];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height][width + 2] + board[height + 1][width + 2];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height + 1][width] +
						board[height + 1][width + 1] + board[height + 1][width + 2];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width + 2] + board[height + 1][width] +
						board[height + 1][width + 1] + board[height + 1][width + 2];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}

	if (height + 2 <= N && width + 1 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height + 1][width] + board[height + 2][width];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height + 1][width + 1] + board[height + 2][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height + 1][width] +
						board[height + 2][width] + board[height + 2][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width + 1] + board[height + 1][width + 1] +
						board[height + 2][width + 1] + board[height + 2][width];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}
}

void case4(int height, int width)
{
	if (height + 1 <= N && width + 2 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height + 1][width + 1] + board[height + 1][width + 2];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height + 1][width] + board[height + 1][width + 1] +
						board[height][width + 1] + board[height][width + 2];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}

	if (height + 2 <= N && width + 1 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height + 1][width] +
						board[height + 1][width + 1] + board[height + 2][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width + 1] + board[height + 1][width + 1] +
						board[height + 1][width] + board[height + 2][width];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}
}

void case5(int height, int width)
{
	if (height + 1 <= N && width + 2 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height][width + 1] +
						board[height][width + 2] + board[height + 1][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height + 1][width] + board[height + 1][width + 1] +
						board[height + 1][width + 2] + board[height][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}

	if (height + 2 <= N && width + 1 <= M)
	{
		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width] + board[height + 1][width] +
						board[height + 2][width] + board[height + 1][width + 1];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;

		tmp_max_sum = 0;
		tmp_max_sum =	board[height][width + 1] + board[height + 1][width + 1] +
						board[height + 2][width + 1] + board[height + 1][width];

		if (tmp_max_sum > max_sum)
			max_sum = tmp_max_sum;
	}
}

void	find_max(void)
{
	for (int height = 1; height <= N; height++)
	{
		for (int width = 1; width <= M; width++)
		{
			case1(height, width); 	// ㅁㅁㅁㅁ

			case2(height, width); 	// ㅁㅁ
									// ㅁㅁ

			case3(height, width);	// ㅁㅁㅁ
									//    ㅁ

			case4(height, width);	// ㅁㅁ
									//   ㅁㅁ

			case5(height, width);	// ㅁㅁㅁ
									//  ㅁ
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int height = 1; height <= N; height++)
		for (int width = 1; width <= M; width++)
			cin >> board[height][width];

	find_max();

	cout << max_sum << "\n";

	return (0);
}
