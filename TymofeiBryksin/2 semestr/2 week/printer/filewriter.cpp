#include "filewriter.h"
#include "fstream"


FileWriter::~FileWriter()
{

}

void FileWriter::print(int n, int **array)
{
    std::ofstream out("output.txt");
    int *ans = getAns(n, array);

    for(int i = 0; i < n * n - 1; i++)
        out << ans[i] << " ";
    out << std::endl;
    delete[] ans;
}
