#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

int isPrimeHalf(int number) {
    if (number <= 1) return 0; // Not prime

    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) return 0; // Not prime
    }

    return 1; // Prime
}

int isPrimeSquareRoot(int number) {
    if (number <= 1) return 0; // Not prime

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return 0; // Not prime
    }

    return 1; // Prime
}

double benchmark(int (*isPrime)(int), int limit, vector<int>& primes) {
    auto start{chrono::high_resolution_clock::now()};

    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    auto stop{chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> elapsed{stop - start};
    return elapsed.count();
}

int main()
{
    const int limit{200000};
    vector<int> primesHalf;
    vector<int> primesSquareRoot;

    cout << "A factor larger than the square root of n must be paired with ";
    cout << "a factor smaller than the square root of n." << endl;
    cout << "So if no divisor is found by sqrt(n), no later divisor can prove ";
    cout << "that n is composite." << endl << endl;

    cout << "Check 1: " << isPrimeSquareRoot(1) << endl;
    cout << "Check 2: " << isPrimeSquareRoot(2) << endl;
    cout << "Check 3: " << isPrimeSquareRoot(3) << endl;
    cout << "Check 4: " << isPrimeSquareRoot(4) << endl;
    cout << "Check 5: " << isPrimeSquareRoot(5) << endl;
    cout << "Check 6: " << isPrimeSquareRoot(6) << endl;
    cout << "Check 7: " << isPrimeSquareRoot(7) << endl;
    cout << "Check 8: " << isPrimeSquareRoot(8) << endl;
    cout << "Check 9: " << isPrimeSquareRoot(9) << endl;
    cout << "Check 10: " << isPrimeSquareRoot(10) << endl;
    cout << "Check 11: " << isPrimeSquareRoot(11) << endl << endl;

    double halfTime{benchmark(isPrimeHalf, limit, primesHalf)};
    double squareRootTime{benchmark(isPrimeSquareRoot, limit, primesSquareRoot)};

    cout << "Primes found from 2 through " << limit << ": ";
    cout << primesSquareRoot.size() << endl;
    cout << "Using n / 2 limit: " << halfTime << " ms" << endl;
    cout << "Using sqrt(n) limit: " << squareRootTime << " ms" << endl;
    cout << "Performance improvement: ";
    cout << halfTime / squareRootTime << " times faster" << endl << endl;

    cout << "First 25 primes:" << endl;
    for (size_t i = 0; i < primesSquareRoot.size() && i < 25; ++i) {
        cout << primesSquareRoot[i] << '\t';
    }
    cout << endl;

    return 0;
}
