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

using namespace std;

const string COUNT[11] = {"", "", " double", " triple", " quadruple", " quintuple", " sextuple", " septuple", " octuple", " nonuple", " decuple"};
const string NUM[10] = {" zero", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine"};

int main()
{
	int T;
	string number, style;
	int index, size, count, previous;
	stack<string> out;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ":";
		cin >> number >> style;
		index = 0;
		for (int j = 0; j < style.size(); ++j) {
			size = 0;
			for (; j < style.size() && style[j] != '-'; ++j) {
				size = size * 10 + style[j] - '0';
			}
			//cerr << i << ", size = " << size << endl;
			previous = number[index + size - 1] - '0';
			if (size == 1) {
				cout << NUM[previous];
				++index;
				//cerr << i << ", " << count << endl;
				continue;
			}
			count = 1;
			for (int k = index + size - 2; k >= index; --k) {
				if (number[k] - '0' != previous) {
					if (count > 10) {
						for (int l = 0; l < count; ++l) {
							out.push(NUM[previous]);
						}
					}
					else {
						out.push(NUM[previous]);
						out.push(COUNT[count]);
					}
					count = 1;
					previous = number[k] - '0';
				}
				else {
					++count;
				}
				if (k == index) {
					if (count > 10) {
						for (int l = 0; l < count; ++l) {
							out.push(NUM[previous]);
						}
						//cerr << i << ", " << count << endl;
					}
					else {
						out.push(NUM[previous]);
						out.push(COUNT[count]);
						//cerr << i << ", " << count << endl;	
					}
				}
			}
			index += size;
			while (!out.empty()) {
				cout << out.top();
				out.pop();
			}
		}
		cout << endl;
	}

	exit(0);
}

