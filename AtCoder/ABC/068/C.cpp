#include <iostream>
#include <vector>
#include <unordered_map>
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

inline void write_line(string str) {
    for (int i = 0; i < str.length(); i++) putchar(str[i]);
}

signed main() {
    int n = read(), m = read();
	unordered_map<int, vector<int>> routes;
	while (m--) {
		int a = read(), b = read();
		routes[a].push_back(b);
		routes[b].push_back(a);
	}
	for (auto& route : routes) {
		bool depart = false, arrive = false;
		for (auto island : route.second) {
			if (island == 1) {
				depart = true;
			} else if (island == n) {
				arrive = true;
			}
		}
		if (depart && arrive) {
			write_line("POSSIBLE");
			return 0;
		}
	}
	write_line("IMPOSSIBLE");
	return 0;
}