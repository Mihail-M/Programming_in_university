#include <iostream>
#include <algorithm>
#include <cmath>
#include <segmenttree.h>

using namespace std;




int main(){

	int n, m;
	cin >> n >> m;

	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	SegmentTree st(a, n);
	st.print();
	string command;
	for (int i = 0;i < m; i++) {
		cin >> command;
		int t, t1;
		if (command == "Set") {
			cin >> t >> t1;
			//update(a, t, t1);
		}
		if (command == "Min"){
			cin >> t >> t1;
			cout << st.min(t, t1) << endl;
		}

	}
	return 0;
}

