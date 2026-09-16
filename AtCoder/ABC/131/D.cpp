#include <iostream>
#include <vector>
#include <algorithm>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
#define deadline second
#define timeTakes first
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

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.deadline == b.deadline) {
		return a.timeTakes < b.timeTakes;
	}
	return a.deadline > b.deadline;
}

signed main() {
    int n = read();
	vector<pair<int, int>> jobs(n);
	for (auto& job : jobs) {
		job = {read(), read()};
	}
	sort(jobs.begin(), jobs.end(), cmp);
	int timeRemain = jobs[0].deadline;
	for (int i = 0; i < n - 1; i++) {
		timeRemain = min(jobs[i + 1].deadline, timeRemain - jobs[i].timeTakes);
	}
	write_line(timeRemain >= jobs[n - 1].timeTakes ? "Yes" : "No");
	return 0;
}