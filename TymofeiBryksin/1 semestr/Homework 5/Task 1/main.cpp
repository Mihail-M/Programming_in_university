#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
const countAlpha = 26;
void nextWord(int &pos, char *text){
    int alpha[countAlpha];
    int i = 0;
    for (int i = 0; i < countAlpha; i++)
        alpha[i] = 0;
    for(i = pos; i < strlen(text) && text[i] != ' '; i++)
        if(!alpha[tolower(text[i]) - 'a']++)
            cout << text[i];
    cout << " ";

    pos = i;
}

int main()
{
    int n = 0;
    ifstream input("input.txt");
    cout << "First string in your file should consist of one number (size of any next string, cstring :( :/ )))\n\n";
    cout << "If file with your text is exist, you should see text!\n\n";
    input >> n;
    char *text = new char[n];
    while(input.getline(text, n))
    {
        for(int pos = 0; pos < n; pos++)
            if(isalpha(text[pos]))
                nextWord(pos, text);

        cout << endl;

    }
    delete[] text;

    return 0;
}

