#include <iostream>
#include <cstdio>

using namespace std;
int getline(char *s, int lim) {
    int k = 0;
    while((*s++ = getchar())!='\n' && (++k)<lim);
    *s-- = '\0';
    if(k < lim) return k;
    while (getchar()!='\n');
    return k;
}
void toUPPER(char *s, int n){
for(int i = 0; i < n; i++)
        *s++ = toupper(*s);
}

char* copy(char *s, int b, int n){
    char *subset = new char[n+1];
    s = s + b;
    int i;
    for(i = 0;i <n ;i++)
        subset[i] = *(s++);
    subset[i++] = '\0';
    return subset;

}

int main()
{
    char s[1000];
    int n = getline(s, 1000);
    cout << copy(s, 1 , 3);
}
    /*int word = 0;

    for(int i = 0; i < n; i++)
        if((isalpha(s[i]) || isdigit(s[i])) && !(isalpha(s[i+1]) || isdigit(s[i+1]))){
            word++;
            s[i+1] = '\0';
            }
    char *p[word];
    int t = 0;
    if(isalpha(s[0]) || isdigit(s[0]))
        p[t++]=&s[0];

    for(int i = 1; i < n; i++)
        if((isalpha(s[i]) || isdigit(s[i])) && !(isalpha(s[i-1]) || isdigit(s[i-1])))
           p[t++] = &(s[i]);

    for(int i = word - 1; i >= 0; i--){
            cout << endl;

           cout << p[i];
            }*/



