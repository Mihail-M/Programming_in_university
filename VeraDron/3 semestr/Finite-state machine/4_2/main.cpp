#include <iostream>
#include <vector>

using namespace std;
vector <string> code;


bool is_separatedElement(char c) {
    if (c == ' ' || c == ';' || c == '<' || c == '=' || c =='\n')
        return 1;
    return 0;
}

int finite_state_machine_for_if(int position, int &index) {

    string s = code[index];
    if (s[position] == 'i')
    {
        if (s[position+1] =='1f'){
            return position + 2 ;
        }
        else return -1;
    }
    else return -1;
}

int finite_state_machine_for_onecomment(int position, int index) {
    string s = code[index];
    if (s[position] == '/')
    {
        if (s[position + 1] != '/' && s[position+1] != '*'){
            cout << "Comment Error line--  " << index;
            return -2;
        }
        else if (s[position+1] == '*')
            return -1;
        else return s.size();
    }
    else return -1;
}

int finite_state_machine_for_multiplycomment(int position, int &index) {
    string s = code[index];
    int state = 0;
    if (s[position] == '/')
    {
        if (s[position + 1] == '*'){
            state = 1;
        }
        else {
            cout << "Comment Error" << endl;
            return -2;
        }
        for (int i = position + 2; i < s.size() - 1; i++)
            if (s[i] == '*' && s[i+1] == '/')
            {
                return i+1;
            }
        for (int i = index+1; i < code.size(); i++){

            s = code[i];
            for (int j = 0; j < s.size() - 1; j++)
                if (s[j] == '*' && s[j + 1] == '/')
                {
                    index = i;
                    return j + 2;
                }
        }

        cout << "Comment Error Line ---" << index << endl;
        return -2;
    }
    else return -1;
}


int finite_state_machine_for_separator(int position, int index) {
    int state = 0;
    string s = code[index];
    if (s[position] == ';')
        return position + 1;
    else return -1;
}

int finite_state_machine_for_type(int position, int index) {
    int state = 0;
    string s = code[index];

    for (int i = position; i < s.size(); i++) {

        if (state == 0) {
            if (s[i] == 'f' && (i - 1 <= 0 || s[i-1] == ' ' || s[i-1] == ';'))
                state = 1;
            continue;
        }
        else
            if (state == 1) {
                if (s[i] == 'l')
                    state = 2;
                continue;
            }
            else
                if (state == 2) {
                    if (s[i] == 'o')
                        state = 3;
                    continue;
                }
                else
                    if (state == 3) {
                        if (s[i] == 'a')
                            state = 4;
                        continue;
                    }
                    else
                        if (state == 4) {
                            if (s[i] == 't')
                                state = 5;
                            continue;
                        }
                        else
                            if (state == 5) {
                                if (s[i] == ';' || s[i] == ' ' || i == s.size())
                                    return i;
                                continue;
                            }
    }
    return -1;
}

int finite_state_machine_for_num(int position, int index, string &object) {
    int state = 0;
    string s = code[index];

    for (int i = position; i < s.size(); i++) {
        if (state == 0) {
            if (isdigit(s[i]) ){
                if (i - 1 >= 0){
                    if (!isalpha(s[i-1]) && s[i-1] != '-'){
                        state = 1;
                        object += s[i];}
                    else if (s[i-1] == '-'){
                        cout << "Minus Error Line--- " << index << endl;
                        return -2;}
                }
                else {state = 1;
                    object += s[i];}}
            else return -1;
            continue;
        }
        else if(state == 1) {
            if (isdigit(s[i]))
            {
                object += s[i];
            }
            else
                if(s[i] == '.') {
                    object += s[i];
                    state = 2;
                }
                else
                    if (!is_separatedElement(s[i]) && s[i] != '/'){
                        cout << "Wrong Number Line--- " << index << endl;
                        return -2;
                    }
                    else
                        return i;
            continue;

        }
        else if (state == 2) {
            if (isdigit(s[i]) ) {
                state = 3;
                object+=s[i];
            }
            else
            {
                cout << "Wrong Number Line--- " << index << endl;
                return -2;
            }
            continue;
        }
        else if (state == 3) {
            if (isdigit(s[i])) {
                object += s[i];
            }
            else
                if (!is_separatedElement(s[i]) && s[i] != '/'){

                    cout << "Wrong Number Line--- " << index << endl;
                    return -2;
                }
                else
                    return i;
        }
    }

    return -1;
}

