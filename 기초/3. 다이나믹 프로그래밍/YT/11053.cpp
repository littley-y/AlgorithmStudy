/*
길이가 1일때는 무조건 1.
길이가 2일때 arr[2] > arr[1]이면 최대값 2. 아니면 1.
길이가 3일때 arr[3] > arr[2]이고 이전 최대값이 2이면 최대값 3.
            arr[3] > arr[1]이고 1에서의 최대값이 1이면 최대값 2.
            아니면 그냥 1.

결과값은 현재 저장된 최대값과 dp[i] 값중 큰 값
*/

#include <iostream>

using namespace std;

int A, ans;
int arr[1001];
int dp[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> A;
  for (int i = 1; i <= A; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= A; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(dp[i], ans);
  }

  cout << ans << '\n';
  return 0;
}
