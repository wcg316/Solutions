#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
	while (t--) {
		int n = read();
		int ans = n;
		string commands = read_line();
		vector<bool> printed(n, false);
		stack<int> printer;
		for (int i = 0; i < n; i++) {
			if (commands[i] == '1') {
				printer.push(i);
			} else if (commands[i] == '2' && !printer.empty()) {
				printed[printer.top()] = true;
				ans--;
				printer.pop();
			} else {
				printed[i] = true;
				ans--;
			}
		}
		write(ans);
		putchar('\n');
		for (int i = 0; i < n; i++) {
			if (!printed[i]) {
				write(i + 1);
				putchar(' ');
			}
		}
		putchar('\n');
	}
    return 0;
}