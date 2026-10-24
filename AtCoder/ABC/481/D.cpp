#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>
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
    int n = read(), m = read(), s = read(), t = read();
	vector<int> minFuel(n + 1, INT_MAX);
	unordered_map<int, vector<int>> routes;
	while (m--) {
		routes[read()].push_back(read());
	}
	for (auto& route : routes) {
		sort(route.second.begin(), route.second.end());
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> visited(n + 1, false);
	pq.push({0, s});
	visited[s] = true;
	while (!pq.empty()) {
		auto [fuelUsed, pos] = pq.top();
		pq.pop();
		if (pos == t) {
			write(fuelUsed);
			return 0;
		}
		if (routes.find(pos) != routes.end()) {
			if (!visited[routes[pos][0]] || fuelUsed < minFuel[routes[pos][0]]) {
				pq.push({fuelUsed, routes[pos][0]});
				visited[routes[pos][0]] = true;
				minFuel[routes[pos][0]] = fuelUsed;
			}
			for (int i = 1; i < routes[pos].size(); i++) {
				if (!visited[routes[pos][i]] || fuelUsed + 1 < minFuel[routes[pos][i]]) {
					pq.push({fuelUsed + 1, routes[pos][i]});
					visited[routes[pos][i]] = true;
					minFuel[routes[pos][i]] = fuelUsed + 1;
				}
			}
		}
	}
	write(-1);
    return 0;
}