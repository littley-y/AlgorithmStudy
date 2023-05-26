#include <iostream>

using namespace std;

int L, C;
char word[16];
char ans[16];

int isValid() {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < L; i++) {
    if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' ||
        ans[i] == 'u')
      cnt1++;
    else
      cnt2++;
  }
  if (cnt1 >= 1 && cnt2 >= 2)
    return true;
  else
    return false;
}

void solution(int curr) {
  if (curr == L) {
    if (isValid()) {
      for (int i = 0; i < L; i++) {
        cout << ans[i];
      }
      cout << '\n';
    }
    return;
  }

  for (int i = 0; i < C; i++) {
    if (curr > 0 && word[i] <= ans[curr - 1])
      continue;
    ans[curr] = word[i];
    solution(curr + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;
  for (int i = 0; i < C; i++) {
    cin >> word[i];
  }

  for (int i = 0; i < C; i++) {
    for (int j = i + 1; j < C; j++) {
      if (word[i] > word[j]) {
        char tmp = word[i];
        word[i] = word[j];
        word[j] = tmp;
      }
    }
  }

  solution(0);

  return 0;
}