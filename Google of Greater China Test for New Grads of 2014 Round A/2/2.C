#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

unsigned long POWER[64] = {1};

int main()
{
	for (int i = 1; i < 64; ++i) {
		POWER[i] = POWER[i - 1] * 2;
	}
	for (int i = 1; i < 64; ++i) {
		--POWER[i];
	}

	int T;
	int id;
	unsigned long n, p, q;
	//int j;
	unsigned long j;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> id;
		cout << "Case #" << i << ':';
		if (1 == id) {
			cin >> n;
			for (j = 63; POWER[j] > n; --j) ;
			if (n % 2) {
				q = j + 1 - (n - POWER[j]) / 2;
				cout << ' ' << j + 1 << ' ' << q;
			}
			else {
				p = (n-POWER[j]) / 2 + 1;
				cout << ' ' << p << ' ' << j + 1;
			}
		}
		else {
			cin >> p >> q;
			if (p == q) {
				cout << " 1";
			}
			else if (p > q) {
				n = POWER[p - 1] + (p - q) * 2;
				cout << ' ' << n;
			}
			else {
				n = POWER[q - 1] + p * 2 - 1;
				cout << ' ' << n;
			}
		}
		cout << endl;
	}

	exit(0);
}

