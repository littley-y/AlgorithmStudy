#include <iostream>
#include <set>
#include <vector>

using namespace std;

int			N, M;
set<int>	my_set;
vector<int>	my_vector;

void	backtracking(int position)
{
	if (position == M)
	{
		for (int print_index = 0; print_index < position; print_index++)
			cout << my_vector[print_index] << ' ';
		cout << '\n';
		return ;
	}

	auto	iter = my_set.begin();
	auto	end = my_set.end();

	for (; iter != end; iter++)
	{
		if (position > 0 && my_vector[position - 1] >= *iter)
			continue ;
		my_vector.push_back(*iter);
		backtracking(position + 1);
		my_vector.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	while (N)
	{
		int tmp;
		cin >> tmp;
		my_set.insert(tmp);
		N--;
	}

	backtracking(0);

	return (0);
}
