#include <iostream>

using namespace std;

int N, result = 0, digits = 1;

void	calculate(void)
{
	int index = 10;
	while(1)
	{
		if (N < index)
		{
			result += (N - (index / 10 - 1)) * digits;
			break ;
		}
		else
			result += 9 * (index / 10) * digits;
		digits++;
		index *= 10;
	}
	cout << result << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	calculate();

	return 0;
}
