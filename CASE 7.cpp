#include <iostream>
using namespace std;

void enterRatings(int rate[5][10]) {
    for (int p = 0; p < 5; p++) {
        cout << "Product " << p + 1 << " ratings:\n";
        for (int u = 0; u < 10; u++) {
            cout << "  User " << u + 1 << ": ";
            cin >> rate[p][u];
        }
    }
}

void avgRatings(int rate[5][10]) {
    float minAvg = 6;
    int worst = 0;
    for (int p = 0; p < 5; p++) {
        float sum = 0;
        int perfect = 0;
        for (int u = 0; u < 10; u++) {
            sum += rate[p][u];
            if (rate[p][u] == 5) perfect++;
        }
        float avg = sum / 10;
        cout << "Product " << p + 1 << " average: " << avg << ", Perfect ratings: " << perfect << "\n";
        if (avg < minAvg) {
            minAvg = avg;
            worst = p;
        }
    }
    cout << "Worst rated product: Product " << worst + 1 << " with average " << minAvg << "\n";
}

int main() {
    int ratings[5][10];
    enterRatings(ratings);
    avgRatings(ratings);
    return 0;
}
