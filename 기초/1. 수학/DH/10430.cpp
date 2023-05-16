#include <iostream>

int main()
{
	int A, B ,C;

	std::cin >> A >> B >> C;

	if (A < 2 || B < 2 || C < 2 ||
		A > 10000 || B > 10000 || C > 10000)
		return (-1);

	std::cout	<< (A + B) % C << "\n"
				<< ((A % C) + (B % C)) % C << "\n"
				<< (A * B) % C << "\n"
				<< ((A % C) * (B % C)) % C << std::endl;

	return (0);
}
