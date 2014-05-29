#include <iostream>

using namespace std;


class WrongValueException
{
public:
    WrongValueException(int i): ind(i){}
    int getInd() {
        return ind;
    }
private:
    int ind;
};

class NegativeValueException
{};

double g(int n, double *A) {

    double ans = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] < 0)
            throw NegativeValueException();
        if(A[i] < 10 || A[i] > 100)
            throw WrongValueException(i);
        ans+=A[i];
    }
    return ans/n;
}

double f() {
    int n;
    cin >> n;
    double *arr = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double ans = 0;
    bool DO = true;

    while(DO) {
        try {
            ans = g(n , arr);
            DO = false;
        }
        catch(NegativeValueException) {
            delete[] arr;
            throw NegativeValueException();
        }

        catch(WrongValueException e) {
            cout << "Errow! Please input element with index " << e.getInd() + 1 << " again" << endl;
            cin >> arr[e.getInd()];
        }
    }
    delete[] arr;
    return ans;
}

int main()
{

    try{
        cout << f();
    }
    catch(NegativeValueException) {
        cout << "Wrong!";
    }

    return 0;
}

