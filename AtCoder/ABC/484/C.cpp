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
	vector<int> vec_a(n);
	vector<int> vec_b(n);
	for (auto& a : vec_a) {
		a = read();
	}
	for (auto& b : vec_b) {
		b = read();
	}
	int l = -1, r = -1;
	for (int i = 0; i < n; i++) {
		if (vec_a[i] != vec_b[i]) {
			l = i;
			break;
		}
	}
	for (int i = n - 1; ~i; i--) {
		if (vec_a[i] != vec_b[i]) {
			r = i;
			break;
		}
	}
	bool forward = true, back = true;
	for (int i = l; i < r; i++) {
		if (vec_a[i + 1] != vec_b[i]) {
			forward = false;
		}
		if (vec_a[i] != vec_b[i + 1]) {
			back = false;
		}
	}
	write_line((l != r && ((forward && vec_a[l] == vec_b[r]) || (back && vec_a[r] == vec_b[l]))) || (l == -1 && r == -1) ? "Yes" : "No");
    return 0;
}