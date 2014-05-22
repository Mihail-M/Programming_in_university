#include <iostream>
#include <cmath>

using namespace std;

class Expression
{
public:
    Expression()
    {
        count++;
    }

    virtual ~Expression()
    {
        count--;
    }
    virtual void print() = 0;
    virtual Expression *copy() = 0;
    virtual Expression *derivative() = 0;
    virtual double evaluate(double) = 0;
    static void showCount()
    {
        cout << "count: " << count << endl;
    }
private:

    static int count;
};


class Const : public Expression
{
public:
    Const(double aa) : a(aa) {}
    ~Const() {};
    void print()
    {
        cout << a;
    }
    Expression *copy()
    {
        return new Const(a);
    }
    Expression *derivative()
    {
        return new Const(0.0);
    }
    double evaluate(double)
    {
        return a;
    }

private:
    double a;

};

class Var: public Expression
{
public:
    void print()
    {
        cout<<'x';
    }
    ~Var() {};
    Expression *copy()
    {
        return new Var;
    }
    Expression *derivative()
    {
        return new Const(1.0);
    }
    double evaluate(double x)
    {
        return x;
    }

};

class Sum :public Expression
{
public:

    Sum(Expression *aa, Expression *bb) : a(aa), b(bb) {}
    ~Sum()
    {
        delete a;
        delete b;
    }
    void print()
    {
        a->print();
        cout<<'+';
        b->print();
    }
    Expression *copy()
    {
        return new Sum(a->copy(),b->copy());
    }
    Expression *derivative()
    {
        return new Sum(a->derivative(),b->derivative());
    }
    double evaluate(double x)
    {
        return a->evaluate(x) + b->evaluate(x);
    }
protected:
    Expression *a, *b;

};

class Diff :public Expression
{
public:

    Diff(Expression *aa, Expression *bb) : a(aa), b(bb) {}
    ~Diff()
    {
        delete a;
        delete b;
    }
    void print()
    {
        a->print();
        cout<<'-';
        b->print();
    }
    Expression *copy()
    {
        return new Diff(a->copy(),b->copy());
    }
    Expression *derivative()
    {
        return new Diff(a->derivative(),b->derivative());
    }
    double evaluate(double x)
    {
        return a->evaluate(x) - b->evaluate(x);
    }
protected:
    Expression *a, *b;

};

class Mult :public Expression
{

public:

    Mult(Expression *aa, Expression *bb) : a(aa), b(bb) {}
    ~Mult()
    {
        delete a;
        delete b;
    }
    void print()
    {
        a->print();
        cout<<'*';
        b->print();
    }
    Expression *copy()
    {
        return new Mult(a->copy(),b->copy());
    }
    Expression *derivative()
    {
        return new Sum(new Mult(a->derivative(),b->copy()), new Mult(a->copy(),b->derivative()));
    }
    double evaluate(double x)
    {
        return a->evaluate(x) * b->evaluate(x);
    }
protected:
    Expression *a, *b;

};

class Div :public Expression
{
public:
    Div(Expression *aa, Expression *bb) : a(aa), b(bb) {}
    ~Div()
    {
        delete a;
        delete b;
    }
    void print()
    {
        a->print();
        cout<<'/';
        b->print();
    }
    Expression *copy()
    {
        return new Div(a->copy(),b->copy());
    }
    Expression *derivative()
    {
        return new Div(new Diff(new Mult(a->derivative(), b->copy()),new Mult(a->copy(),b->derivative())),new Mult(b->copy(),b->copy()));
    }
    double evaluate(double x)
    {
        return a->evaluate(x) / b->evaluate(x);
    }
protected:
    Expression *a, *b;

};
class Sin:public Expression
{
public:
    Sin(Expression *aa) : a(aa) {}
    ~Sin()
    {
        delete a;
    }
    void print()
    {
        cout<<"sin(";
        a->print();
        cout<<')';
    }
    Expression *copy()
    {
        return new Sin(a->copy());
    }
    Expression *derivative();
    double evaluate(double x)
    {
        return sin(a->evaluate(x));
    }
protected:
    Expression *a;

};

class Cos :public Expression
{
public:
    Cos(Expression *aa) : a(aa) {}
    ~Cos()
    {
        delete a;
    }
    void print()
    {
        cout<<"cos(";
        a->print();
        cout<<')';
    }
    Expression *copy()
    {
        return new Cos(a->copy());
    }
    Expression *derivative()
    {
        return new Mult(new Const(-1.0),new Mult(new Sin(a->copy()),a->derivative()));
    }
    double evaluate(double x)
    {
        return cos(a->evaluate(x));
    }
protected:
    Expression *a;

};

Expression *Sin::derivative()
{
    return new Mult(new Cos(a->copy()),a->derivative());
}

int Expression::count = 0;

int main()
{
    Expression::showCount();
    Expression *v = new Var;
    Expression *c = new Const(2);
    Expression *m = new Mult(c->copy(), v->copy());
    Expression *c2 = new Const(7);
    Expression *s = new Sum(v->copy(), c2->copy());
    Expression *si = new Sin(s->copy());
    Expression *co = new Cos(m->copy());
    Expression *e;

    si->print();
    cout << endl;
    cout << si-> evaluate(9);
    cout << endl;

    co->print();
    e = co->derivative();
    cout << endl;
    e->print();
    cout << endl;
    cout << e-> evaluate(2);
    cout << endl;

    Expression::showCount();

    delete co;
    delete si;
    delete v;
    delete c;
    delete m;
    delete c2;
    delete s;
    delete e;

    Expression::showCount();

}
