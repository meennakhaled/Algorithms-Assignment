// Anas Ibrahim Safwat
// 20220068
// IT-S1&S2
// Task-3 , Part[B]

#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<pair<int,int>> heap;

    // (for insertion)
    void heapifyUp(int index) {
        if (index == 0) return; //stop at root
        int parent = (index - 1) / 2;

        // if current node's priority is greater than parent's I will swap them
        if (heap[index].second > heap[parent].second) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent); //Recursive over the tree
        }
    }

    // (for extraction)
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        //checking which one from the right and left child is the largest one and then swap the current node with the largest one of them
        if (leftChild < heap.size() && heap[leftChild].second > heap[largest].second) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].second > heap[largest].second) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:

    void insert(int value , int priority) {
        heap.push_back({value,priority});
        heapifyUp(heap.size() - 1);
    }

    pair<int,int> extractMax() {
        if (heap.empty()){
            cout << "Heap is empty!" << endl;
            return {-1,-1};
        }

        //root is the max element. so I save it in a temp node "max" and pop it from the heap then return "max"
        pair<int,int> max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    pair<int,int> extractMin() {
        if (heap.empty()){
            cout << "Heap is empty!" << endl;
            return {-1,-1};
        }


        int minIndex = 0; //assuming first element is the minimum, then loop through the heap to find the min index
        for (int i = 1; i < heap.size() ; ++i) {
            if(heap[i].first < heap[minIndex].first){
                minIndex = i;
            }
        }

        pair<int,int> min = heap[minIndex];
        heap[minIndex] = heap.back();
        heap.pop_back();
        if(minIndex < heap.size()){
            heapifyDown(minIndex);
            heapifyUp(minIndex);
        }
        return min;
    }

    void printQueue() {
        for (auto &i : heap) {
            cout << "(" << i.first << ", " << i.second  << ")" << endl;
        }
        cout << endl;

    }
    void printHeap() {
        for (auto &i : heap) {
            cout << i.first << " ";
        }
        cout << endl;
    }



};

class priorityQueue {
private:
    Heap heap;

public:

    void insertWithPriority(int value , int priority) {
        heap.insert(value,priority);
    }

    pair<int,int> extractHighestPriority() {
        return heap.extractMax();
    }

    void printQueue() {
        heap.printQueue();
    }
};

void heapSort(vector<pair<int,int>>& arr) {
    Heap heap;

    for (auto &val : arr) {
        heap.insert(val.first, val.second);
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = heap.extractMax();
    }
}

int main() {
    Heap heap;
    priorityQueue pq;
    vector<pair<int,int>> v;
    int choice;
    cout << "Select what you want to do: " << endl;
    cout << "1- Build a Heap" << endl << "2- Build a Priority Queue" << endl << "3- Sort an array using heap sort" << endl;
    int select; cin >> select;

    switch (select) {

        case 1:
            cout << "1- insert an element" << endl << "2- extract max" << endl <<"3- extract min" << endl << "4- print heap" << endl << "5- exit" << endl;

            while(cin >> choice){
                if(choice == 1){
                    cout << "Element: ";
                    int element; cin >> element;
                    heap.insert(element,element);
                }
                else if(choice == 2){
                    cout << "Max element: " << heap.extractMax().first << endl;
                }
                else if(choice == 3){
                    cout << "Min element: " << heap.extractMin().first << endl;
                }
                else if(choice == 4){
                    cout << "Heap: ";
                    heap.printHeap();
                    cout << endl;
                }
                else if(choice == 5){
                    break;
                }
                cout << "1- insert an element" << endl << "2- extract max" << endl <<"3- extract min" << endl << "4- print heap" << endl << "5- exit" << endl;
            }
            break;

        case 2:
            cout << "1- insert an element" << endl << "2- extract max" << endl <<"3- print queue" << endl << "4- exit" << endl;
            while(cin >> choice){
                if(choice == 1){
                    cout << "Element: ";
                    int element; cin >> element;
                    cout << endl << "Priority: ";
                    int priority; cin >> priority;
                    pq.insertWithPriority(element,priority);
                }
                else if(choice == 2){
                    cout << "Max element: " << pq.extractHighestPriority().first << endl;
                }
                else if(choice == 3){
                    cout <<"Priority queue: "; pq.printQueue();
                    cout << endl;
                }
                else if(choice == 4){
                    break;
                }
                cout << "1- insert an element" << endl << "2- extract max" << endl <<"3- print queue" << endl << "4- exit" << endl;
            }
            break;

        case 3:
            int n;
            int e;
            cout << "Size of array: ";
            cin >> n;
            cout << endl << "Enter the array elements: ";
            for (int i = 0; i < n ; ++i) {
                 cin >> e;
                 v.push_back({e,e});
            }
            heapSort(v);
            cout << endl << "Array sorted!" << endl;
            for (int i = 0; i < n ; ++i) {
                cout << v[i].first << " " ;
            }
            cout << endl;
            break;
    }

    return 0;
}
