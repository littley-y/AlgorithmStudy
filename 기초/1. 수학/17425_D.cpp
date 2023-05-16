#include <iostream>

using namespace std;

long long calculated[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int num = 1; num <= 1000001; num++)
		for(int pos = num; pos <= 1000001; pos += num)
			calculated[pos] += num;

	for (int pos = 2; pos <= 1000001; pos++)
		calculated[pos] += calculated[pos - 1];

	long long	N, T;

	cin >> T;

	while (T)
	{
		cin >> N;
		cout << calculated[N] << "\n";
		T--;
	}
	return (0);
}
