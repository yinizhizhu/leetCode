#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

char monthHaab[19][60] = { "pop", "no", "zip", "zotz", "tzec",
"xul", "yoxkin", "mol", "chen", "yax",
"zac", "ceh", "mac", "kankin", "muan",
"pax", "koyab", "cumhu", "uayet" };

struct dateHaab {
	int day, month, year;
	int days;
	dateHaab(int d, string& m, int y) {
		day = d + 1;
		for (int i = 0; i < 19; i++)
			if (monthHaab[i] == m) {
				month = i;
				break;
			}
		year = y;
		days = year * 365 + month * 20 + day;
	}
};

char dayTzolkin[20][60] = { "ahau", "imix", "ik", "akbal", "kan", "chicchan",
"cimi", "manik", "lamat", "muluk", "ok",
"chuen", "eb", "ben", "ix", "mem",
"cib", "caban", "eznab", "canac" };

struct dateTzolkin {
	int days;
	int day, month, year;
	dateTzolkin(int ds) {
		days = ds;
	}
	void getDI() {
		year = days / 260;
		if (days % 260 == 0)
			year--;
		month = days % 13;
		if (month == 0)
			month = 13;
		day = days % 20;
	}
};

int main() {
	int n, i;
	string month;
	int day, year;
	while (cin >> n) {
		vector<dateHaab> container;
		for (i = 0; i < n; i++) {
			scanf("%d. ", &day);
			cin >> month;
			cin >> year;
			container.push_back(dateHaab(day, month, year));
		}
		cout << n << endl;
		for (i = 0; i < n; i++) {
			dateTzolkin des(container[i].days);
			des.getDI();
			cout << des.month << " " << dayTzolkin[des.day] << " " << des.year << endl;
		}
	}
	return 0;
}