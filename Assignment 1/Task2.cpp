#include<iostream>
#include<vector>
using namespace std;

// ----------------------
// Sequential Search (Iterative)
// ----------------------
int sequential_search_iter(const vector<int>& a, int target) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == target) return static_cast<int>(i);
    }
    return -1; // not found
}

// ----------------------
// Sequential Search (Recursive)
// ----------------------
// helper with index parameter
int sequential_search_rec_helper(const vector<int>& a, int target, int idx) {
    if (idx >= static_cast<int>(a.size())) return -1; // base: reached end
    if (a[idx] == target) return idx;
    return sequential_search_rec_helper(a, target, idx + 1);
}
int sequential_search_rec(const vector<int>& a, int target) {
    return sequential_search_rec_helper(a, target, 0);
}

// ----------------------
// Binary Search (Iterative)
// Assumes 'a' is sorted in ascending order
// ----------------------
int binary_search_iter(const vector<int>& a, int target) {
    int low = 0;
    int high = static_cast<int>(a.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}

// ----------------------
// Binary Search (Recursive)
// Assumes 'a' is sorted in ascending order
// ----------------------
int binary_search_rec(const vector<int>& a, int target, int low, int high) {
    if (low > high) return -1; // not found
    int mid = low + (high - low) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] < target) return binary_search_rec(a, target, mid + 1, high);
    else return binary_search_rec(a, target, low, mid - 1);
}

// convenience wrapper
int binary_search_rec(const vector<int>& a, int target) {
    return binary_search_rec(a, target, 0, static_cast<int>(a.size()) - 1);
}

// ----------------------
// Demo main
// ----------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ???? ??????
    vector<int> unsorted = { 7, 3, 9, 1, 5 };
    vector<int> sorted_asc = { 1, 3, 5, 7, 9, 11, 13 };

    int t1 = 5;   // ????? ?? unsorted (??? index 4)
    int t2 = 7;   // ????? ?? sorted_asc (index 3)
    int t3 = 4;   // ??? ?????

    cout << "Sequential (iterative) search in unsorted for " << t1 << " -> "
        << sequential_search_iter(unsorted, t1) << "\n";

    cout << "Sequential (recursive) search in unsorted for " << t1 << " -> "
        << sequential_search_rec(unsorted, t1) << "\n";

    cout << "Binary (iterative) search in sorted for " << t2 << " -> "
        << binary_search_iter(sorted_asc, t2) << "\n";

    cout << "Binary (recursive) search in sorted for " << t2 << " -> "
        << binary_search_rec(sorted_asc, t2) << "\n";

    cout << "Binary (iterative) search for missing " << t3 << " -> "
        << binary_search_iter(sorted_asc, t3) << "\n";

    cout << "Sequential (iterative) search for missing " << t3 << " -> "
        << sequential_search_iter(unsorted, t3) << "\n";

    cout << "\nInteractive test: enter n then n numbers (sorted for binary), then a target:\n";
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int target;
    cin >> target;

    cout << "Sequential (iterative) -> " << sequential_search_iter(arr, target) << "\n";
    cout << "Sequential (recursive) -> " << sequential_search_rec(arr, target) << "\n";
    cout << "Binary (iterative)    -> " << binary_search_iter(arr, target) << "\n";
    cout << "Binary (recursive)    -> " << binary_search_rec(arr, target) << "\n";

    return 0;
}
