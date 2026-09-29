#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAXN = 1000000;

long long fact[MAXN + 1];
long long invfact[MAXN + 1];

// Binary exponentiation
long long modpow(long long base, long long exp) {
    long long result = 1;

    base %= MOD;

    while (exp > 0) {

        // If exp is odd
        if (exp & 1) {
            result = (result * base) % MOD;
        }

        // Square the base
        base = (base * base) % MOD;

        // Divide exponent by 2
        exp >>= 1;
    }

    return result;
}

// Precompute factorials and inverse factorials
void precompute() {

    // fact[i] = i!
    fact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // Fermat's Little Theorem:
    // (MAXN!)^(-1) = (MAXN!)^(MOD-2) mod MOD
    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);

    // Calculate remaining inverse factorials backwards
    for (int i = MAXN; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }
}

// Calculate nCr
long long nCr(int n, int r) {

    if (r < 0 || r > n)
        return 0;

    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {

    precompute();

    cout << nCr(5, 2) << endl;          // 10
    cout << nCr(1000000, 500000) << endl;

    return 0;
}
