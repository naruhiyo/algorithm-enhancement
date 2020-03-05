#include <bits/stdc++.h>
#define repeat(i, n) for (ll(i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long ll;

ll get_digits(ll N) {
	int count = 0;
	if (N < 10) return 1;

	while (N > 0) {
		N /= 10;
		count++;
	}
	return count;
}

int main()
{
	ll A, B, X;
	ll result = 0;
	cin >> A >> B >> X;

	ll maxN = ll(1e9), minN = 0, N = 0, middle = ll(1e9), sum;
	while (true) {
		sum = A * middle + B * get_digits(middle);
		if (sum <= X) {
			minN = middle;
		} else {
			maxN = middle;
		}
		middle = (minN + maxN) / 2;
		if (middle == minN || middle == maxN) break;
	}

	cout << middle << endl;
	return 0;
}