#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<long long>& arr, int N, int i) {
    int min = i;
    int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < N && arr[left] < arr[min]) {
        min = left;
    }
    if (right < N && arr[right] < arr[min]) {
        min = right;
    }
    if (min != i) {
        swap(arr[i], arr[min]);
        heapify(arr, N, min);
    }
}

void build_heap(vector<long long>& arr) { //min
    int N = arr.size();

    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

int main() {
    long long cnt = 0; int N = 0;
    vector<long long> arr;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    build_heap(arr);

    while (arr.size() > 1) {
        long long smallest1 = arr[0];//первый самый малый элемент выбираем его из массива
        arr[0] = arr.back(); //"меняем" его на последний и удаляем последний
        arr.pop_back();
        heapify(arr, arr.size(), 0);//востанавливаем кучу
        long long smallest2 = arr[0];//тоже самое
        arr[0] = arr.back();
        arr.pop_back();
        heapify(arr, arr.size(), 0);
        long long sum = smallest1 + smallest2;
        cnt += sum;
        arr.push_back(sum);
        heapify(arr, arr.size(), arr.size() - 1);//восстанавливаем кучу после вставки суммы начиная с последнего которого мы всавили
    }

    cout << cnt << endl;
}