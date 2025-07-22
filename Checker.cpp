#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    // Check and print the condition message directly
    if (temperature < 0 || temperature > 45) {
        cout << "Temperature out of range!\n";
        return false;
    }

    if (soc < 20 || soc > 80) {
        cout << "State of Charge out of range!\n";
        return false;
    }

    if (chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        return false;
    }

    // If all conditions pass, return true
    return true;
}

int main() {
    // Test cases
    assert(batteryIsOk(25, 70, 0.7) == true);  // Expected: true (within range)
    assert(batteryIsOk(50, 85, 0) == false);   // Expected: false (Temperature and SOC out of range)
    assert(batteryIsOk(25, 70, 0.9) == false); // Expected: false (Charge Rate out of range)

    return 0;
}
