#include <iostream>
#include <string>

using namespace std;

int		n, ans[10];
char	sign_matrix[10][10];

bool	checkAns(int position)
{
	int sum = 0;

	for (int i = position; i >= 0; i--)
	{
		sum += ans[i];
		if (sign_matrix[i][position] == '-' && sum >= 0)
		{
			return (false);
		}
		else if (sign_matrix[i][position] == '+' && sum <= 0)
		{
			return (false);
		}
		else if (sign_matrix[i][position] == '0' && sum != 0)
		{
			return (false);
		}
	}
	return (true);
}

void	guess(int position)
{
	if (position == n)
	{
		for (int index = 0; index < n; index++)
		{
			cout << ans[index] << ' ';
		}
		exit(0);
	}
	for (int num = -10; num <= 10; ++num)
	{
		ans[position] = num;
		if (checkAns(position))
			guess(position + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int j = 0; j < n; ++j)
	{
		for (int i = j; i < n; i++)
			cin >> sign_matrix[j][i];
	}

	guess(0);

	return (0);
}
