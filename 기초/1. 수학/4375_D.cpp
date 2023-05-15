#include <iostream>

long long	check_result(long long result)
{
	long long ret = 0;
	while (true)
	{
		if (result == 1)
		{
			ret++;
			break ;
		}

		if (result % 10 != 1)
		{
			ret = -1;
			break ;
		}
		result /= 10;
		ret++;
	}

	return (ret);
}

int main()
{
	long long	n;

	std::cin >> n;

	if (n < 1 || n > 10000 || n % 2 == 0 || n % 5 == 0)
		return (1);

	long long result = n;
	long long ret;

	while (true)
	{
		ret = check_result(result);
		if (ret != -1)
		{
			std::cout << ret << std::endl;
			break ;
		}
		else
		result += n;
	}
	return (0);
}
