#include <iostream>
#include <queue>

using namespace std;

int S, min_time[1001][1001];
queue<pair<int, int> > que;

void  bfs() {
  que.push({1, 0});
  min_time[1][0] = true;

  pair<int, int> curr;
  int time, screen, clipboard;
  while (!que.empty()) {
    curr = que.front();
    que.pop();

    screen = curr.first;
    clipboard = curr.second;
    time = min_time[screen][clipboard];

    if (screen == S) {
      cout << min_time[screen][clipboard] - 1 << '\n';
      return ;
    }

    if (!min_time[screen][screen]) {
      min_time[screen][screen] = time + 1;
      que.push({screen, screen});
    }

    if (screen + clipboard <= S && !min_time[screen + clipboard][clipboard]) {
      min_time[screen + clipboard][clipboard] = time + 1;
      que.push({screen + clipboard, clipboard});
    }

    if (screen > 0 && !min_time[screen - 1][clipboard]) {
      min_time[screen - 1][clipboard] = time + 1;
      que.push({screen - 1, clipboard});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  bfs();

  return (0);
}
