#include iostream

using namespace std;
typedef int ar;
int b[1000];
int main()
{

    int n = 0;
    cin  n;
    int a[n];
    int minS = 0;
    int sumSegment = 0;


    int result = 0;
    for (int i = 0;i  n; i++)
        cin  a[i];
     int answer = a[0];
    for (int r = 0; r  n; r++){
        sumSegment += a[r];
        answer = max(answer, sumSegment - minS);
        minS = min(minS, sumSegment);
        cout  sumSegment   msum  minS   ans   answer endl;

    }
    cout  answer;


    return 0;
}
