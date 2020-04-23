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
	vector<string> v;
	int cnt = 0;
	cin >> s;
	sort(s.begin(), s.end());
	do {
		string t;
		for (int i = 0; i < s.length(); i++) t += s[i];
		v.push_back(t);
		cnt++;
	} while (next_permutation(s.begin(), s.end()));
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) cout << v[i] << "\n";
}
