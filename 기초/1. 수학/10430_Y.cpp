#include <iostream>

using namespace std;

int A, B, C;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> A >> B >> C;
  cout << (A + B) % C << '\n';
  cout << ((A % C) + (B % C)) % C << '\n';
  cout << (A * B) % C << '\n';
  cout << ((A % C) * (B % C)) % C << '\n';
}