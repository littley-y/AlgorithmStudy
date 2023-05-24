#include <iostream>
#include <vector>

using namespace std;

int			N, M;
vector<int>	vec;
bool		visit_arr[9] = {false, };

void backtracking()
{
	if (vec.size() == M)
	{
		for (int vec_index = 0; vec_index < vec.size(); vec_index++)
			cout << vec[vec_index] << ' ';
		cout << '\n';
		return ;
	}

	for (int index = 1; index <= N; index++)
	{
		if (visit_arr[index] == false)
		{
			visit_arr[index] = true;
			vec.push_back(index);
			backtracking();
			visit_arr[index] = false;
			vec.pop_back();
		}
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
