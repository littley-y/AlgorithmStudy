#include <iostream>
#include <vector>

using namespace std;

vector<int>	vec;
int			N, M;
bool		visit_check[8] = {false, };

void	backtracking()
{
	int size = vec.size();

	if (size == M)
	{
		for (int print_index = 0; print_index < size; print_index++)
			cout << vec[print_index] << ' ';
		cout << '\n';
		return ;
	}

	for (int index = 1; index <= N; index++)
	{
		vec.push_back(index);
		backtracking();
		vec.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	backtracking();

	return (0);
}
