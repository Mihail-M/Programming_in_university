//n+m
#include <iostream>
#include "List.h"

using namespace std;
using namespace Lists;

void read(List *list, int n) {
    for(int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;
        sortAdd(list, k);
    }
}

int main()
{
    List *pileFirst = create();
    List *pileSecond = create();
    List *pileThird = create();

    int countFirst = 0;
    int countSecond = 0;

    cout << "Input length first pile: ";
    cin >> countFirst;

    cout << ":Please, input length second pile: ";
    cin >> countSecond;

    cout << "Input  first pile: ";
    read(pileFirst, countFirst);

    cout << "Input  second pile: ";
    read(pileSecond, countSecond);
    cout << "Fist pile is: ";
    printList(pileFirst);
    cout << "\nSecond pile is: ";
    printList(pileSecond);


    ListElement  *elemPile1 = getElement(1, pileFirst);
    ListElement  *elemPile2 = getElement(1, pileSecond);
    ListElement  *elemPile3 = getElement(0, pileThird);
    int count1 = 0;
    int count2 = 0;

    while (pileThird->size != (countSecond + countFirst)) {

        while (count1<countFirst) {
            if (elemPile1->value >= elemPile2->value || count2 == countSecond) {
                add(pileThird, elemPile3, elemPile1->value);
                count1++;
            }
            else break;

            if(count1!=countFirst)
                elemPile1 = elemPile1->next;

            elemPile3 = elemPile3->next;
        }
        while (count2 < countSecond) {
            if (elemPile2->value >= elemPile1->value || count1 == countFirst)
            {
                add(pileThird, elemPile3, elemPile2->value);
                count2++;
            }
            else break;

            if(count2!=countSecond)
                elemPile2 = elemPile2->next;

            elemPile3 = elemPile3->next;
        }
    }

    cout << "\n Сonsequently, third pile is: ";
    printList(pileThird);
    deleteList(pileFirst);
    deleteList(pileSecond);
    deleteList(pileThird);
    return 0;
}

