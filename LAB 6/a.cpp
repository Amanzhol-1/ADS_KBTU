#include <iostream>
#include <vector>

using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}
int left(int i) {
    return 2 * i + 1;
}
int right(int i) {
    return 2 * i + 2;
}

void insertToHeap(vector<char>& heap, char value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[parent(i)] > heap[i]) {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void heapify(vector<char>& heap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap.size() && heap[l] < heap[smallest]) {
        smallest = l;
    }
    if (r < heap.size() && heap[r] < heap[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(heap[smallest], heap[i]);
        heapify(heap, smallest);
    }
}

char extractMin(vector<char>& heap) {
    if (heap.size() == 1) {
        char root = heap[0];
        heap.pop_back();
        return root;
    }
    char root = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(heap, 0);
    return root;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<char> vowelsHeap; vector<char> consonantsHeap;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            insertToHeap(vowelsHeap, s[i]);
        } else {
            insertToHeap(consonantsHeap, s[i]);
        }
    }
    while (!vowelsHeap.empty()) {
        cout << extractMin(vowelsHeap);
    }
    while (!consonantsHeap.empty()) {
        cout << extractMin(consonantsHeap);
    }
    cout << endl;
    return 0;
}
