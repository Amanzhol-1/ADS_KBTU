#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++){
        deque<int> d;
        for (int j = arr[i]; j >= 1; j--){
            d.push_front(j);
            for (int k = 0; k < j; k++){
                d.push_front(d.back());
                d.pop_back();
            }
        }
        while(!d.empty()){
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << endl;
    }
}   