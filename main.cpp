#include <iostream>
using namespace std;

int main(){
    int A,B;
    
    cin >> A;
    if (A<=0) return 1;
    cin >> B;
    if (B >=10) return 1;
    long double C = (long double)A/(long double)B;
    cout << C << endl;
    
    return 0;
}