#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
    int t = read();
	while (t--) {
		int n = read();
		string str = read_line();
		vector<int> replaced(26);
		for (int i = 0; i < n >> 1; i++) {
			int a = str[i] - 'a', b = str[n - 1 - i] - 'a';
			replaced[min(a, b)]++;
			replaced[max(a, b)]--;
		}
		int ans = replaced[0] > 0 ? 1 : 0;
		for (int i = 1; i < 26; i++) {
			replaced[i] += replaced[i - 1];
			ans += replaced[i] > 0;
		}
		write(ans);
		putchar('\n');
	}
    return 0;
}