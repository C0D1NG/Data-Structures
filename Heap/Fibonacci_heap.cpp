//Implementation of Fibonacci Heap


#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
using namespace std;

struct FibHeapNode
{
	int key;
	int degree;
	FibHeapNode* parent;
	FibHeapNode* child;
	FibHeapNode* left;
	FibHeapNode* right;
	bool mark;
};

const char* conversions(int x) {
	stringstream strs;
	strs << x;
	string temp_str = strs.str();
	const char* char_type = temp_str.c_str();
	return char_type;
}

void printNode(FibHeapNode* x) {
	cout << "Key: " << x -> key << " degree: " << x -> degree << " Marked: " << ((x -> mark) ? "yes" : "no") << " Parent: " << ((x -> parent == nullptr) ? "RootList, no parent" : conversions(x -> parent -> key)) << " Left: " << x -> left -> key << " Right: " << x -> right -> key << " Has Child:" << ((x -> child == nullptr) ? "no" : "yes") << '\n';
}

class FibonacciHeap
{
private:
	FibHeapNode* min_heapNode;
	int min_heapNumOfNodes;
	FibHeapNode* _createNode(int value);
	FibHeapNode* _merge(FibHeapNode* a, FibHeapNode* b);
	void _unparent(FibHeapNode* node);
	void _removeFromCircularList(FibHeapNode* x);
	void _consolidate();
	void _fibHeapLink(FibHeapNode* child, FibHeapNode* parent);
	void _printHeap(FibHeapNode* x);
	void _cut(FibHeapNode* x, FibHeapNode* y);
	void _cascadeCut(FibHeapNode* y);
public:
	FibonacciHeap() {
		min_heapNode = nullptr;
		min_heapNumOfNodes = 0;
	}
	~FibonacciHeap() {}
	int getMin() {
		return min_heapNode -> key;
	}
	FibHeapNode* insert(int value);
	void fibHeapUnion(FibonacciHeap &another);
	int extractMin();
	void decreaseKey(FibHeapNode* x, int newValue);
	void deleteNode(FibHeapNode* x);
	void clear(FibHeapNode x);
	void printHeap();
};

void FibonacciHeap::_printHeap(FibHeapNode* x) {
	FibHeapNode* iter = x;
	do
	{
		printNode(iter);
		if (iter -> child != nullptr)
		{
			_printHeap(iter -> child);
		}
		iter = iter -> right;
	} while (iter != x);
}

FibHeapNode* FibonacciHeap::_createNode(int value) {
	FibHeapNode* newNode = new FibHeapNode;
	newNode -> key = value;
	newNode -> degree = 0;
	newNode ->  parent = nullptr;
	newNode -> child = nullptr;
	newNode -> left = newNode;
	newNode -> right = newNode;
	newNode -> mark = false;
	return newNode;
}

FibHeapNode* FibonacciHeap::_merge(FibHeapNode* a, FibHeapNode* b) {
	if (a == nullptr)
	{
		return b;
	}
	if (b == nullptr)
	{
		return a;
	}
	if (a -> key > b -> key)
	{
		FibHeapNode* temp = a;
		a = b;
		b = temp;
	}
	FibHeapNode* aRight = a -> right;
	FibHeapNode* bLeft = b -> left;
	a -> right = b;
	b -> left = a;
	bLeft -> right = aRight;
	aRight -> left = bLeft;
	return a;
}

void FibonacciHeap::_unparent(FibHeapNode* node) {
	if (node == nullptr)
	{
		return ;
	}
	FibHeapNode* y = node;
	do
	{
		y -> parent = nullptr;
		y -> right;
	} while (y != node);
}

void FibonacciHeap::_removeFromCircularList(FibHeapNode* x) {
	if (x -> right == x)
	{
		return ;
	}
	FibHeapNode* rightOfx = x -> right;
	FibHeapNode* leftOfx = x -> left;
	rightOfx -> left = x -> left;
	leftOfx -> right = x -> right;
}

void FibonacciHeap::_fibHeapLink(FibHeapNode* child, FibHeapNode* parent) {
	_removeFromCircularList(child);
	child -> left = child -> right = child;
	parent -> child = _merge(parent -> child, child);
	child -> parent = parent;
	parent -> degree++;
	child -> mark = false;
}

