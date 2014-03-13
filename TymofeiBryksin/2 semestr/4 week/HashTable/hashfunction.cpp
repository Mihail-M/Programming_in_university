#include "hashfunction.h"
#include "powerhashfunction.h"
#include "primitivehashfunction.h"

HashFunction *getHashFunction(int n) {
    if (n == 1)
    {
        HashFunction *f = new PrimitiveHashFunction;
        return f;
    }
    else
    {
        HashFunction *f = new PowerHashFunction;
        return f;
    }
}
