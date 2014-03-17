#include "hashfunction.h"
#include "powerhashfunction.h"
#include "primitivehashfunction.h"

HashFunction *getHashFunction(int n) {
    if (n == 1)
    {
        return new PrimitiveHashFunction;
    }
    else
    {
        return new PowerHashFunction;

    }
}
