#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include "lexic.h"
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	srand(time(0));

	long long value;
	for (int i = 0; i < 20; i++)
	{
		if (!(cin >> value))
			value = rand() % 999999999;
		vector <string> cases{ "И", "Р", "Д", "В", "Т", "П" };
		vector <string> genders{ "М", "Ж", "С" };
		int a, b;
		a = rand() % 6;
		b = rand() % 3;
		cout << sumProp(value, genders[b], cases[a]) << endl;

	}
	return 0;
}
