#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, value, cnt;

	while (cin >> n)
	{
		value = 1;
		cnt = 1;
		while (true)
		{
			if (value % n == 0)
				break ;

			value = (value * 10 + 1) % n;
			cnt++;
		}
		cout << cnt << "\n";
	}
	return (0);
}
