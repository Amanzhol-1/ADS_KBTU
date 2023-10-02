#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool isPrime(int n){ // функция для проверки простого числа
    if (n == 1){
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    
    return true;
}

void cntPrimes(vector<int> primes, int n){ // функция для индексации простых чисел 

    for (int i = 2; i <= 1000000; i++){ // 1 лям = 1000 в квадрате 
        if (isPrime(i) == true){
            primes.push_back(i);
        }
    }

    cout << primes[n - 1]; 
}

int main(){
    int n; cin >> n;
    vector <int> primes;
    cntPrimes(primes, n);
}