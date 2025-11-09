#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Heap {
private:
    vector<pair<int, int>> data;  

    void moveUpward(int index) {
        if (index == 0) return;  
        int parent = (index - 1) / 2;

        if (data[index].second > data[parent].second) {
            swap(data[index], data[parent]);
            moveUpward(parent); 
        }
    }

    void moveDownward(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int highest = index;

        if (left < data.size() && data[left].second > data[highest].second)
            highest = left;
        if (right < data.size() && data[right].second > data[highest].second)
            highest = right;

        if (highest != index) {
            swap(data[index], data[highest]);
            moveDownward(highest);
        }
    }

public:

    void addNode(int value, int priority) {
        data.push_back({value, priority});
        moveUpward(data.size() - 1);
    }

    pair<int, int> popMax() {
        if (data.empty()) {
            cout << "Heap is empty!" << endl;
            return {-1, -1};
        }

        pair<int, int> maxElem = data[0];
        data[0] = data.back();
        data.pop_back();
        moveDownward(0);
        return maxElem;
    }

    pair<int, int> popMin() {
        if (data.empty()) {
            cout << "Heap is empty!" << endl;
            return {-1, -1};
        }

        int minIdx = 0;
        for (int i = 1; i < data.size(); ++i) {
            if (data[i].first < data[minIdx].first)
                minIdx = i;
        }

        pair<int, int> minElem = data[minIdx];
        data[minIdx] = data.back();
        data.pop_back();

        if (minIdx < data.size()) {
            moveDownward(minIdx);
            moveUpward(minIdx);
        }

        return minElem;
    }

    void showQueue() {
        for (auto &i : data) {
            cout << "(" << i.first << ", " << i.second << ")" << endl;
        }
        cout << endl;
    }

    void showHeap() {
        for (auto &i : data)
            cout << i.first << " ";
        cout << endl;
    }
};

class PriorityQueue {
private:
    Heap heapObj;

public:
    void addWithPriority(int value, int priority) {
        heapObj.addNode(value, priority);
    }

    pair<int, int> getHighestPriority() {
        return heapObj.popMax();
    }

    void displayQueue() {
        heapObj.showQueue();
    }
};

void heapSort(vector<pair<int, int>>& arr) {
    Heap heap;

    for (auto &val : arr)
        heap.addNode(val.first, val.second);

    for (int i = arr.size() - 1; i >= 0; --i)
        arr[i] = heap.popMax();
}

int main() {
    Heap heap;
    PriorityQueue pq;
    vector<pair<int, int>> v;
    int choice;

    cout << "Select operation:\n";
    cout << "1 - Heap operations\n2 - Priority Queue\n3 - Heap Sort\n";
    int select;
    cin >> select;

    switch (select) {

        case 1:
            cout << "1 - Add element\n2 - Extract Max\n3 - Extract Min\n4 - Print Heap\n5 - Exit\n";
            while (cin >> choice) {
                if (choice == 1) {
                    cout << "Value: ";
                    int val; cin >> val;
                    heap.addNode(val, val);
                } 
                else if (choice == 2) {
                    cout << "Max element: " << heap.popMax().first << endl;
                } 
                else if (choice == 3) {
                    cout << "Min element: " << heap.popMin().first << endl;
                } 
                else if (choice == 4) {
                    cout << "Heap: ";
                    heap.showHeap();
                    cout << endl;
                } 
                else if (choice == 5) break;
                cout << "1 - Add element\n2 - Extract Max\n3 - Extract Min\n4 - Print Heap\n5 - Exit\n";
            }
            break;

        case 2:
            cout << "1 - Insert element\n2 - Extract Highest Priority\n3 - Show Queue\n4 - Exit\n";
            while (cin >> choice) {
                if (choice == 1) {
                    int val, pr;
                    cout << "Value: "; cin >> val;
                    cout << "Priority: "; cin >> pr;
                    pq.addWithPriority(val, pr);
                } 
                else if (choice == 2) {
                    cout << "Highest Priority Element: " << pq.getHighestPriority().first << endl;
                } 
                else if (choice == 3) {
                    cout << "Priority Queue:\n";
                    pq.displayQueue();
                } 
                else if (choice == 4) break;
                cout << "1 - Insert element\n2 - Extract Highest Priority\n3 - Show Queue\n4 - Exit\n";
            }
            break;

        case 3:
            int n;
            cout << "Array size: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; ++i) {
                int x; cin >> x;
                v.push_back({x, x});
            }
            heapSort(v);
            cout << "Sorted Array: ";
            for (auto &el : v)
                cout << el.first << " ";
            cout << endl;
            break;
    }

    return 0;
}