#include "ConsoleWriter.h"
#include <iostream>


ConsoleWriter::ConsoleWriter()
{

}

ConsoleWriter::~ConsoleWriter()
{

}

void ConsoleWriter::print(int n, int **array){

    int *ans = getAns(n, array);
    for(int i = 0; i < n * n - 1; i++)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
    delete[] ans;
}
