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
    int n = read(), q = read();
	vector<int> vec(n), prefix(n + 1);
	prefix[0] = 0;
	for (int i = 0; i < n; i++) {
		vec[i] = read();
		prefix[i + 1] = prefix[i] + vec[i];
	}
	while (q--) {
		if (read() == 1) {
			int x = read();
			prefix[x] += vec[x] - vec[x - 1];
			swap(vec[x - 1], vec[x]);
		} else {
			int l = read() - 1, r = read();
			write(prefix[r] - prefix[l]);
			putchar('\n');
		}
	}
	return 0;
}