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

signed main() {
    int n = read();
	string people = read_line();
	vector<int> shouldTurnWest(n + 1);
	vector<int> shouldTurnEast(n + 1);
	shouldTurnWest[0] = shouldTurnEast[n] = 0;
	for (int i = 1; i <= n; i++) {
		shouldTurnWest[i] = shouldTurnWest[i - 1] + (people[i - 1] == 'W');
		shouldTurnEast[n - i] = shouldTurnEast[n - i + 1] +(people[n - i] == 'E');
	}
	int ans = (1 << 31) - 1;
	for (int i = 0; i < n; i++) {
		ans = min(ans, shouldTurnWest[i + 1] + shouldTurnEast[i]);
	}
	write(ans - 1);
    return 0;
}