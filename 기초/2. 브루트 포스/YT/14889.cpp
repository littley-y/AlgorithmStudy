#include <iostream>

using namespace std;

int N, lowest = 100;
int team[20][20];
int start[10], link[10];

int calLow() {
  int startSum = 0, linkSum = 0;
  for (int i = 0; i < N / 2; i++) {
    for (int j = i + 1; j < N / 2; j++) {
      startSum += team[start[i]][start[j]] + team[start[j]][start[i]];
      linkSum += team[link[i]][link[j]] + team[link[j]][link[i]];
    }
  }

  return abs(startSum - linkSum);
}

void fillLink() {
  bool visited[20] = {
      0,
  };
  for (int i = 0; i < N / 2; i++) {
    visited[start[i]] = true;
  }

  int idx = 0;
  for (int i = 0; i < N; i++) {
    if (visited[i] == true)
      continue;
    link[idx] = i;
    idx++;
  }
}

void solution(int curr) {
  if (curr == N / 2) {
    fillLink();

    int currLow = calLow();
    if (currLow < lowest)
      lowest = currLow;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (curr > 0 && start[curr - 1] >= i)
      continue;
    start[curr] = i;
    solution(curr + 1);
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