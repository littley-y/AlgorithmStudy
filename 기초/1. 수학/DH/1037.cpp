#include <iostream>

int main()
{
	int count;

	std::cin >> count;

	if (count < 0 || count > 50)
		return (1);

	int A, min = 1000000, max = 2;

	while (count)
	{
		std::cin >> A;

		if (A < 2 || A > 1000000)
			return (1);

		if (A > max)
			max = A;

		if (A < min)
			min = A;

		count--;
	}
	std::cout << min * max << std::endl;
	return (0);
}
