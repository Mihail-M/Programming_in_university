#pragma once
const int inf = 10e9;

/// Segment tree for min on segment
class SegmentTree
{
public:
	SegmentTree(int *a, int _size);
	~SegmentTree();
	int min(int left, int right);
	void print();
	void update(int i, int value);
private:
	void build(int *a, int _size);


	int *tree;
	int size;
};

