#include <iostream>

using namespace std;

int					N, T, P, max_income = 0, income = 0;
std::pair<int, int>	schedule[15];

void	calculate(int position)
{
	if (income > max_income)
		max_income = income;

	for (; position < N; position++)
	{
		if (position + schedule[position].first > N)
			continue ;

		income += schedule[position].second;

		calculate(position + schedule[position].first);

		income -= schedule[position].second;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int index = 0; index < N; index++)
	{
		cin >> T >> P;
		schedule[index].first = T;
		schedule[index].second = P;
	}

	calculate(0);

	cout << max_income << '\n';

	return (0);
}
