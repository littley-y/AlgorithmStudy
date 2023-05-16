#include <iostream>

using namespace std;

long long fg(long long A)
{
	long long index = 1, ret = 0;

	while (A != index)
	{
		ret += index * (A / index);
		index++;
	}
	ret += index * (A / index);

	return (ret);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long	N;

	cin >> N;

	cout << fg(N) << endl;
	return (0);
}
