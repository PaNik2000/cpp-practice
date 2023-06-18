#include <iostream>
#include <cmath>
#include "eq2.h"

using namespace std;

int main()
{
    eq2 e(1,-5,4);
    cout << e.find_X() << "\n";
    cout << e.find_Y(1) << " " << e.find_Y(4) << "\n";
    eq2 e2(1,-5,4);
    e2.set(1,-3,2);
    cout << e2.find_X() << "\n";
    cout << e2.find_Y(1) << " " << e2.find_Y(2) << "\n";
    eq2 e3 = e + e2;
    e.show();
    e2.show();
    e3.show();

    eq2 e4(2,1,2);
    cout << e4.find_X() << "\n";
    
    if (isnan(e4.find_X()))
    {
        cout << "корней нет" << "\n";
    }
}