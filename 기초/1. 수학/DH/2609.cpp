#include <iostream>

using namespace std;

int	first, second, greatest_common_divisor, lowest_common_multiple;

void getGreatestCommonDivisor(void)
{
	int max = first > second ? first : second;

	for (int index = max; index > 0; index--)
	{
		if (first % index == 0 && second % index == 0)
		{
			greatest_common_divisor = index;
			cout << greatest_common_divisor << "\n";
			return ;
		}
	}

}

void getLowestCommonMultiple(void)
{
	lowest_common_multiple = greatest_common_divisor * (first / greatest_common_divisor) * (second / greatest_common_divisor);

	cout << lowest_common_multiple << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> first >> second;

	getGreatestCommonDivisor();
	getLowestCommonMultiple();

	return (0);
}
