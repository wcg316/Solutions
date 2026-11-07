#include <iostream>
#include <vector>
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
    int n = read(), m = read();
	vector<pair<int, int>> secondVotes(m);
	vector<int> originalVotes(n + 1);
	for (auto& secondVote : secondVotes) {
		int f = read(), s = read();
		secondVote = {f, s};
		originalVotes[f]++;
	}
	int originalWinner = 1;
	int secondWinner = 0;
	for (int i = 2; i <= n; i++) {
		if (originalVotes[i] > originalVotes[originalWinner]) {
			secondWinner = originalWinner;
			originalWinner = i;
		} else if (!secondWinner || originalVotes[i] > originalVotes[secondWinner]) {
			secondWinner = i;
		}
	}
	sort(secondVotes.begin(), secondVotes.end());
	int pass = 0;
	for (int i = 1; i <= n; i++) {
		int ans = originalWinner == i ? secondWinner : originalWinner;
		int voteForWithdrawOne = originalVotes[i];
		originalVotes[i] = 0;
		for (int j = 0; j < voteForWithdrawOne; j++) {
			int candidate = secondVotes[pass + j].second;
			originalVotes[candidate]++;
			if (originalVotes[candidate] > originalVotes[ans] ||
				originalVotes[candidate] == originalVotes[ans] && ans > candidate) {
				ans = candidate;
			}
		}
		write(ans);
		putchar('\n');
		originalVotes[i] = voteForWithdrawOne;
		for (int j = 0; j < voteForWithdrawOne; j++) {
			originalVotes[secondVotes[pass + j].second]--;
		}
		pass += originalVotes[i];
	}
    return 0;
}