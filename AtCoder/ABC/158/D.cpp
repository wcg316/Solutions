#include <iostream>
#include <deque>
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
    char ch = getchar();
	deque<char> str;
	while (ch != '\n') {
		str.push_front(ch);
		ch = getchar();
	}
	int q = read();
	bool reversed = 0;
	while (q--) {
		if (read() & 1) {
			reversed ^= 1;
		} else {
			if (reversed ^ (read() & 1)) {
				str.push_back(getchar());
			} else {
				str.push_front(getchar());
			}
		}
	}
	int t = str.size();
	if (reversed) {
		while (t--) {
			putchar(str.front());
			str.pop_front();
		}
	} else {
		while (t--) {
			putchar(str.back());
			str.pop_back();
		}
	}
    return 0;
}