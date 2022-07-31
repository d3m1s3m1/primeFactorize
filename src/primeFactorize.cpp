#include <iostream>
#include <map>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

void increment(uint1024_t *i)
{
    if (*i == 2)
    {
        ++*i;
    }
    else
    {
        *i = *i + 2;
    }
}

void incrementPrimes(map<uint1024_t, uint64_t>* ans, uint1024_t i)
{
    if (ans->find(i) == ans->end())
    {
        (*ans)[i] = 1;
    }
    else
    {
        (*ans)[i] = (*ans)[i] + 1;
    }
}

int main()
{
    uint1024_t start = 2;
    uint1024_t goal;
    cin >> goal;
    map<uint1024_t, uint64_t> ans;

    while (true)
    {
        bool isPrime = true;
        for (uint1024_t i = start; i <= sqrt(goal); increment(&i))
        {
            if (goal % i == 0)
            {
                start = i;
                goal /= i;
                incrementPrimes(&ans, i);
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            incrementPrimes(&ans, goal);
            break;
        }
    }
    for (auto const &entry : ans)
    {
        // Adds an unnecessary * at the end
        cout << entry.first << "^" << entry.second << " * ";
    }
}