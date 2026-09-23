#include <iostream>
#include <string>
#define int long long
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
	int m = 0, a = 0, r = 0, c = 0, h = 0;
	while (n--) {
		string str = read_line();
		switch (str[0]) {
			case 'M' :
				m++;
				break;
			case 'A' :
				a++;
				break;
			case 'R' :
				r++;
				break;
			case 'C' :
				c++;
				break;
			case 'H' :
				h++;
				break;
		} 
	}
	write((m * a * r) + (m * a * c) + (m * a * h) + (m * r * c) + (m * r * h) +
		  (m * c * h) + (a * r * c) + (a * r * h) + (a * c * h) + (r * c * h));
    return 0;
}