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
    int n = read(), m = read();
	vector<pair<bool, bool>> occupied(n, {false, false});
	vector<pair<int, int>> pieces(m);
	for (auto& piece : pieces) {
		piece = {read(), read()};
	}
	int ans = 0;
	for (int i = m - 1; ~i; i--) {
		if (!occupied[pieces[i].first].first && !occupied[pieces[i].second].second) {
			ans++;
		}
		occupied[pieces[i].first].first = true;
		occupied[pieces[i].second].second = true;
	}
	write(ans);
	return 0;
}