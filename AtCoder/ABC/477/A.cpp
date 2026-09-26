#include <iostream>
//#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;

signed main() {
	char ch = getchar();
    putchar(ch == 'B' ? 'Y' : ch == 'Y' ? 'R' : 'B');
    return 0;
}