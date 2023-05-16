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

bool	isPrime(int num)
{
	for (int index = 0; Prime[index] <= num; index++)
	{
		if (Prime[index] == num)
			return (true);
	}
	return (false);
}

void	checkGoldBach(void)
{
	int second;

	for (int index = 0; Prime[index] < input; index++)
	{
		second = input - Prime[index];
		if (isPrime(second))
		{
			cout << input << " = " << Prime[index] << " + " << second << "\n";
			return ;
		}
	}
	cout << "Goldbach's conjecture is wrong." << "\n";
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
