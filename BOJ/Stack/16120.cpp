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
	stack<int> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A') {
			if (s[i + 1] != 'P') {
				cout << "NP\n";
				return 0;
			}
			else {
				i++;
				for (int j = 0; j < 2; j++) {
					if (st.empty()) {
						cout << "NP\n";
						return 0;
					}
					st.pop();
				}
				st.push(s[i]);
			}
		}
		else st.push(s[i]);
	}
	if (st.size() == 1) cout << "PPAP\n";
	else cout << "NP\n";
}
