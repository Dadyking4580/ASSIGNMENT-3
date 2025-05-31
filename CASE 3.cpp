#include <iostream>
using namespace std;

void inputStatus(char state[5][7]) {
    for (int p = 0; p < 5; p++) {
        cout << "Patient " << p + 1 << ":\n";
        for (int d = 0; d < 7; d++) {
            cout << "  Day " << d + 1 << ": ";
            cin >> state[p][d];
        }
    }
}

void statusCount(char state[5][7]) {
    int stable = 0, critical = 0, recovered = 0;
    for (int p = 0; p < 5; p++)
        for (int d = 0; d < 7; d++) {
            if (state[p][d] == 'S') stable++;
            else if (state[p][d] == 'C') critical++;
            else if (state[p][d] == 'R') recovered++;
        }
    cout << "Stable: " << stable << ", Critical: " << critical << ", Recovered: " << recovered << "\n";
}

void criticalDaysPerPatient(char state[5][7]) {
    for (int p = 0; p < 5; p++) {
        int count = 0;
        for (int d = 0; d < 7; d++)
            if (state[p][d] == 'C') count++;
        cout << "Patient " << p + 1 << ": " << count << " critical days\n";
    }
}

int main() {
    char status[5][7];
    inputStatus(status);
    statusCount(status);
    criticalDaysPerPatient(status);
    return 0;
}
