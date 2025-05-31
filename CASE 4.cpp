#include <iostream>
using namespace std;

void inputTemps(float grid[5][5]) {
    for (int r = 0; r < 5; r++) {
        cout << "Zone " << r + 1 << ":\n";
        for (int c = 0; c < 5; c++) {
            cout << "  Location " << c + 1 << ": ";
            cin >> grid[r][c];
        }
    }
}

void averagePerZone(float grid[5][5]) {
    for (int r = 0; r < 5; r++) {
        float sum = 0;
        for (int c = 0; c < 5; c++)
            sum += grid[r][c];
        cout << "Zone " << r + 1 << " average temperature: " << sum / 5 << "\n";
    }
}

void detectExtremes(float grid[5][5]) {
    float maxT = grid[0][0], minT = grid[0][0];
    int hotR = 0, hotC = 0, coldR = 0, coldC = 0;

    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++) {
            if (grid[r][c] > maxT) {
                maxT = grid[r][c];
                hotR = r; hotC = c;
            }
            if (grid[r][c] < minT) {
                minT = grid[r][c];
                coldR = r; coldC = c;
            }
        }

    cout << "Extreme hot spot: " << maxT << " at (" << hotR + 1 << ", " << hotC + 1 << ")\n";
    cout << "Extreme cold spot: " << minT << " at (" << coldR + 1 << ", " << coldC + 1 << ")\n";
}

int main() {
    float temps[5][5];
    inputTemps(temps);
    averagePerZone(temps);
    detectExtremes(temps);
    return 0;
}
