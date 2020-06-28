
// Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

// Input
// The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

// Output
// For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
// https://www.spoj.com/problems/PRIME1/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> p(100000, 0);
vector<int> primes;
void sieve()
{
    primes.push_back(2);
    for (ll i = 3; i < 100000; i += 2)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);
            for (ll j = i * i; j < 100000; j += i)
                p[j] = 1;
        }
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> m >> n;
        bool segment[n - m + 1];
        for (ll i = 0; i < n - m + 1; i++)
            segment[i] = 0;

        for (auto x : primes)
        {
            // end point to stop iterating the primes
            if (x * x > n)
                break;
            int start = (m / x) * x;

            // if the number is the prime itself start from next multiple
            if (x >= m and x <= n)
            {
                start = x * 2;
            }
            for (ll i = start; i <= n; i += x)
            {
                segment[i - m] = 1;
            }
        }
        for (int i = m; i <= n; i++)
        {
            if (segment[i - m] == 0 and i != 1)
                cout << i << "\n";
        }
        
        cout << endl;
    }
}