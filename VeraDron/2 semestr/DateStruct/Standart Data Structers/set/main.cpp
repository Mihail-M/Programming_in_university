#include <iostream>
#include <set>

#include "point.h"


using namespace std;

template <class T>
set<T> intersect(set<T> a, set<T> b)
{
	set<T> ans;
	for (set<T>::iterator i = a.begin(); i != a.end(); i++)
	{
		set<T>::iterator j = b.find(*i);
		if (j != b.end()) {
			ans.insert(*j);
		}
	}
	return ans;
}

template <class T>
set<T> Union(set<T> a, set<T> b)
{
	set<T> ans;
	for (set<T>::iterator i = a.begin(); i != a.end(); i++)
		ans.insert(*i);
	for (set<T>::iterator i = b.begin(); i != b.end(); i++)
		ans.insert(*i);
	return ans;
}

template <class T>
bool close(set<set<T>> a)
{
	for (set<set<T>>::iterator i = a.begin(); i != a.end(); i++)
	for (set<set<T>>::iterator j = i; j != a.end(); j++)
	if (a.find(Union(*i, *j)) == a.end() || a.find(intersect(*i, *j)) == a.end())
		return false;
	return true;
}

int main()
{

	set<point> a;
	for (int i = 0; i < 5; i++)
	{
		point t;
		cin >> t;
		a.insert(t);
	}
	
	set <set <point> > b;
	for (int i = 0; i < (1 << a.size()); i++) {
		set<point> temp;
		set<point>::iterator it = a.begin();
		int t = i;
		while (t > 0)
		{
			if ((t % 2))
				temp.insert(*it);
			t /= 2;
			it++;
		}
		b.insert(temp);


	}

	cout << "Set B is: " << endl;
	for (set<set<point>>::iterator i = b.begin(); i != b.end(); i++)
	{
		cout << "{";
		for (set<point>::iterator j = (*i).begin(); j != (*i).end(); j++)
			cout << *j << " ";
		cout << "}" << endl;
	}
	
	cout << " closed : " << close(b);
	

	int x;
	cin >> x;
}
