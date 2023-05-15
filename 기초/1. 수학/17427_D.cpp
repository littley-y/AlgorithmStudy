#include <iostream>

int f(int A)
{
	int index = 1, ret = 0;

	while (A != index)
	{
		if (A % index == 0)
			ret += index;
		index++;
	}
	ret += index;

	return (ret);
}

int g(int x)
{
	int ret = 0;

	while (x)
	{
		ret += f(x);
		x--;
	}

	return (ret);
}

int main()
{
	int	N;

	std::cin >> N;

	if (N < 1 || N > 1000000)
		return (1);

	std::cout << g(N) << std::endl;
	return (0);
}
