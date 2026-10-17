#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;

inline void write_line(string str) {
    for (int i = 0; i < str.length(); i++) putchar(str[i]);
}

signed main() {
    int bitmap = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			char ch = getchar();
			if (ch == 'A' || ch == 'D') {
				bitmap += 1 << ((i << 1) + j);
			}
		}
		getchar();
	}
	write_line(bitmap & 1 && bitmap & 8 || bitmap & 2 && bitmap & 4 ? "No" : "Yes");
    return 0;
}