#include <iostream>
#include <set>
#include <vector>

using namespace std;

int 			L, C, vowels_count = 0;;
char			vowels[] = {'a', 'e', 'i', 'o', 'u'};
set<char>		password_pool;
vector<char>	password;

bool	isVowels(char value)
{
	for (int index = 0; vowels[index]; index++)
	{
		if (value == vowels[index])
			return true;
	}
	return (false);
}

void	findPassword(set<char>::iterator iter, int position)
{
	int size = password.size();

	if (size == L && vowels_count > 0 && abs(L - vowels_count) >= 2)
	{
		for (int print_index = 0; print_index < size; print_index++)
			cout << password[print_index];
		cout << '\n';
		return ;
	}
	else if (size == L)
		return ;

	auto end = password_pool.end();
	char tmp;

	for (; iter != end; iter++)
	{
		if (position > 0 && password[position - 1] >= *iter)
			continue ;

		password.push_back(*iter);

		if (isVowels(*iter))
			vowels_count++;

		iter++;
		position++;

		findPassword(iter, position);

		tmp = password.back();
		password.pop_back();
		if (isVowels(tmp))
			vowels_count--;

		iter--;
		position--;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	char tmp;
	while (C)
	{
		cin >> tmp;
		password_pool.insert(tmp);
		C--;
	}

	findPassword(password_pool.begin(), 0);

	return(0);
}
