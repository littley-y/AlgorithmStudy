#include <iostream>

using namespace std;

int input, prime_index = 0;;
int	all[1000001];
int Prime[1000001];

void	getPrime(void)
{
	for (int index = 3; index <= 1000000; index += 2)
	{
		for (int pos = index; pos <= 1000000; pos += index)
			all[pos] += index;
		if (all[index] == index)
		{
			Prime[prime_index] = index;
			prime_index++;
		}

	}
}

void	checkGoldBach(void)
{
	for (int index = 0; Prime[index] < input; index++)
	{
		for (int tmp = index + 1; Prime[tmp] < input; tmp++)
		{
			if (input - Prime[index] - Prime[tmp] == 0)
			{
				cout << input << " = " << Prime[index] << " + " << Prime[tmp] << "\n";
				return ;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	getPrime();

	while(cin >> input)
	{
		if (input == 0)
			break ;

		checkGoldBach();
	}

	return (0);
}
