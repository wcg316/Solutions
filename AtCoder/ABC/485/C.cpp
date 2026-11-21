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
    int n = read();
	int color = read();
	int cnt = 1;
	vector<int> lengths;
	while (--n) {
		int curr = read();
		if (curr == color) {
			cnt++;
		} else {
			lengths.push_back(cnt);
			color = curr;
			cnt = 1;
		}
	}
	lengths.push_back(cnt);
	for (int ans = 1; ans <= lengths[0]; ans++) {
		write(lengths[0] - ans + 1);
		putchar(' ');
	}
	for (int i = 1; i < lengths.size() - 1; i++) {
		int currLength = lengths[i];
		for (int ans = 1; ans <= currLength; ans++) {
			write(min(ans, currLength - ans + 1));
			putchar(' ');
		}
	}
	for (int ans = 1; ans <= lengths[lengths.size() - 1]; ans++) {
		write(ans);
		putchar(' ');
	}
    return 0;
}