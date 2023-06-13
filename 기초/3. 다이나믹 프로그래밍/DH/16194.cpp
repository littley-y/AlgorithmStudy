#include <iostream>

using namespace std;

int N, price[10001], min_price[10001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int index = 1; index <= N; ++index)
    cin >> price[index];

  min_price[1] = price[1];
  for (int index = 2; index <= N; ++index)
  {
    min_price[index] = 2147483647 / 2;
    for (int loop = 1; loop < index; ++loop)
    {
      int now_min = price[index] < min_price[index - loop] + min_price[loop] ? price[index] : min_price[index - loop] + min_price[loop];
      if (now_min < min_price[index])
      {
        min_price[index] = now_min;
      }
    }
  }

  cout << min_price[N] << '\n';

  return (0);
}
