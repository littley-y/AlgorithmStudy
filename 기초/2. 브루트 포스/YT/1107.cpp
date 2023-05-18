#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int near = 10000000;
string broken;

int calCnt(int num) {
  int tmp = num / 10;
  int cnt = 1;

  while (tmp) {
    tmp /= 10;
    cnt++;
  }
  return cnt;
}

void findNear() {
  int maxNum = pow(10, calCnt(N));

  for (int i = 0; i <= maxNum; i++) {
    string tmp = to_string(i);
    size_t j = 0;
    for (; j < tmp.size(); j++) {
      if (broken.find(tmp[j]) != string::npos)
        break;
    }
    if (j != tmp.size())
      continue;
    if (abs(N - i) < abs(N - near))
      near = i;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  broken.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> broken[i];
  }

  int ngd = abs(N - 100);
  if (ngd < 4) {
    cout << ngd << '\n';
    return 0;
  }

  findNear();
  int cal = abs(near - N) + calCnt(near);

  cout << (ngd < cal ? ngd : cal) << '\n';
  return 0;
}