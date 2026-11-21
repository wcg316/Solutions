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
    int n = read(), m = read();
	vector<vector<char>> grid(n, vector<char>(m));
	for (auto& row : grid) {
		for (auto& cell : row) {
			cell = getchar();
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		if (grid[i][0] == 'x' && grid[i][1] == 'x') {
			write_line("Faucet ");
			write(i + 1);
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		if (grid[0][i] == 'x' && grid[1][i] == 'x') {
			write_line("Drain ");
			write(i + 1);
			return 0;
		}
	}
    return 0;
}