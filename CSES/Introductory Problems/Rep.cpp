#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 1, res = 1;
	for (int i = 1; i < (int) s.length(); i++) {
		if (s[i] != s[i - 1]) {
			cnt = 1;
		}
		else cnt++;
		res = max(res, cnt);
	}
	cout << res << "\n";
}
