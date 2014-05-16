#include <iostream>
#include  <cstdio>

#include  "hashtable.h"

using namespace std;

int main()
{
	HashTable b;
    freopen("tale.in", "rt", stdin);

    string word = "";
    char alpha;
    bool flag = true;

    while (flag) {
        alpha = getchar();
        if(alpha == EOF)
        {
            flag = false;
            break;
        }
        else
            if (alpha == '.' || alpha == ' ' || alpha == ',' || alpha == '\n')
            {
                if(word != "")
                b.add(word);
                word = "";
            }
            else
            {
                word += alpha;
            }
    }

    b.show();
    return 0;
}

