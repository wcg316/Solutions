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
		if (n == 1) {
			write(1);
			putchar('\n');
			write(read());
			putchar('\n');
			continue;
		}
		vector<int> books(n);
		for (auto& book : books) {
			book = read();
		}
		int Lans = 1;
		vector<int> Lbooks;
		vector<int> remainingBooks;
		sort(books.begin(), books.end());
		Lbooks.push_back(books[0]);
		for (int i = 1; i < n; i++) {
			if (books[i] > books[i - 1]) {
				Lbooks.push_back(books[i]);
				Lans++;
			} else {
				remainingBooks.push_back(books[i]);
			}
		}
		int Rans = 0;
		vector<int> Rbooks;
		vector<int> midBooks;
		if (!remainingBooks.empty()) {
			Rans++;
			Rbooks.push_back(remainingBooks[0]);
		}
		for (int i = 1; i < remainingBooks.size(); i++) {
			if (remainingBooks[i] > remainingBooks[i - 1]) {
				Rbooks.push_back(remainingBooks[i]);
				Rans++;
			} else {
				midBooks.push_back(remainingBooks[i]);
			}
		}
		write(Lans + Rans);
		putchar('\n');
		for (auto book : Lbooks) {
			write(book);
			putchar(' ');
		}
		for (auto book : midBooks) {
			write(book);
			putchar(' ');
		}
		reverse(Rbooks.begin(), Rbooks.end());
		for (auto book : Rbooks) {
			write(book);
			putchar(' ');
		}
		putchar('\n');
	}
    return 0;
}