#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numElements;
    cin >> numElements;
    vector<int> values(numElements);
    int minimum = 1e9;
    int minIndex = -1;
    int totalSum = 0;

    for (int i = 0; i < numElements; i++) {
        cin >> values[i];
        if (minimum > values[i]) {
            minimum = values[i];
        }
        totalSum += values[i];
    }

    totalSum -= minimum;
    cout << (numElements - 1) * minimum + totalSum << endl;

    return 0;
}
