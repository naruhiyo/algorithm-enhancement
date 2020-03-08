#include <bits/stdc++.h>
#define repeat(i, n) for(int (i) = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const double EPS = numeric_limits<double>::epsilon();
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
	string S;
	cin >> S;
	vector<int> result(S.length(), 0);

	int pos = 0, right_count, left_count;
	repeat(i, S.length()) {
		string a = S.substr(i, 1);
		pos++;
		if (a == "R") continue;

		pos -= 1; // `L`
		if (pos < 1) continue;

		// count RL of RRRRL
		result[i-1] += 1; // R
		pos -= 1; // `R`
		if (pos < 1) continue;

		// count other strings
		right_count = pos / 2;
		left_count = pos - right_count;

		result[i] += left_count;
		result[i-1] += right_count;

		pos = 0;
	}

	pos = 0;

	for(int i = S.length() - 1; i >= 0; i--) {
		string a = S.substr(i, 1);
		pos++;
		if (a == "L") continue;

		pos -= 1;	// `R`
		if (pos < 1) continue;

		// count RL of RLLLL
		result[i+1] += 1; // L
		pos -= 1;// L
		if (pos < 1) continue;

		if (pos < 1) continue;

		// count other strings
		left_count = pos / 2;
		right_count = pos - left_count;

		result[i] += right_count;
		result[i+1] += left_count;

		pos = 0;
	}

	repeat(i, S.length()) {
		cout << result[i] << endl;
	}
	return 0;
}
