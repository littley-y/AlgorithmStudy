#include <iostream>

using namespace std;

const int ARR_MAX = 100001;
int arr[ARR_MAX];
int dp[ARR_MAX];
int n, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  ans = arr[1];
  dp[1] = arr[1];

  for (int i = 2; i <= n; i++) {
    dp[i] = max(arr[i], dp[i - 1] + arr[i]);
    if (ans < dp[i])
      ans = dp[i];
  }

  cout << ans << '\n';

  return 0;
}