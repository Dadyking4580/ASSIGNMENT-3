#include <iostream>
using namespace std;

void getDefects(float percent[3][7]) {
    for (int s = 0; s < 3; s++) {
        cout << "Shift " << s + 1 << ":\n";
        for (int d = 0; d < 7; d++) {
            cout << "  Day " << d + 1 << ": ";
            cin >> percent[s][d];
        }
    }
}

void avgDefects(float percent[3][7]) {
    for (int s = 0; s < 3; s++) {
        float sum = 0;
        for (int d = 0; d < 7; d++)
            sum += percent[s][d];
        float avg = sum / 7;
        cout << "Shift " << s + 1 << " average defect: " << avg << "%";
        if (avg > 10) cout << " (Critical)";
        cout << "\n";
    }
}

void avgDayDefects(float percent[3][7]) {
    for (int d = 0; d < 7; d++) {
        float sum = 0;
        for (int s = 0; s < 3; s++)
            sum += percent[s][d];
        cout << "Day " << d + 1 << " average defect: " << sum / 3 << "%\n";
    }
}

int main() {
    float defects[3][7];
    getDefects(defects);
    avgDefects(defects);
    avgDayDefects(defects);
    return 0;
}
