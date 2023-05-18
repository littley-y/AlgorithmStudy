#include <iostream>
#include <set>

using namespace std;

set<int> all_small[9];
int	total_height = 0;

void	print_seven_small(void)
{
	set<int>::iterator	iter = all_small->begin();
	set<int>::iterator	end = all_small->end();

	for (; iter != end; iter++)
	{
		cout << *iter << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int value;
	for (int index = 0; index < 9; index++)
	{
		cin >> value;
		all_small->insert(value);
		total_height += value;
	}

	int over_height = total_height - 100;

	set<int>::iterator	main_iter = all_small->begin();
	set<int>::iterator	end = all_small->end();
	set<int>::iterator	loop_iter;

	for (; main_iter != end; main_iter++)
	{
		loop_iter = main_iter;
		loop_iter++;
		for (; loop_iter != end; loop_iter++)
		{
			if (over_height == *main_iter + *loop_iter)
			{
				all_small->erase(main_iter);
				all_small->erase(loop_iter);
				print_seven_small();
				return (0);
			}
		}
	}

	return (0);
}
