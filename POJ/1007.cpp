#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define N 50

struct DNA {
	string str, word;
	int counter;
	DNA(string& s, int l) {
		str = s;
		word = str;
		counter = 0;
		counting(0, l);
	}
	void counting(int h, int t) {
		int n = t - h;
		if (n == 1) return;
		if (n == 2) {
			if (word[h] > word[h + 1]) {
				counter++;
				char c = word[h];
				word[h] = word[h + 1];
				word[h + 1] = c;
			}
			return;
		}
		int i, j, mid;
		mid = (h + t) / 2;
		counting(h, mid);
		counting(mid, t);
		string tmp = "";
		for (i = h, j = mid; i < mid && j < t;) {
			if (word[i] > word[j]) {
				counter += mid - i;
				tmp += word[j++];
			}
			else
				tmp += word[i++];
		}
		for (; i < mid; i++)
			tmp += word[i];
		for (; j < t; j++)
			tmp += word[j];
		for (i = 0; h < t; h++, i++)
			word[h] = tmp[i];
	}
};

bool cmp(DNA& a, DNA& b) {
	return a.counter < b.counter;
}

int main() {
	int i, n, m;
	string str;
	vector<DNA> container;
	cin >> n >> m;
	for (i=0; i<m; i++) {
		cin >> str;
		container.push_back(DNA(str, n));
	}
	sort(container.begin(), container.end(), cmp);
	for (i = 0; i < m; i++)
		cout << container[i].str << endl;
	return 0;
}