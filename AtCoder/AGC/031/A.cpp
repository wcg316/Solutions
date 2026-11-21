#include <iostream>
#include <string>
#include <vector>
#define int long long
#define MOD 1000000007
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

signed main() {
    int n = read();
    string str = read_line();
    vector<int> cnt(26);
    for (auto& ch : str) {
        cnt[ch - 'a']++;
    }
    int ans = 1;
    for (auto& c : cnt) {
        ans *= (c + 1);
        ans %= MOD;
    }
    write(ans - 1);
	return 0;
}