#include <iostream>
#include <vector>
#define int long long
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
    int n = read();
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = read();
		b[i] = read();
	}
	int ans = 0;
	for (int i = n - 1; ~i; i--) {
		int m = (a[i] + ans) % b[i];
		ans += m ? b[i] - m : 0;
	}
	write(ans);
    return 0;
}