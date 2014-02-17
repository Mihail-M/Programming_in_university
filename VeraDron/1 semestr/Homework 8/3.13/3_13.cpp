#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int getline(char *s, int lim) {
    int k = 0;
    while((*s++ = getchar()) != '\n' && (++k)<lim);
    *--s = '\0';
    if(k < lim) return k;
    while (getchar() != '\n');
    return k;
}


char* trans(char *s, char *in, char *to){
    for(int i = 0; i < strlen(in); i++)
        for(int j = 0; j < strlen(s); j++)
            if(s[j] == in[i])
                s[j] = to[i];
    return s;
}
int main()
{
    char s[1000];
    char in[100];
    char to[100];
    getline(s, 1000);
    getline(in, 100);
    getline(to, 100);
    cout << trans(s,in,to);
}

