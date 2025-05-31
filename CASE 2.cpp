#include <iostream>
using namespace std;

void fillSales(float items[4][7]) {
    for (int i = 0; i < 4; i++) {
        cout << "Item " << i + 1 << " sales:\n";
        for (int d = 0; d < 7; d++) {
            cout << "  Day " << d + 1 << ": ";
            cin >> items[i][d];
        }
    }
}

void totalByItem(float items[4][7]) {
    for (int i = 0; i < 4; i++) {
        float sum = 0;
        for (int d = 0; d < 7; d++)
            sum += items[i][d];
        cout << "Total sales of Item " << i + 1 << ": " << sum << "\n";
    }
}

void totalByDay(float items[4][7]) {
    float highest = 0;
    int bestDay = 0;
    for (int d = 0; d < 7; d++) {
        float daily = 0;
        for (int i = 0; i < 4; i++)
            daily += items[i][d];
        cout << "Day " << d + 1 << ": " << daily << "\n";
        if (daily > highest) {
            highest = daily;
            bestDay = d;
        }
    }
    cout << "Highest sales on Day " << bestDay + 1 << " = " << highest << "\n";
}

void bestSellingItem(float items[4][7]) {
    float max = 0;
    int best = 0;
    for (int i = 0; i < 4; i++) {
        float sum = 0;
        for (int d = 0; d < 7; d++)
            sum += items[i][d];
        if (sum > max) {
            max = sum;
            best = i;
        }
    }
    cout << "Best-selling item: Item " << best + 1 << " with total " << max << "\n";
}

int main() {
    float sales[4][7];
    fillSales(sales);
    totalByItem(sales);
    totalByDay(sales);
    bestSellingItem(sales);
    return 0;
}
