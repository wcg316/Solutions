#include <iostream>
#include <queue>
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

signed main() {
    queue<int> a, b, c;
	string str = read_line();
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == 'A') {
			a.push(i);
		} else if (str[i] == 'B') {
			b.push(i);
		} else {
			c.push(i);
		}
	}
	int ans = 0;
	while (!a.empty()) {
		while (!b.empty() && a.front() > b.front()) {
			b.pop();
		}
		while (!c.empty() && b.front() > c.front()) {
			c.pop();
		}
		if (!b.empty() && !c.empty()) {
			ans++;
			b.pop();
			c.pop();
		}
		a.pop();
	}
	write(ans);
	return 0;
}