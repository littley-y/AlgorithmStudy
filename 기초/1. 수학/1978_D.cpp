#include <iostream>

using namespace std;

int	N, input, cnt = 0;
int Prime[1001];

void	getPrime(void)
{
	for (int index = 2; index <= 1000; index++)
		for (int pos = index; pos <= 1000; pos += index)
		{
			Prime[pos] += index;
		}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	getPrime();

	cin >> N;

	for (; N; N--)
	{
		cin >> input;
		if (Prime[input] == input)
			cnt++;
	}

	cout << cnt << "\n";
	return (0);
}
