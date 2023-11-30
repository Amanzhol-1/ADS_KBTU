#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Date {
public:
    Date(string dateStr) : dateStr(dateStr) {}
    bool operator<(const Date& other) {
        if (getYear() < other.getYear()) {
            return true;
        } else if (getYear() > other.getYear()) {
            return false;
        } else {
            if (getMonth() < other.getMonth()) {
                return true;
            } else if (getMonth() > other.getMonth()) {
                return false;
            } else {
                return getDay() <= other.getDay();
            }
        }
    }
private:
    string dateStr;
    int getYear() const {
        return stoi(dateStr.substr(6, 4));
    }  
    int getMonth() const {
        return stoi(dateStr.substr(3, 2));
    }
    int getDay() const {
        return stoi(dateStr.substr(0, 2));
    }
};

int partition(string arr[], int l, int r) {
    string pivot = arr[r];
    int pIndex = l;
    for (int i = l; i < r; i++) {
        if (Date(arr[i]) < Date(pivot)) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(string arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main() {
    int n; cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}