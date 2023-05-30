#include <iomanip>
#include <iostream>

using namespace std;

int K;
string ans;
char unequal[9];
bool visited[10];
long long maxNum = 0, minNum = 9223372036854775807;

bool isValid(int curr, int i) {
  if (curr == 0)
    return true;
  if (unequal[curr - 1] == '>' && ans[curr - 1] - '0' < i)
    return false;
  if (unequal[curr - 1] == '<' && ans[curr - 1] - '0' > i)
    return false;
  return true;
}

void solution(int curr) {
  if (curr == K + 1) {
    long long num = stoll(ans);
    if (num > maxNum)
      maxNum = num;
    if (num < minNum)
      minNum = num;
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (visited[i] == true || isValid(curr, i) == false)
      continue;
    visited[i] = true;
    ans.push_back(i + '0');
    solution(curr + 1);
    visited[i] = false;
    ans.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> unequal[i];
  }

  solution(0);

  cout << setw(K + 1) << setfill('0') << maxNum << '\n';
  cout << setw(K + 1) << setfill('0') << minNum << '\n';

  return 0;
}