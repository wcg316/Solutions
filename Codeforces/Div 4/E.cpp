#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

inline string read_line() {
    string r = "";
    char ch = getchar();
    while (ch != '\n' && ch != EOF) r += ch, ch = getchar();
    return r;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void write_line(string str) {
    for (int i = 0; i < str.length(); i++) putchar(str[i]);
}

signed main() {
    int t = read();
	while (t--) {
		int n = read(), k = read();
		vector<int> vec(n);
		vec[0] = 1;
		for (int i = 1; i < n; i++) {
			if (i - k <= 0) {
				vec[i] = 0;
			} else {
				vec[i] = i % (k + 1) == 0;
			}
		}
		bool alice = 0;
		for (int i = 0; i < n; i++) {
			alice = (alice + read() * vec[i]) & 1;
		}
		write_line(alice ? "Alice" : "Bob");
		putchar('\n');
	}
    return 0;
}