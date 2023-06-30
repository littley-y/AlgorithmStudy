#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<string> map;
vector<int> house;

void BFS(int x, int y) {
  queue<pair<int, int>> Q;
  Q.push(make_pair(x, y));
  map[y][x] = '0';

  while (!Q.empty()) {
    int cx = Q.front().first;
    int cy = Q.front().second;
    Q.pop();
    ++house.back();

    if (cx > 0 && map[cy][cx - 1] == '1') {
      map[cy][cx - 1] = '0';
      Q.push(make_pair(cx - 1, cy));
    }
    if (cx < N - 1 && map[cy][cx + 1] == '1') {
      map[cy][cx + 1] = '0';
      Q.push(make_pair(cx + 1, cy));
    }
    if (cy > 0 && map[cy - 1][cx] == '1') {
      map[cy - 1][cx] = '0';
      Q.push(make_pair(cx, cy - 1));
    }
    if (cy < N - 1 && map[cy + 1][cx] == '1') {
      map[cy + 1][cx] = '0';
      Q.push(make_pair(cx, cy + 1));
    }
  }
}

void DFS(int x, int y) {
  map[y][x] = '0';
  ++house.back();

  if (x > 0 && map[y][x - 1] == '1')
    DFS(x - 1, y);
  if (x < N - 1 && map[y][x + 1] == '1')
    DFS(x + 1, y);
  if (y > 0 && map[y - 1][x] == '1')
    DFS(x, y - 1);
  if (y < N - 1 && map[y + 1][x] == '1')
    DFS(x, y + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    map.push_back(tmp);
  }

  for (int b = 0; b < N; b++) {
    for (int a = 0; a < N; a++) {
      if (map[b][a] == '1') {
        house.push_back(0);
        BFS(a, b);
      }
    }
  }

  sort(house.begin(), house.end());
  cout << house.size() << '\n';
  for (int i = 0; i < house.size(); i++) {
    cout << house[i] << '\n';
  }

  return 0;
}