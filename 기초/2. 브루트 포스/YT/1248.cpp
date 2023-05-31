#include <iostream>

using namespace std;

int n;
int ans[10];
char matrix[100][100];

bool isValid(int curr) {
  for (int i = 0; i < curr; i++) {
    int sum = 0;
    for (int j = i; j < curr; j++) {
      sum += ans[j];
      if (matrix[i][j] == '+' && sum <= 0)
        return false;
      else if (matrix[i][j] == '-' && sum >= 0)
        return false;
      else if (matrix[i][j] == '0' && sum != 0)
        return false;
    }
  }
  return true;
}

void solution(int curr) {
  if (curr == n) {
    if (isValid(curr)) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
      exit(0);
    }
  }

  if (matrix[curr][curr] == '+') {
    for (int i = 1; i <= 10; i++) {
      if (isValid(curr) == false)
        continue;
      ans[curr] = i;
      solution(curr + 1);
    }
  } else if (matrix[curr][curr] == '-') {
    for (int i = -10; i < 0; i++) {
      if (isValid(curr) == false)
        continue;
      ans[curr] = i;
      solution(curr + 1);
    }
  } else if (matrix[curr][curr] == '0') {
    ans[curr] = 0;
    solution(curr + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int i = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  solution(0);
  return 0;
}