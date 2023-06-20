
#ifndef TRY_OOP_H
#define TRY_OOP_H

#include <cinttypes>
#include <iostream>

using namespace std;

namespace TryCPPLangg{
    namespace TryOOP{
        class Vehicle
        {
        private:
            uint32_t m_NumberOfWheels;
            string m_Name;

        public:
            Vehicle(string name, uint32_t numberOfWheels) 
            : m_Name{name} , m_NumberOfWheels { numberOfWheels} 
            {

            }

            Vehicle() = default;
            uint32_t GetNumberOfWheels() 
            {
                return m_NumberOfWheels;
            }

            // ~Vehicle()
            // {
            //     cout << m_Name << "is getting destroyed" << endl;
            // }

            ~Vehicle() = default;
        };

        class VehicleForInherit {
            private:
                uint32_t m_NumberOfWheels{};
            public:
                // VehicleForInherit() = default;
                VehicleForInherit(uint32_t numberOfWheels): 
                    m_NumberOfWheels {numberOfWheels} {

                    }

                uint32_t GetNumberOfWheels() const
                {
                    return m_NumberOfWheels;
                }

        };
        class Car: public VehicleForInherit {
            public:
            Car(): VehicleForInherit(4) {}

        };

        class Motorcycle : public VehicleForInherit{
            public :
                Motorcycle() : VehicleForInherit(2){}
        };

        void TestForClassVehicle();
        void TestForInheritance();

        void TestForUnnamedNamespace();
        void MainForOOP();

    }
    


   

}



#endif