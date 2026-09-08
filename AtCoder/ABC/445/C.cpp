#include <iostream>
#include <vector>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;

int n;
vector<int> vec;

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
	vector<int> vec(n);
	vector<bool> finished(n);
	for (int i = 0; i < n; i++) {
		vec[i] = read() - 1;
		if (vec[i] == i) {
			finished[i] = true;
		}
	}
	for (int i = n - 1; ~i; i--) {
		if (!finished[i]) {
			finished[i] = true;
			vec[i] = vec[vec[i]];
		}	
	}
	for (auto ans : vec) {
		write(ans + 1);
		putchar(' ');
	}
	return 0;
}