int finite_state_machine_for_id(int position, int index, string &object) {
    int state = 0;
    string s = code[index];

    for (int i = position; i < s.size(); i++) {
        if (state == 0) {
            if (isalpha(s[i])) {
                if (i - 1>= 0){
                    if (!isdigit(s[i-1]))
                    {
                        state = 1;
                        object += s[i];}
                    else {
                        cout << "wrong prefix Line--- " << index << endl;
                        return -2;}
                }
                else {
                    state = 1;
                    object += s[i];
                }
            }
            else return -1;
            continue;
        }
        else if(state == 1) {
            if (isalpha(s[i]))
            {
                object += s[i];
            }
            else
                if(isdigit(s[i])) {
                    object += s[i];
                    state = 2;
                }
                else
                    if (!is_separatedElement(s[i]) && s[i] != '/'){
                        cout << "Wrong ID Line--- " << index << endl;
                        return -2;
                    }
                    else{
                        if(object != "float" && object != "if")
                            return i;
                        else return -1;
                    }
            continue;

        }
        else if (state == 2) {
            if (isdigit(s[i]) ) {
                object+=s[i];
            }
            else
                if (isalpha(s[i]))
                {
                    object+=s[i];
                }
                else if(!is_separatedElement(s[i]))
                {
                    cout << "Wrong ID Line--- " << index << endl;
                    return -2;
                }
                else return i;
            continue;
        }
    }

    return -1;
}
int finite_state_machine_for_relation(int position, int index, string &object) {
    int state = 0;
    string s = code[index];

    if (state == 0) {
        if (s[position] == '<') {
            state = 1;
            object += s[position];
        }
    }
    if (state == 1) {
        if (s[position+1] == '=') {
            object += s[position+1];
            return position+2;
        }
        return position+1;

    }

    return -1;
}

int finite_state_machine_for_assignment(int position, int index) {

    if (code[index][position] == '=')
            return position+1;
    return -1;
}

int finite_state_machine_for_space(int position, int index) {
    if (code[index][position] == ' ')
        return position + 1;
    else return -1;
}

//нужен для проверки принадлежит ли символ алфавиту
int finite_state_machine_for_rabish(int position, int index) {
    if ((is_separatedElement( code[index][position])
         || isalpha(code[index][position])
         || isdigit(code[index][position])
         || code[index][position] == '.') || (int)code[index][position] == 0)
    {
        return position;}
    else {

        cout << "Error: unexpected symbol - " << code[index][position]  << " Line ---" << index;
        return -2;}
}

int main()
{
    string t;
    vector <pair<string,string> > tokens;
    while(getline(cin, t)) {
        code.push_back(t);
    }
    //cout << code[1] << endl;
    for (int i = 0; i < code.size(); i++) {
        int start = 0;
        while (start < code[i].size() )
        {

            int valOneComment = finite_state_machine_for_onecomment(start, i);
            if( valOneComment == -2 ) {
                return 0;
            }
            else
                if (valOneComment != -1) {
                    start = valOneComment;

                }

            int valMultiplyComment = finite_state_machine_for_multiplycomment(start, i);
            if( valMultiplyComment == -2 ) {
                return 0;
            }
            else
                if (valMultiplyComment != -1) {
                    start = valMultiplyComment;
                }

            int valRabish = finite_state_machine_for_rabish(start, i);
            if( valRabish == -2 ) {
                return 0;
            }
            else
                if (valRabish != -1) {
                    start = valRabish;
                }

            int valID = finite_state_machine_for_id(start, i, t);
            if( valID == -2 ) {
                return 0;
            }
            else
                if (valID != -1) {
                    start = valID;
                    tokens.push_back(make_pair(t, "ID"));
                }
            t ="";


            int valNum = finite_state_machine_for_num(start, i, t);
            if( valNum == -2 ) {
                return 0;
            }
            else
                if (valNum != -1) {
                    start = valNum;
                    tokens.push_back(make_pair(t, "num"));
                }
            t ="";


            int valIf = finite_state_machine_for_if(start, i);
            if( valIf == -2 ) {
                return 0;
            }
            else
                if (valIf != -1) {
                    start = valIf;
                    tokens.push_back(make_pair("if", "if"));
                }


            int valSeparator = finite_state_machine_for_separator(start, i);
            if( valSeparator == -2 ) {
                return 0;
            }
            else
                if (valSeparator != -1) {
                    start = valSeparator;
                    tokens.push_back(make_pair(";", "separator"));

                }


            int valType = finite_state_machine_for_type(start, i);
            if( valType == -2 ) {
                return 0;
            }
            else
                if (valType != -1) {
                    start = valType;
                    tokens.push_back(make_pair("float", "type"));

                }



            int valRelation = finite_state_machine_for_relation(start, i,t);
            if( valRelation == -2 ) {
                return 0;
            }
            else
                if (valRelation != -1) {
                    start = valRelation;
                    tokens.push_back(make_pair(t, "Relation"));

                }
            t ="";


            int valAssignment = finite_state_machine_for_assignment(start, i);
            if( valAssignment == -2 ) {
                return 0;
            }
            else
                if (valAssignment != -1) {
                    start = valAssignment;
                    tokens.push_back(make_pair("=", "Assignment"));

                }


            int valSpace = finite_state_machine_for_space(start, i);
            if (valSpace != -1)
                start = valSpace;
        }
    }



    for (int i = 0; i < tokens.size(); i++)
        cout << tokens[i].first << " " << tokens[i].second << endl;

    return 0;
}

