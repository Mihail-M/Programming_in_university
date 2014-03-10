#include <iostream>

using namespace std;
class who {

public:
    who(char _ch);
    who(const who &b);

    ~who();
    who &operator = (who const &b);
    char getCh() const;

private:
    char ch;
};

who::who(char _ch): ch(_ch)
{
    cout <<"Creating object who <" << ch <<" >" << endl;
}

who::who(const who &b): ch(b.ch)
{
     cout << "___Copying object who <" << b.ch <<">" << endl;
}

who::~who()
{
    cout <<"Deleting object who <" << ch <<" >" << endl;
}

who &who::operator =(const who &b)
{
    cout << "Assignment of object who <" << b.ch << ">" << endl;
    ch = b.ch;
    return (*this);
}

char who::getCh() const
{
    return ch;
}

who make_who(char c){
    who a(c);
    return a;
}
void f_value(who a){}
void f_address(who &a){}
void f_pointer(who *a){}

int main()
{
    who a('1');
    who b('2');
    who c('3');
    who n('1');
    n = c;
    who q(c);
    who d = make_who('4');

    f_value(a);
    f_address(b);
    f_pointer(&c);
  //  who h[] = {'a', 'b', 'c', 'd', 'e'};
    //for(int i =0; i < 5;i ++)
      //  cout <<h[i].getCh() << " ";

    return 0;
}

