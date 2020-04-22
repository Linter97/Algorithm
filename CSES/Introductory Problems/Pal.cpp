#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char a[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[i + 1]) i++;
		else cnt++;
	}
	if (cnt > 1) {
		cout << "NO SOLUTION\n";
		return 0;
	}
	int i = 0, j = 0;
	while (i < s.length()) {
		if (s[i] == s[i + 1]) {
			a[j] = a[s.length() - j - 1] = s[i];
			i += 2;
			j++;
		}
		else {
			a[s.length() / 2] = s[i];
			i++;
		}
	}
	for (int i = 0; i < s.length(); i++)cout << a[i];
}
