#include <iostream>
#include <vector>
#include <cmath>
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
    int n = read();
	vector<int> spots(n + 2);
	spots[0] = spots[n + 1] = 0;
	for (int i = 1; i < n + 1; i++) {
		spots[i] = read();
	}
	vector<int> costs(n + 1);
	int totalCost = 0;
	for (int i = 0; i < n + 1; i++) {
		costs[i] = abs(spots[i] - spots[i + 1]);
		totalCost += costs[i];
	}
	for (int i = 1; i < n + 1; i++) {
		write(totalCost - costs[i - 1] - costs[i] + abs(spots[i - 1] - spots[i + 1]));
		putchar('\n');
	}
	return 0;
}