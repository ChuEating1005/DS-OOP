#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
public:
    void push(int value) {
		// TODO
        if(heap.empty())
        {
            heap.push_back(0);
            heap.push_back(value);
            return;
        }
        heap.push_back(value);
        shiftUp(size());
    }

    int top() {
        // TODO
        if(heap.empty()) return 0;
        else return heap[1];
    }

    void pop() {
		// TODO
        heap[1] = heap[size()];
        heap.pop_back();
        shiftDown(1);
        
    }

    size_t size() {
      	// TODO
        return heap.size()-1;
    }

private:
    vector<int> heap;

    void shiftUp(int index) {
        while (index > 1) {
			// TODO
            if(heap[index/2]<=heap[index]) break;
            swap(index,index/2);
            index /= 2;
        }
    }

    void shiftDown(int index) {
        while (true) {
			// TODO
            if(2*index > (int)size()) break;
            if(2*index == (int)size()) 
            {
                if(heap[index] > heap[2*index])
                    swap(index,2*index);
                break;
            }
            int i = 2*index;
            if(heap[2*index]>heap[2*index+1]) i = 2*index+1;
            if(heap[index] > heap[i] )
            {
                swap(index,i);
                index = i;
            }
            else 
                break;
        }
    }
    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
};

int main() {
    int N;
    while (cin >> N && N != 0) {
        MinHeap min_heap;
        int num;
        for (int i = 0; i < N; i++) {
            cin >> num;
            min_heap.push(num);
        }

        int total_cost = 0;
        while (min_heap.size() > 1) {
            int a = min_heap.top();
            min_heap.pop();
            int b = min_heap.top();
            min_heap.pop();
            int cost = a + b;
            total_cost += cost;
            min_heap.push(cost);
        }

        cout << total_cost << endl;
    }

    return 0;
}