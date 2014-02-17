#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int find(string s, string substr) {
    for (int i = 0; i < s.size(); i++) {
        bool b = true;
        for (int j = 0; j < substr.size(); j++){
            if(s[i + j] != substr[j])
                b = false;
        }
        if (b)
            return i;
    }
    return -1;
}
void write(string s, int pos) {
    for(int i = pos; i < s.size(); i++)
        cout << s[i] <<"";
    cout << endl;
}
int openComment(string s) {
    return find(s, "/*");
}
//int f(string s) {
 //   return find(s, );
//}
int closeComment(string s) {
    return find(s, "*/");
}
int comment(string s) {
    return find(s, "//");
}

int main()
{
    ifstream in("1.txt");
    string s;
    int balance = 0;
    int balance2 = 0;

    while(getline(in, s)){
        if(comment(s) == -1 && !balance && !balance2 )
            balance += (!balance2 && openComment(s) != -1 ? 1 : 0);
        balance += (!balance2 && openComment(s) <= comment(s)  && openComment(s) != -1 ? 1 : 0);

        if (comment(s) == -1)
            balance += (closeComment(s) != -1 ? -1 : 0);

        if (find(s,  "\"") != -1 && find(s,  "\"") < comment(s)){
            balance2 = (!balance2 ? 1 : 0);
            //cout << balance2 << endl;

            for(int i = find(s, "\"") + 1; i < s.size(); i++)
                if(s[i] == '\"')
                    balance2--;
        }
        balance += (!balance2 && balance && comment(s) != -1 && closeComment(s) !=-1 ? -1 : 0);

        if((comment(s) > closeComment(s) || comment(s) < openComment(s)) && !balance && !balance2 )
            write(s, comment(s));
        /*cout << "balance: "<< balance<<endl;
        cout << "open: " << openComment(s);
        cout << "\nclose: " << closeComment(s)<<endl;
        cout << "comment: " << comment(s);*/
    }
}
