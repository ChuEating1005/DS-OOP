#include <iostream>
// please note that you are not allowed to include any container, such as <vector>, <list>, <queue>
using namespace std;


struct ListNode{
    // TODO: define your own ListNode with data and a pointer points to the next ListNode.
    int data;
    ListNode* next;
};

class Queue {
public:
    Queue(): head(nullptr), tail(nullptr) {}

    void push(int data) {
        // TODO: add a new data in the queue.
        ListNode* node = new ListNode;
        node->data = data;
        node->next = NULL;
        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    void pop() {
        // TODO: pop a data from the queue,
        //       remember to deal with the case when there's already empty in the queue.
        if(!isEmpty())
        {
            ListNode* del = head;
            head = head->next;
            cout << del->data << endl;
            delete del;
        }
        else
            cout << "Invalid.\n-1\n";
        
    }

    bool isEmpty() {
        // TODO: return true if the queue is empty, otherwise, false.
        if(head == NULL) 
            return true;
        else
            return false;
    }

    void printQueue() {
        if(isEmpty())
        {
            cout << "Empty Queue.\n";
        }
        else
        {
            cout << "Queue: ";
            // TODO: output all the data in the queue.
            ListNode* temp = head;
            while(temp!=NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }   
    }

private:
    ListNode* head;
    ListNode* tail;
};

int main()
{
    Queue q;

    int num;
    while (cin >> num && num != -1){
        // TODO: create the initial queue
        q.push(num);
    }


    int selection; // selection: 1->push, 0->pop, -1->end
    while (cin >> selection && selection != -1){
        // TODO: allows user to do push or pop
        if(selection == 1)
        {
            int data;
            cin >> data;
            q.push(data);
        }
        else if(selection == 0)
        {
            q.pop();
        }
    }
    q.printQueue();
    // TODO: print every data in the queue at the end,
    //       you can check the empty case by using isEmpty() you create.


    return 0;
}