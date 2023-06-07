#include <iostream>

using namespace std;

int N, S, set[20], cnt;

void  find(void)
{
  for (int subset = 1; subset < (1 << N); ++subset)
  {
    int sum = 0;

    for (int index = 0; subset >> index; ++index)
    {
      if ((subset >> index) & 1)
      {
        sum += set[index];
      }
    }

    if (sum == S)
      cnt++;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> S;

  for (int index = 0; index < N; ++index)
    cin >> set[index];

  find();

  cout << cnt << '\n';

  return (0);
}
