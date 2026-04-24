#include <iostream>
using namespace std;

long factorial( unsigned long n ) {
    if ( n > 1 )
        return n * factorial( n - 1 );
    else
        return 1;
}

long square( unsigned long n ) {
    return n * n;
}

int main() {

    double n {1}, result {1};
    cout << "Enter a positive integer: ";
    cin >> n;

    while ( n >= 1 ) {
        result += square( n ) / factorial( n );
        --n;
    } 

    cout << "Sum of reciprocals of factorials is: " << result << endl;
    
    return 0;
}