void FibonacciHeap::_consolidate() {
	int Dn = (int) (log2(min_heapNumOfNodes) / log2(1.618));
	FibHeapNode** auxilary = new FibHeapNode* [Dn + 1];
	//cout << "Dn: " << Dn << '\n';
	for (int i = 0; i < Dn + 1; ++i)
	{
		auxilary[i] = nullptr;
	}
	FibHeapNode* x = min_heapNode;
	int d;
	bool breakFlag = false;
	do
	{
		d = x -> degree;
		while(auxilary[d] != nullptr) {
			FibHeapNode* y = auxilary[d];
			if (y == x)
			{
				breakFlag = true;
				break;
			}
			if (y -> key < x -> key)
			{
				FibHeapNode* temp = y;
				y = x;
				x = temp;
			}
			_fibHeapLink(y, x);
			auxilary[d] = nullptr;
			d++;
		}
		if (breakFlag)
		{
			break;
		}
		auxilary[d] = x;
		x = x -> right;
	} while (true);
	min_heapNode = x;
	FibHeapNode* iter = x;
	do
	{
		if (iter -> key < min_heapNode -> key)
		{
			min_heapNode = iter;
		}
		iter = iter -> right;
	} while (iter != x);
	delete []auxilary;
}

void FibonacciHeap::_cut(FibHeapNode* x, FibHeapNode* y) {
	_removeFromCircularList(x);
	y -> degree--;
	if (x -> right == x)
	{
		y -> child = nullptr;
	} else {
		y -> child = x -> right;
	}
	x -> left = x -> right = x;
	_merge(min_heapNode, x);
	x -> parent = nullptr;
	x -> mark = false;
}

void FibonacciHeap::_cascadeCut(FibHeapNode* y) {
	FibHeapNode* z = y -> parent;
	if (z != nullptr)
	{
		if (y -> mark == false)
		{
			y -> mark = true;
		} else {
			_cut(y, z);
			_cascadeCut(z);
		}
	}
}

FibHeapNode* FibonacciHeap::insert(int value) {
	FibHeapNode* newNode = _createNode(value);
	if (min_heapNode == nullptr)
	{
		min_heapNode = newNode;
		min_heapNumOfNodes++;
		return newNode;
	}
	FibHeapNode* lastNode = min_heapNode -> left;
	lastNode -> right = newNode;
	min_heapNode -> left = newNode;
	newNode -> right = min_heapNode;
	newNode -> left = lastNode;
	if (min_heapNode -> key > newNode -> key)
	{
		min_heapNode = newNode;
	}
	min_heapNumOfNodes++;
	return newNode;
}

void FibonacciHeap::fibHeapUnion(FibonacciHeap &another) {
	FibHeapNode* lastNodeOfCurrFibHeap = min_heapNode -> left;
	FibHeapNode* lastNodeOfAnotherFibHeap = another.min_heapNode ->left;
	lastNodeOfCurrFibHeap -> right = another.min_heapNode;
	another.min_heapNode -> left = lastNodeOfCurrFibHeap;
	min_heapNode -> left = lastNodeOfCurrFibHeap;
	lastNodeOfAnotherFibHeap -> right = min_heapNode;
	if (min_heapNode -> key > another.min_heapNode -> key)
	{
		min_heapNode = another.min_heapNode;
	}
	min_heapNumOfNodes += another.min_heapNumOfNodes;
}

int FibonacciHeap::extractMin() {
	FibHeapNode* z = min_heapNode;
	if (z != nullptr)
	{
		_unparent(z -> child);
		_merge(z, z -> child);
		_removeFromCircularList(z);
		if (z == z -> right)
		{
			min_heapNode = nullptr;
		}
		else {
			min_heapNode = z -> right;
			_consolidate();
		}
		--min_heapNumOfNodes;
		int value = z -> key;
		delete z;
		return value;
	}
	return -9999;
}

void FibonacciHeap::decreaseKey(FibHeapNode *x, int newValue) {
	if (newValue > x -> key)
	{
		cout << "new key is greater than previous key";
		return;
	}
	x -> key = newValue;
	cout << "min node: " << min_heapNode -> key << '\n';
	// _printHeap(min_heapNode);
	FibHeapNode* y = x -> parent;
	if (y != nullptr && (x -> key < y -> key))
	{
		_cut(x, y);
		_cascadeCut(y);
	}
	if (x -> key < min_heapNode -> key)
	{
		min_heapNode = x;
	}
}

void FibonacciHeap::deleteNode(FibHeapNode* x) {
	decreaseKey(x, -99999);
	extractMin();
}

void FibonacciHeap::printHeap() {
	cout << "No Of Nodes: " << min_heapNumOfNodes << '\n';
	_printHeap(min_heapNode);
}

int main(int argc, char const *argv[])
{
	int arr[] = {23, 7, 17, 24, 15, 32};
	FibonacciHeap* newHeap = new FibonacciHeap();
	FibHeapNode** arrFib = new FibHeapNode* [6];
	for (int i = 0; i < 6; ++i)
	{
		arrFib[i] = newHeap -> insert(arr[i]);
	}
	newHeap -> printHeap();
	cout << "Extract Min" << '\n';
	cout << newHeap -> extractMin() << '\n';
	newHeap -> printHeap();
	cout << "Decrease Key" << '\n';
	newHeap -> decreaseKey(arrFib[0], 10);
	newHeap -> printHeap();
	return 0;
}
