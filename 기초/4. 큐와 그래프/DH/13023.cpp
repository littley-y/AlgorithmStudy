#include <iostream>
#include <vector>

using namespace std;

vector<int> people[2000];
bool        visited[2000];

int N, M;

void  find(int people_index, int position) {
  if (position == 4) {
    cout << 1 << '\n';
    exit(0);
  }

  visited[people_index] = true;

  for (int index = 0; index < people[people_index].size(); ++index) {
    if (!visited[people[people_index][index]]) {
      find(people[people_index][index], position + 1);
    }
  }

  visited[people_index] = false;

}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  int a, b;
  for (int index = 0; index < M; ++index) {
    cin >> a >> b;
    people[a].push_back(b);
    people[b].push_back(a);
  }

  for (int people_index = 0; people_index < N; ++people_index) {
    find(people_index, 0);
  }

  cout << 0 << '\n';

  return (0);
}
