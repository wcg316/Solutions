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

signed main() {
    string alice = read_line();
	string bob = read_line();
	string charlie = read_line();
	int i = 0, j = 0, k = 0;
	char* card = &alice[0];
	while (true) {
		if (card == &alice[i]) {
			if (i++ >= alice.size()) {
				putchar('A');
				return 0;
			}
		} else if (card == &bob[j]) {
			if (j++ >= bob.size()) {
				putchar('B');
				return 0;
			}
		} else {
			if (k++ >= charlie.size()) {
				putchar('C');
				return 0;
			}
		}
		if (*card == 'a') {
			card = &alice[i];
		} else if (*card == 'b') {
			card = &bob[j];
		} else {
			card = &charlie[k];
		}
	}
    return 0;
}