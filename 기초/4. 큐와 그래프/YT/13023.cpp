#include <iostream>
#include <vector>

using namespace std;

vector<int> friends[2000];
bool visited[2000];
int N, M;
bool ans;

void solution(int curr, int cnt) {
  if (cnt == 4) {
    ans = true;
    return;
  }

  for (const auto i : friends[curr]) {
    if (visited[i] == true)
      continue;
    visited[i] = true;
    solution(i, cnt + 1);
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    friends[a].push_back(b);
    friends[b].push_back(a);
  }

  for (int i = 0; i < N; i++) {
    visited[i] = true;
    solution(i, 0);
    visited[i] = false;
    if (ans)
      break;
  }
  cout << ans << '\n';
  return 0;
}