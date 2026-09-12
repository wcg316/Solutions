#include <iostream>
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
    int t = read();
	int hundred = 0, ten = 0, one = 0;
	while (t--) {
		int n = read() % 1000;
		hundred += n ? 9 - (n / 100) + (n % 100 == 0) : 0;
		n %= 100;
		ten += n ? 9 - (n / 10) + (n % 10 == 0) : 0;
		n %= 10;
		one += n ? 10 - n : 0;
	}
	write(one);
	putchar(' ');
	write(ten);
	putchar(' ');
	write(hundred);
	return 0;
}