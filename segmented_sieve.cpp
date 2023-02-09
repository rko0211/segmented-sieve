#include <bits/stdc++.h>
using namespace std;

int  n = 1000000;
bool sieve[1000001];

void createseive()
{
    // O(nloglogn)

    for (int i = 2; i <= n; i++)
    {
        // Initially all are primes
        sieve[i] = true;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i]==true)
        {
            for (int j = i * i; j <= n; j +=i)
            {
                // Not prime number
                sieve[i] = 0;
            }
        }
    }
}
vector<int> findallprimes(int p)
{
    vector<int> allprimes;
    for (int i = 2; i <= p; i++)
    {
        if (sieve[i]==true)
        {
            allprimes.push_back(i);
        }
    }
    return allprimes;
}

int main()
{
    createseive();

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        //    Step 1
        //  We have to store all the primes present till sqrt(r);

        vector<int> primes = findallprimes(sqrt(r));
        // Step 2
        // Creat a dummy array of size (r-l+1) and mark that with 1;

        int dummy[r - l + 1];
        for (int i = 0; i < (r - l + 1); i++)
        {
            dummy[i] = 1;
        }

        // Step 3
        // Mark all multiples of primes in l to r in dummy array;

        for (auto pr : primes)
        {
            int firstmultiples = (l / pr) * pr;
            if (firstmultiples < l)
            {
                firstmultiples += pr;
            }
            // We have iterate on each multiple of primes;
            for (int j = max(firstmultiples, pr * pr); j <= r; j += pr)
            {
                dummy[j - l] = 0;
            }
        }
        // Step 4 get all the primes
        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l]==1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}