#include <iostream>
#include <map>
#include <iterator>
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
    int h = read(), w = read(), n = read(), q = read();
	map<int, int> rowCount;
	map<int, int> columnCount;
	rowCount[0] = 0;
	columnCount[0] = 0;
	while (n--) {
		rowCount[read()]++;
		columnCount[read()]++;
	}
	for (auto it = next(rowCount.begin()); it != rowCount.end(); it++) {
		it -> second += prev(it) -> second;
	}
	for (auto it = next(columnCount.begin()); it != columnCount.end(); it++) {
		it -> second += prev(it) -> second;
	}
	while (q--) {
		int type = read(), s = read(), e = read();
		write(type & 1 ?
			prev(rowCount.upper_bound(e)) -> second - prev(rowCount.lower_bound(s)) -> second :
			prev(columnCount.upper_bound(e)) -> second - prev(columnCount.lower_bound(s)) -> second
		);
		putchar('\n');
	}
    return 0;
}