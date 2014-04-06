#include "segmenttree.h"
#include <iostream>
#include <cmath>


int toPower2(int size)
{
	int l;
	int k;
	for (k = size; (l = k & (k - 1)) != 0; k = l);
	return (size + (k - 1)) & (~(k - 1));
}
SegmentTree::SegmentTree(int *a, int _size)
{
	int n = toPower2(_size);
	int *t = new int[n];

	for (int i = 0; i < _size; i++)
		t[i] = a[i];
	for (int i = _size; i < n; i++)
		t[i] = inf;

	tree = new int[2*n];
	build(t, n);
	size = n;
}

SegmentTree::~SegmentTree()
{
	delete[] tree;
}

void SegmentTree::build(int *a, int _size)
{
	for (int i = _size; i <= 2 * _size; i++)
		tree[i] = a[i - _size];

	for (int i = _size - 1; i > 0; i--)
		tree[i] = std::min(tree[2 * i], tree[2 * i + 1]);

}


int SegmentTree::min(int left, int right)
{
	int ans = inf;
	int n = size;
	left += n - 1, right += n - 1;

	while (left <= right)
	{
		if (left & 1)
			ans = std::min(ans, tree[left]);

		if (!(right & 1))
			ans = std::min(ans, tree[right]);

		left = (left + 1) / 2, right = (right - 1) / 2;
	}
	return ans;
}

void SegmentTree::print()
{
	for(int i = 1; i < 2*size; i++){
		if (tree[i] == inf)
			std::cout << "inf" << " ";
		else std::cout << tree[i] << " ";

	}
	std::cout << std::endl;
}

void SegmentTree::update(int i, int value)
{
	int n = size;
	i += n - 1;
	tree[i] = value;
	while (i /= 2)
		tree[i] = std::min(tree[2 * i], tree[2 * i + 1]);
}

