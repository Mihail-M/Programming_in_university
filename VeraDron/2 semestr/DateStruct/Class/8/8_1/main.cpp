#include <iostream>
#include <cmath>

using namespace std;
enum Direction{
    North = 0,
    East = 1,
    South = 2,
    West = 3
};

class OfTheField{
public:
    int x,y;
    OfTheField(int _x, int _y): x(_x), y(_y){}
};

class WrongDirection {
public:
    int e;
    WrongDirection(int _e): e(_e){}

};


class Car {

public:
    Car(int mx, int my, int md):
        x(mx), y(my), direction(md){}
    Car(): x(0), y(0), direction(0)
    {}

    void reinput(int _x, int _y, int _direction) {
        if (_x > 100 || _x < -100 || y > 100 || y <-100)
            throw OfTheField(x, y);

        if (_direction < 0 || _direction > 3)
            throw WrongDirection(_direction);

        x = _x, y = _y, direction = _direction;
    }

    int move(int len) {
        int d, newX, newY;
        Direction myDirection  = static_cast<Direction>(direction);
        switch (myDirection) {
        case North:
            newY = min(100, y + len);
            d = abs(newY - y);
            y = newY;
            break;
        case South:
            newY = max(-100, y - len);
            d = abs(newY - y);
            y = newY;
            break;
        case East:
            newX = min(100, x + len);
            d = abs(newX - x);
            x = newX;
            break;
        case West:
            newX = max(-100, x - len);
            d = abs(newX - x);
            x = newX;
            break;
        }

        if (x > 100 || x < -100 || y < -100 || y > 100)
            throw OfTheField(x, y);

        return d;
    }

    void rotateLeft() {
        direction = (direction + 1) % 4;
    }

    void rotateRight() {
        direction = (direction + 3) % 4;
    }
    void print() {
        cout << x << " " << y << " " << direction << endl;

    }

private:
    int x, y;
    int direction;
};

class Bus: public Car {
public:
    Bus(int mx, int my, int md, int count, int myMoney):
        Car(mx, my, md), countP(count), money(myMoney) {}
    Bus(): Car(), countP(0), money(0)
    {}
    int move(int len){
        int d = Car::move(len);
        money += countP*d;
        return d;
    }
    void enter(int x) {
        countP += x;
    }
    void leave(int x){
        countP = max(countP - x, 0);
    }

    int getMoney() {
        return money;
    }

private:
    int countP, money;
};

int main()
{
    Bus a;
    while (true) {
        char command;
        cin >> command;

        if (command == 's') {
            int x, y, d;
            cin >> x >> y >> d;
            a = Bus(x, y, d, 0, 0);
        }
        if (command == '!') {
            int x, y, d;
            cin >> x >> y >> d;

            bool flag = true;
            while (flag)
            {
                try
                {
                    a.reinput(x, y, d);
                    flag = false;
                }
                catch (OfTheField *e)
                {
                    cout << "Our position: " << e->x << " " << e->y << endl;
                    cout << "Input position ";
                    cin >> x >> y;
                }
                catch (WrongDirection *e)
                {
                    cout << "Wrong direction" << endl;
                    cout << "Input direction ";
                    cin >> d;
                }
            }
        }

        if (command == 'f') {
            int len;
            cin >> len;
            a.move(len);
        }
        if (command == 'l'){
            a.rotateLeft();
        }
        if (command == 'r')
            a.rotateRight();
        if (command == 'e')
            break;
        if (command == 'i')
        {
            int x;
            cin >> x;
            a.enter(x);
        }
        if (command == 'o')
        {
            int x;
            cin >> x;
            a.leave(x);
        }
        if (command == 'm'){
            cout << a.getMoney() << endl;
        }
        if (command == 'w')
            a.print();

    }
    return 0;
}

