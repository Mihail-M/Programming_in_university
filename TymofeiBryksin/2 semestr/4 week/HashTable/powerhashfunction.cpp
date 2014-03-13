#include "powerhashfunction.h"


int PowerHashFunction::calculateHashFunction(std::string s, int size)
{
    const int p = 31;
    unsigned int hash = 0, p_pow = 1;
    int count = s.size();
    for (int i=0; i < count; i++)
    {
        hash += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return hash%size;
}
