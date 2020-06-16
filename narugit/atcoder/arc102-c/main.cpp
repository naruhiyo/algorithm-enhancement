#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;

  ll a = N / K;
  ll b = (N + K / 2) / K;

  cout << (K % 2 == 0 ? a * a * a + b * b * b : a * a * a) << endl;

  return 0;
}
