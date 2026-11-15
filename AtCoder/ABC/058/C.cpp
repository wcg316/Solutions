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

inline void write_line(string str) {
    for (int i = 0; i < str.length(); i++) putchar(str[i]);
}

signed main() {
    int n = read();
	vector<int> maxTimes(26, (1 << 31) - 1);
	for (int i = 0; i < n; i++) {
		string headline = read_line();
		vector<int> currTimes(26);
		for (auto& letter : headline) {
			currTimes[letter - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			maxTimes[i] = min(maxTimes[i], currTimes[i]);
		}
	}
	for (int i = 0; i < 26; i++) {
		while (maxTimes[i]--) {
			putchar('a' + i);
		}
	}
    return 0;
}