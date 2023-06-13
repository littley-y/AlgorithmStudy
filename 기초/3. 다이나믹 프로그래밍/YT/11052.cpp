/*
DP는 손으로 직접 쓰면서 해보는게 가장 좋은 방법인듯..
만약 4개를 살 때 경우의 수를 작성해보면

price[1] + 3개 살떄 최대값
price[2] + 2개 살때 최대값
price[3] + 1개 살때 최대값
price[4];

이렇게 나온다. 이를 토대로 점화식을 세워보자.
*/

#include <iostream>

using namespace std;

int N;
int price[1001];
int arr[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> price[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      // 바로 전의 계산 값과, 현재의 경우 중 큰 쪽이 현재 값이 된다.
      arr[i] = max(arr[i], arr[i - j] + price[j]);
    }
  }
  cout << arr[N] << '\n';

  return 0;
}
