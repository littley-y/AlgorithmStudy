#include <iostream>

using namespace std;

int N;
int team[20][20];
int lowest = 2147483647;
bool visited[20];
int start[20];

int calLow(int curr) {
  int idx = 0, link[20] = {
                   0,
               };

  for (int i = 0; i < N; i++) {
    if (visited[i] == true)
      continue;
    link[idx] = i;
    idx++;
  }

  int startSum = 0, linkSum = 0;
  if (curr == 1) {
    startSum = team[start[0]][start[0]];
  } else {
    for (int i = 0; i < curr; i++) {
      for (int j = i + 1; j < curr; j++) {
        startSum += team[start[i]][start[j]] + team[start[j]][start[i]];
      }
    }
  }

  if (idx == 1) {
    linkSum = team[link[0]][link[0]];
  } else {
    for (int i = 0; i < idx; i++) {
      for (int j = i + 1; j < idx; j++) {
        linkSum += team[link[i]][link[j]] + team[link[j]][link[i]];
      }
    }
  }

  return abs(startSum - linkSum);
}

void solution(int curr) {
  if (curr > 1 && N - curr > 1) {
    int currLow = calLow(curr);
    if (currLow < lowest)
      lowest = currLow;
  }

  for (int i = 0; i < N; i++) {
    if (curr > 0 && start[curr - 1] >= i)
      continue;
    visited[i] = true;
    start[curr] = i;
    solution(curr + 1);
    visited[i] = false;
    if (curr == 0)
      return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> team[i][j];
    }
  }

  solution(0);
  cout << lowest << '\n';

  return 0;
}