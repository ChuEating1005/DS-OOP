#include <bits/stdc++.h>
using namespace std;
class MinHeap {
private:
    vector<int> heap;
	int parent(int i){ return (i - 1) / 2; }
    int lChild(int i){ (2 * i + 1); }
    int rChild(int i){ (2 * i + 2); }
		void swap(int i, int j) 
		{
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
	void heapifyUp(int); 
	void heapifyDown(int);
public:
    void insertKey(int);
    void deleteKey(int);
    int getMin();
    int extractMin();
    int getSize();
};

void MinHeap::heapifyUp(int index) 
{
    while (index > 0 && heap[index] < heap[parent(index)]) 
	{
        swap(index, parent(index));
        index = parent(index);
    }
}
void MinHeap::heapifyDown(int index) 
{
    int smallest = index;
    int left = lChild(index);
    int right = rChild(index);

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(index, smallest);
        heapifyDown(smallest);
    }
}
void MinHeap::insertKey(int key) 
{
    heap.push_back(key);
    int index = heap.size() - 1;
    heapifyUp(index);
}

void MinHeap::deleteKey(int key) 
{
    if (heap.empty()) 
    {
        cout << "Empty" << endl;
        return;
    }
    int index = -1;
    for (int i = 0; i < heap.size(); i++) 
    {
        if (heap[i] == key) 
        {
            index = i;
            break;
        }
    }

    if (index == -1) 
    {
        cout << "Key not found" << endl;
        return;
    }

    swap(index, heap.size() - 1); //將該以點的值換成最後一個點的值
    heap.pop_back();
    heapifyDown(index);
}
int MinHeap::getMin() 
{
    if (heap.empty()) 
    {
        cout << "Empty" << endl;
        return -1;
    }
    return heap[0];
}
int MinHeap::extractMin()
{
    if (heap.empty()) 
    {
        cout << "Empty" << endl;
        return -1; // or any other suitable value
    }

    int minVal = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
    return minVal;
}
int MinHeap::getSize() 
{
    return heap.size();
}


int main() {
    MinHeap binaryHeap;
    binaryHeap.insertKey(5);
    binaryHeap.insertKey(10);
    binaryHeap.insertKey(3);
    binaryHeap.insertKey(8);

    std::cout << "Minimum value: " << binaryHeap.getMin() << std::endl;

    binaryHeap.deleteKey(3);

    while (!binaryHeap.getSize()) {
        std::cout << "Extracted minimum value: " << binaryHeap.extractMin() << std::endl;
    }

    return 0;
}