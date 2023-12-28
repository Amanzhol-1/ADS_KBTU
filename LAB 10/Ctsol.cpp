
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int A;
    int B;
    int buf = B;
    int cnt = 0;
    vector<int> o;
    cin>>A>>B;
    o.push_back(B);
    while(A!=B){ 
        if(B > A){  //начиниаем обратный алгоритм с обратными действиями  начинаяя с конца
            if(B % 2 == 0){
                B = B / 2; 
                o.push_back(B);
            }
            else{
                B += 1;  
                o.push_back(B);
            }
            cnt++;
        }
        else if(B < A){
            B += 1;
            o.push_back(B);
            cnt++;
        }
    }
    cout<<cnt<<endl;  // вывод кол во шагов для того чтобы сделать из А B
    for(int i=o.size()-2;i>=0;i--){
        cout<<o[i]<<" ";
    }
}
// вот ты дебил забыл этот алгоритм?
// 7 24
// (7-1)*2*2 = 24
// (24/2)/2+1 = 7