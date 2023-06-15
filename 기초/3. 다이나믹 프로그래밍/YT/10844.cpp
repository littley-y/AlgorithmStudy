#include <iostream>

using namespace std;

const int ARR_MAX = 101;
int N;
long long arr[ARR_MAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  arr[1] = 9;

  for (int i = 2; i <= N; i++) {
    arr[i] = ((arr[i - 1] - (i - 1)) * 2 + i - 1) % 1000000000;
  }
  cout << arr[N] % 1000000000 << "\n";

  return 0;
}

/*
9
1 2 3 4 5 6 7 8
8 + 1

10 89 -> 2
12 23 34 45 56 67 78 21 32 43 54 65 76 87 98 -> 8 * 2 - 1
15 + 2

210 989 789 -> 3
101 121 123 232 234 343 345 454 456 565 567 676 678 787 898
212 321 323 432 434 543 545 654 656 765 767 876 878 987 -> 15 * 2 - 1
29 + 3

끝애자리가 0이나 9로 끝나면 경우의수 1개 추가
그 외 모든 경우는 2개 추가
*/