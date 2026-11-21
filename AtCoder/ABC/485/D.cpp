#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;

int n;
string str;
vector<int> Aprefix, Bprefix, Cprefix;

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

inline bool isLegal(int a, int b) {
	return
		Aprefix[b] - Aprefix[a] > 0 && 
		Bprefix[b] - Bprefix[a] > 0 && 
		Cprefix[b] - Cprefix[a] > 0;
}

signed main() {
    n = read();
	str = read_line();
	Aprefix.resize(n + 1), Bprefix.resize(n + 1), Cprefix.resize(n + 1);
	Aprefix[0] = Bprefix[0] = Cprefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		Aprefix[i] = Aprefix[i - 1] + (str[i - 1] == 'A');
		Bprefix[i] = Bprefix[i - 1] + (str[i - 1] == 'B');
		Cprefix[i] = Cprefix[i - 1] + (str[i - 1] == 'C');
	}
	int l = -1;
	for (int i = 3; i <= n; i++) {
		if (isLegal(0, i)) {
			l = i;
			break;
		}
	}
	int r = -1;
	for (int i = l + 3; i <= n; i++) {
		if (isLegal(l, i)) {
			r = i;
			break;
		}
	}
	if (!~l || !~r || !isLegal(r, n)) {
		putchar('0');
		return 0;
	}
	int ans = 0;
	int i = l, j = r;
	while (isLegal(j, n)) {
		while (isLegal(i, j)) {
			i++;
		}
		ans += i - l;
		j++;
	}
	write(ans);
    return 0;
}