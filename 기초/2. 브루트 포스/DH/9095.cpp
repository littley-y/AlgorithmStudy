
// 다이나믹 프로그래밍
#include <iostream>

using namespace std;

int	test_case, n, arr[11];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int arr_index = 4; arr_index < 11; arr_index++)
		arr[arr_index] = arr[arr_index - 1] + arr[arr_index - 2] + arr[arr_index - 3];

	cin >> test_case;

	while(test_case)
	{
		cin >> n;
		cout << arr[n] << '\n';
		test_case--;
	}

	return (0);
}

// 백트래킹
#include <iostream>

using namespace std;

int	test_case, n, sum_case, arr[10];

int	sumAll(void)
{
	int sum = 0;

	for (int arr_index = 0; arr[arr_index]; arr_index++)
		sum += arr[arr_index];
	return (sum);
}

void	backtracking(int curr)
{
	if (sumAll() == n)
	{
		sum_case++;
		return ;
	}

	for (int num = 1; num <= 3; num++)
	{
		arr[curr] = num;
		if (sumAll() <= n)
		{
			backtracking(curr + 1);
			arr[curr] = 0;
		}
		else
		{
			arr[curr] = 0;
			return ;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> test_case;

	while(test_case)
	{
		cin >> n;
		sum_case = 0;
		backtracking(0);
		cout << sum_case << '\n';
		test_case--;
	}

	return (0);
}
