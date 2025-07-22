#include <iostream>
#include <cassert>

using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    if(temperature < 0 || temperature > 45) {
        cout << "Temperature out of range!\n";
        return false;
    } else if(soc < 20 || soc > 80) {
        cout << "State of Charge out of range!\n";
        return false;
    } else if(chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        return false;
    }
    return true;
}

int main() {
    // Test cases with assertions
    bool result1 = batteryIsOk(25, 70, 0.7);
    assert(result1 == true); // Expected: true

    bool result2 = batteryIsOk(50, 85, 0);
    assert(result2 == false); // Expected: false (due to temperature and SOC out of range)

    return 0;
}
