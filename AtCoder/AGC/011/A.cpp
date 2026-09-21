#include <iostream>
#include <vector>
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

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    int n = read(), c = read(), k = read();
	vector<int> arriveTimes(n);
	for (auto& arriveTime : arriveTimes) {
		arriveTime = read();
	}
	sort(arriveTimes.begin(), arriveTimes.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int departTime = arriveTimes[i] + k;
		for (int j = 1; j <= c; j++) {
			if (arriveTimes[i + j] > departTime || j == c) {
				i += j - 1;
				break;
			}
		}
		ans++;
	}
	write(ans);
	return 0;
}