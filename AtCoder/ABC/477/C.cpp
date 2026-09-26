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
    int q = read();
	string str = read_line();
	string target = read_line();
	size_t pos = str.find(target);
	vector<int> results;
	results.reserve(400000);
	while (pos != str.npos) {
		results.push_back(pos + 1);
		pos = str.find(target, pos + 1);
	}
	while (q--) {
		int l = read(), r = read();
		auto itFirst = lower_bound(results.begin(), results.end(), l);
		if (itFirst != results.end() && r >= *itFirst + target.length()	- 1) {
			write_line("Yes\n");
		} else {
			write_line("No\n");
		}
	}
    return 0;
}