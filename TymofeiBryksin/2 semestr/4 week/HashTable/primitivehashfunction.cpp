#include "primitivehashfunction.h"

int PrimitiveHashFunction::calculateHashFunction(std::string s, int size)
{
    return (s.size() % size);
}
