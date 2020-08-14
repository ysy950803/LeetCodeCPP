#include <iostream>
#include <vector>

using namespace std;

class Solution204 {
public:
    bool isPrime(int i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) ++count;
        }
        return count;
    }

    int countPrimes2(int n) {
        if (n <= 2) return 0;

        bool primes[n];
        for (int i = 0; i < n; ++i) {
            primes[i] = true;
        }

        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (primes[i]) ++count;
        }
        return count;
    }

    // BEST
    int countPrimes3(int n) {
        if (n <= 2) return 0;

        bool primes[n];
        for (int i = 0; i < n; ++i) {
            primes[i] = true;
        }

        int count = n - 2;
        for (int i = 2; i * i <= n; ++i) {
            cout << "i " << i << endl;
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (primes[j]) {
                        cout << "j " << j << endl;
                        primes[j] = false;
                        --count;
                    }
                }
            }
        }

//        int count = 0;
//        for (int i = 2; i < n; ++i) {
//            if (primes[i]) ++count;
//        }
        return count;
    }
};

void test204() {
    cout << Solution204().countPrimes3(25);
}
