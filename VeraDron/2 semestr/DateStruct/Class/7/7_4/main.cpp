#include <iostream>

using namespace std;

class Vehicle
{
private:
	int motor_id;
public:
	Vehicle( int mymotor_id ): motor_id(mymotor_id)
	{
	}
	void print_motor()
	{
		cout << "Motor id = " << motor_id << endl;
	}
};

class GroundVehicle: virtual public Vehicle
{
private:
	double wheel_diam;
public:
	GroundVehicle( int mymotor_id, double mywheel_diam ) :
		Vehicle(mymotor_id), wheel_diam(mywheel_diam)
	{
	}
protected:
	void print_full()
	{
		print_motor();
		cout << "Wheel diam = " << wheel_diam << endl;
	}
};

class FlyingVehicle: virtual public Vehicle
{
private:
	int turbine_num;
public:
	FlyingVehicle( int mymotor_id, int myturbine_num ) :
		Vehicle(mymotor_id), turbine_num(myturbine_num)
	{
	}
protected:
    void print_turbine() {
        cout << "Turbine num = " << turbine_num << endl;
    }

	void print_full()
	{
		print_motor();
		cout << "Turbine num = " << turbine_num << endl;
	}
};

class Aircraft: public GroundVehicle, public FlyingVehicle
{
public:
	Aircraft( int mymotor_id, double mywheel_diam, int myturbine_num ):
        GroundVehicle(mymotor_id, mywheel_diam), FlyingVehicle(mymotor_id, myturbine_num), Vehicle(mymotor_id)
	{
	}
void print_full()
	{
		GroundVehicle::print_full();
        FlyingVehicle::print_turbine();

	}
};

int main()
{
	Aircraft B707(1234, 12.3, 10);
	B707.print_full();
    B707.print_motor();

	return 0;
}

