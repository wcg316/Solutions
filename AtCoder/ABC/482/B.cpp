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

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    vector<vector<char>> grid(5, vector<char>(5));
	for (auto& row : grid) {
		for (auto& cell : row) {
			cell = getchar();
		}
		getchar();
	}
	int ans = min(
		(grid[0][0] == '.') + (grid[1][1] == '.') + (grid[2][2] == '.') + (grid[3][3] == '.') + (grid[4][4] == '.'), 
		(grid[0][4] == '.') + (grid[1][3] == '.') + (grid[2][2] == '.') + (grid[3][1] == '.') + (grid[4][0] == '.')
	);
	for (int i = 0; i < 5; i++) {
		int rowMarks = 0, columnMarks = 0;
		for (int j = 0; j < 5; j++) {
			if (grid[i][j] == 'o') {
				rowMarks++;
			}
			if (grid[j][i] == 'o') {
				columnMarks++;
			}
		}
		ans = min({5 - rowMarks, 5 - columnMarks, ans});
	}
	write(ans);
    return 0;
}