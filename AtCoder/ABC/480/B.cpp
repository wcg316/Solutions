#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
    int n = read(), m = read();
	vector<string> candidates(n);
	unordered_map<string, char*> misspeltCandidates;
	unordered_map<string, char> voteReceived;
	for (auto& candidate : candidates) {
		string input = read_line();
		candidate = input;
		misspeltCandidates[input] = &voteReceived[candidate];
		for (auto& ch : input) {
			for (int i = 0; i < 26; i++) {
				ch = 'a' + i;
				if (misspeltCandidates.find(input) == misspeltCandidates.end()) {
					misspeltCandidates[input] = &voteReceived[candidate];
				} else if (misspeltCandidates[input] != &voteReceived[candidate] && voteReceived.find(input) == voteReceived.end()) {
					misspeltCandidates[input] = nullptr;
				}
			}
			input = candidate;
		}
	}
	while (m--) {
		string vote = read_line();
		if (misspeltCandidates.find(vote) != misspeltCandidates.end() && misspeltCandidates[vote] != nullptr) {
			(*misspeltCandidates[vote])++;
		}
	}
	for (auto& candidate : candidates) {
		write(voteReceived[candidate]);
		putchar('\n');
	}
    return 0;
}