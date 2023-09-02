
#include "TryOOP.hpp"

using namespace TryCPPLangg;



void TryOOP::TestForClassVehicle(){
    Vehicle myCar{"myCar", 4};
    Vehicle mybike{"myBike", 2};
    Vehicle noWheels;

    cout << "myCar has wheels: " << myCar.GetNumberOfWheels() << endl;
    cout << "myBike has wheels: " << mybike.GetNumberOfWheels() << endl;
    cout << "noWheels has wheels: " << noWheels.GetNumberOfWheels() << endl;

}

namespace{
    //just some variables accessible from this file

    int var1 {10};

    void FuncInUnNamedNamespace(){
        cout << "Inside fn " << __FUNCTION__ << " line: " << __LINE__ ;
        cout << " FileName: " << __FILE__ << endl;
    }
}

void TryOOP::TestForUnnamedNamespace(){
    cout << "var1 is " << var1 << endl;
    cout << " calling FuncInUnNamedNamespace\n" ;
    FuncInUnNamedNamespace();
}

void TryOOP::TestForInheritance(){
    TryOOP::Car MyCar;
    Motorcycle Motorcycle1;

    cout << "Mycar has wheels: " << MyCar.GetNumberOfWheels() << endl;
    cout << "Motorcycle1 has wheels: " << Motorcycle1.GetNumberOfWheels() << endl;

}





void TryOOP::MainForOOP(){
    TryOOP::TestForClassVehicle();
    // TryOOP::TestForInheritance();
    // TryOOP::TestForUnnamedNamespace();
}


