#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
bool count[26];

int getline(char *s, int lim)
{
    int k = 0;
    while((*s++ = getchar())!='\n' && (++k)<lim);
    *s-- = '\0';
    if(k < lim) return k;
    while (getchar()!='\n');
    return k;
}

int main()
{
    char str[1000];
    cin >> str;
    cout << str << " ";
    for(int i = 0; i < strlen(str); i++)
        count[str[i]-'a']++;
    getline(str, 1000);
    str[strlen(str)-1] = ' ';
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
        {
            bool f = 0;
            for(int j = i+1; str[j] != ' ';  j++){
                if(!count[str[j]-'a']){
                    f = 1;}
                    }

            if(!f)
            {
                for(int j = i+1; str[j] != ' ';  j++) cout << str[j];
                cout << " ";
            }
        }
    }
    return 0;
}
