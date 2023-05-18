#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int		channel = 100, N, M, click = 0;
int		wrong_button[10];

bool	is_wrong(string now)
{
	for (int index = 0; index < 10; index++)
	{
		if (wrong_button[index] == 1)
		{
			char char_index = index + '0';
			if (string::npos != now.find(char_index))
				return (false);
		}
	}
	return (true);
}

void	find_channel(void)
{
	click = abs(N - channel);

	// if (click < 4)
	// 	return ;

	int now_click;

	int max = pow(10, to_string(N).length() + 1);

	for (int now = 0; now <= max; now++)
	{
		if(is_wrong(to_string(now)))
		{
			now_click = abs(now - N) + to_string(now).length();
			if (now_click < click)
				click = now_click;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cin >> M;

	int temp;

	while (M)
	{
		cin >> temp;
		wrong_button[temp] = 1;
		M--;
	}

	find_channel();

	cout << click << "\n";

	return (0);
}
