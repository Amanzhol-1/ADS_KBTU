
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    long n;
    cin>>n;
    vector<long long> hs(n);
    for(int i=0;i<n;i++){
        cin>>hs[i];
    }
    string s = "";
    s += char(hs[0] + 97);
    
    for(int i=1;i<n;i++){ // выполняю обратные действия
        long long res = 2;
        for(int j=0;j<i-1;j++){
            res *= 2;
        }
        s += char((hs[i]-hs[i-1])/res) + 97;
    }
    cout<<s;
}