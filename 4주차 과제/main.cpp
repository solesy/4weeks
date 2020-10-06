/*#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<algorithm>
#include<cassert>
#include<memory.h>
#include<cmath>
using namespace std;*/
#include"GrowableArray.h"

int main(void) {
	cout << "GrowableArray<int> Test" << endl;
	GrowableArray<int> g(10);
	for (int i = 0; i < g.length(); ++i) g[i] = 2 * i + 3;
	cout << "g(10)"; g.print();
	g[13] = 13;
	cout << "g(20)"; g.print();
	cout << "GrowableArray<double> Test" << endl;
	GrowableArray<double> dg(10);
	for (int i = 0; i < dg.length(); ++i) dg[i] = 2 * i + 3.14;
	cout << "dg(10)"; dg.print();
	dg[13] = 13.31;
	cout << "dg(20)"; dg.print();
}
