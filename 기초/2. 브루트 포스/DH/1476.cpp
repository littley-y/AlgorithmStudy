/*
	1 ≤ E ≤ 15
	1 ≤ S ≤ 28
	1 ≤ M ≤ 19
*/

#include <iostream>

using namespace std;

int	earth, sun, moon, year = 0;

void	calculate_date(void)
{
	while (1)
	{
		earth--;
		sun--;
		moon--;
		year++;

		if (earth == 0 && sun == 0 && moon == 0)
			return ;

		if (earth == 0)
			earth = 15;

		if (sun == 0)
			sun = 28;

		if (moon == 0)
			moon = 19;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> earth;
	cin >> sun;
	cin >> moon;

	calculate_date();

	cout << year << "\n";

	return (0);
}
