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
	bool solved = false;
	while (t--) {
		int x = read(), y = read(), r = read();
		for (int i = -35; i <= 35; i++) {
			for (int j = -35; j <= 35; j++) {
				if ((x - i) * (x - i) + (y - j) * (y - j) == r * r) {
					write(i);
					putchar(' ');
					write(j);
					putchar('\n');
					solved = true;
					break;
				}
			}
			if (solved) {
				solved = false;
				break;
			}
		}
	}
    return 0;
}