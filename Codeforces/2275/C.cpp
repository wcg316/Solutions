#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

inline void write_line(string str) {
    for (int i = 0; i < str.length(); i++) putchar(str[i]);
}

signed main() {
    int t = read();
	while (t--) {
		int n = read();
		vector<int> audienceLoves(n);
		for (auto& audienceLove : audienceLoves) {
			audienceLove = read();
		}
		vector<int> traids(n - 4);
		unordered_map<int, vector<int>> traidMap;
		for (int i = 0; i < n - 4; i++) {
			traids[i] = audienceLoves[i] + audienceLoves[i + 2] - audienceLoves[i + 4];
			traidMap[audienceLoves[i] + audienceLoves[i + 2] - audienceLoves[i + 4]].push_back(i);
		}
		int ans = 0;
		for (int i = 0; i < n - 4; i++) {
			if (traidMap.count(traids[i])) {
				for (int j = 0; j < traidMap[traids[i]].size(); j++) {
					for (int k = j + 1; k < traidMap[traids[i]].size() && k < j + 5; k++) {
						if ((traidMap[traids[i]][k] != traidMap[traids[i]][j] + 2) && (traidMap[traids[i]][k] != traidMap[traids[i]][j] + 4)) {
							ans++;
						}
					}
					if (traidMap[traids[i]].size() > j + 5) {
						ans += traidMap[traids[i]].size() - j - 5;
					}
				}
			}
			traidMap.erase(traids[i]);
		}
		write(ans);
		putchar('\n');
	}
    return 0;
}