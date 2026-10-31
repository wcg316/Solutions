#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;

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
    int count = 0;
	char ch = getchar();
	while (ch != EOF && ch != '\n' && ch != ' ') {
		if (ch == 'o') {
			count++;
		}
		ch = getchar();
	}
	write_line(count & 1 ? "odd" : "even");
    return 0;
}