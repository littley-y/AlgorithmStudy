#include <iostream>

using namespace std;

int N, price[10001], max_price[10001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int index = 1; index <= N; ++index)
    cin >> price[index];

  max_price[1] = price[1];
  for (int index = 2; index <= N; ++index)
  {
    for (int loop = 1; loop < index; ++loop)
    {
      int now_max = price[index] > max_price[index - loop] + max_price[loop] ? price[index] : max_price[index - loop] + max_price[loop];
      if (now_max > max_price[index])
        max_price[index] = now_max;
    }
  }

  cout << max_price[N] << '\n';

  return (0);
}
