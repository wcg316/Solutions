#include <iostream>
#include <vector>
#include <string>
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

inline void write_line(string str) {
    for (int i = 0; i < str.length(); i++) putchar(str[i]);
}

signed main() {
    int h = read(), w = read();
	int passed = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char ch = getchar();
			if (ch == '#') {
				passed++;
			}
		}
		getchar();
	}
	write_line(passed == h + w - 1 ? "Possible" : "Impossible");
    return 0;
}