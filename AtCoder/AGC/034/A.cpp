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
    int n = read(), a = read(), b = read(), c = read(), d = read();
    string str = read_line();
    int rockCount = 0;
    for (int i = a - 1; i < max(c, d); i++) {
        if (str[i] == '#') {
            rockCount++;
            if (rockCount >= 2) {
                write_line("No");
                return 0;
            }
        } else {
            rockCount = 0;
        }
    }
    if (c > d) {
        int spaceCount = 0;
        for (int i = b - 2; i <= d; i++) {
            if (str[i] == '.') {
                spaceCount++;
                if (spaceCount >= 3) {
                    write_line("Yes");
                    return 0;
                }
            } else {
                spaceCount = 0;
            }
        }
        write_line("No");
        return 0;
    }
    write_line("Yes");
    return 0;
}