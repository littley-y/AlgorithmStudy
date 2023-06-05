#include <iostream>

using namespace std;

int		k, lottoSet[14], permutation[14];
bool	visited[14];

void	print(int position)
{
	if (position == 6)
	{
		for (int print = 0; print < 6; ++print)
			cout << permutation[print] << ' ';
		cout << '\n';
		return ;
	}

	for (int index = 0; index < k; ++index)
	{
		if (position > 0 && permutation[position - 1] > lottoSet[index])
			continue ;

		if (visited[index] == true)
			continue ;

		visited[index] = true;

		permutation[position] = lottoSet[index];

		print(position + 1);

		visited[index] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> k;
		if (k == 0)
			break ;

		for  (int index = 0; index < k; ++index)
			cin >> lottoSet[index];

		print(0);
		cout << '\n';
	}

	return (0);
}
