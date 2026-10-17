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

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    int n = read(), k = read(), t = read();
	vector<int> input(n);
	for (auto& i : input) {
		i = read();
	}
	sort(input.begin(), input.end());
	vector<int> startTime(n + 1, -1);
	vector<int> endTime(n + 1, -1);
	startTime[n] = t;
	endTime[0] = 0;
	for (int i = 0; i < n; i++) {
		startTime[i] = input[i];
		if (startTime[i] > t) {
			startTime[i] = t;
			break;
		}
		endTime[i + 1] = startTime[i] + k;
	}
	int ans = 0, i = 0, j = 0;
	while (i <= n && j <= n && startTime[i] <= t && ~startTime[i] && ~endTime[j]) {
		ans += (startTime[i] - endTime[j] + k - 1) / k;
		i++;
		j++;
		while (i <= n && j <= n && startTime[i] < endTime[j]) {
			i++;
			j++;
		}
	}
	write(ans);
    return 0;
}