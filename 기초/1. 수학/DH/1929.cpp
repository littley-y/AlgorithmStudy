#include <iostream>

using namespace std;

int	M, N, cnt = 0;
int Prime[1000001];

void	getPrime(void)
{
	for (int index = 2; index <= 1000000; index++)
		for (int pos = index; pos <= 1000000; pos += index)
		{
			Prime[pos] += index;
		}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	getPrime();

	cin >> M >> N;

	for (; M <= N; M++)
	{
		if (Prime[M] == M)
			cout << M << "\n";
	}

	return (0);
}
