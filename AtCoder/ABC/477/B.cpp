#include <iostream>
#include <vector>
#include <algorithm>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;

inline int read() {
    char ch = getchar();
    while (ch == ' ' || ch == '\n') ch = getchar();
    if (ch == EOF) return EOF;
    int s = 1;
    while (ch < '0' || '9' < ch) {
        if (ch == '-') s = -1;
        ch = getchar();
    }
    int r = 0;
    while ('0' <= ch && ch <= '9') r = r * 10 + ch - '0', ch = getchar();
    return r * s;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    int n = read(), d = read();
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		vec[i] = {read(), i + 1};
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	vector<int> ans;
	if (vec[1].first - vec[0].first >= d) {
		sum++;
		ans.push_back(vec[0].second);
	}
	if (vec[n - 1].first - vec[n - 2].first >= d) {
		sum++;
		ans.push_back(vec[n - 1].second);
	}
	for (int i = 1; i < n - 1; i++) {
		if (vec[i].first - vec[i - 1].first >= d && vec[i + 1].first - vec[i].first >= d) {
			sum++;
			ans.push_back(vec[i].second);
		}
	}
	sort(ans.begin(), ans.end());
	write(sum);
	putchar('\n');
	for (auto& ans : ans) {
		write(ans);
		putchar(' ');
	}
    return 0;
}