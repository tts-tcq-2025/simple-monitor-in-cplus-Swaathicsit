#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    // Simplified checks using an array of conditions to reduce complexity
    struct Condition {
        bool (*check)(float);
        const char* message;
    };

    // Define checks and corresponding messages
    Condition checks[] = {
        { [](float value) { return value < 0 || value > 45; }, "Temperature out of range!" },
        { [](float value) { return value < 20 || value > 80; }, "State of Charge out of range!" },
        { [](float value) { return value > 0.8; }, "Charge Rate out of range!" }
    };

    // Check all conditions
    for (auto& condition : checks) {
        if (condition.check(temperature) || condition.check(soc) || condition.check(chargeRate)) {
            cout << condition.message << endl;
            return false;
        }
    }

    return true;
}

int main() {
    // Test cases
    assert(batteryIsOk(25, 70, 0.7) == true);  // Expected: true (within range)
    assert(batteryIsOk(50, 85, 0) == false);   // Expected: false (Temperature and SOC out of range)
    assert(batteryIsOk(25, 70, 0.9) == false); // Expected: false (Charge Rate out of range)

    return 0;
}
