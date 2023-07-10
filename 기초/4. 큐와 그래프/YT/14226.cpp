#include <iostream>
#include <queue>

using namespace std;

int S;
int visited[2000][2000];
queue<pair<int, int>> que;

void BFS() {
  visited[1][0] = 1;
  que.push({1, 0});

  while (true) {
    int now = que.front().first;
    int clip = que.front().second;
    que.pop();

    if (now == S) {
      cout << visited[now][clip] - 1 << '\n';
      break;
    }

    int nextClip = now;
    if (visited[now][nextClip] == 0) {
      que.push({now, nextClip});
      visited[now][nextClip] = visited[now][clip] + 1;
    }
    if (now + clip <= S && visited[now + clip][clip] == 0) {
      que.push({now + clip, clip});
      visited[now + clip][clip] = visited[now][clip] + 1;
    }
    if (now > 0 && visited[now - 1][clip] == 0) {
      que.push({now - 1, clip});
      visited[now - 1][clip] = visited[now][clip] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> S;

  BFS();

  return 0;
}