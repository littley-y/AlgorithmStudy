#include <iostream>
#include <string>

#define LENGTH true;
#define WIDTH false;

using namespace std;

int   N, M, max_sum = 0, board[4][4];


void  find(void)
{
  for (int bitset = 0; bitset < (1 << N * M); ++bitset)
	{
		int sum = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if ((bitset & (1 << (i * M + j))) == 0)
				{
					int num = 0;
					while (j < M && (bitset & (1 << (i * M + j))) == 0)
					{
						num *= 10;
						num += board[i][j];
						++j;
					}
					sum += num;
				}
			}
		}

		for (int j = 0; j < M; ++j)
		{
			for (int i = 0; i < N; ++i)
			{
				if ((bitset & (1 << (i * M + j))) != 0)
				{
					int num = 0;
					while (i < N && (bitset & (1 << (i * M + j))) != 0)
					{
						num *= 10;
						num += board[i][j];
						++i;
					}
					sum += num;
				}
			}
		}

    if (sum > max_sum)
      max_sum = sum;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      char tmp;
      cin >> tmp;
      board[i][j] = tmp - '0';
    }
  }

  find();

  cout << max_sum << '\n';

  return 0;
}
