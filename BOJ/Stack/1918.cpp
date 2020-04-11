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
	string s, op = "+-*/()";
	cin >> s;
	stack<char> st;
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		if (op.find(s[i]) == string::npos) {
			res += s[i];
		}
		else {
			if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')') {
				while (st.top() != '(') {
					res += st.top();
					st.pop();
				}
				st.pop();
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	cout << res << "\n";
}
