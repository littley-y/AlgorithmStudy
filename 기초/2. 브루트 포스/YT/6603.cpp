#include <iostream>
#include <vector>

using namespace std;

int k;

void solution(vector<int> &numbers, vector<int> &ans, int curr) {
  if (curr == 6) {
    for (int i = 0; i < 6; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < k; i++) {
    if (curr > 0 && ans[curr - 1] >= numbers[i])
      continue;
    ans[curr] = numbers[i];
    solution(numbers, ans, curr + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  while (k) {
    vector<int> numbers(k);
    vector<int> ans(6);
    for (int i = 0; i < k; i++) {
      cin >> numbers[i];
    }
    solution(numbers, ans, 0);
    cout << '\n';
    cin >> k;
  }

  return 0;
}