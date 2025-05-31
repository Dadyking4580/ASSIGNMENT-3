#include <iostream>
using namespace std;

void getMarks(int scores[10][5]) {
    for (int s = 0; s < 10; s++) {
        cout << "Student " << s + 1 << " Marks:\n";
        for (int sub = 0; sub < 5; sub++) {
            cout << "  Subject " << sub + 1 << ": ";
            cin >> scores[s][sub];
        }
    }
}

void computeTotalAverage(int scores[10][5], int totals[10], float avgs[10]) {
    for (int s = 0; s < 10; s++) {
        totals[s] = 0;
        for (int sub = 0; sub < 5; sub++)
            totals[s] += scores[s][sub];
        avgs[s] = totals[s] / 5.0;
    }
}

void findTopper(float avgs[10]) {
    int top = 0;
    for (int s = 1; s < 10; s++)
        if (avgs[s] > avgs[top]) top = s;
    cout << "Topper is Student " << top + 1 << " with average: " << avgs[top] << "\n";
}

void displayGrades(float avgs[10]) {
    for (int s = 0; s < 10; s++) {
        char grade;
        if (avgs[s] >= 80) grade = 'A';
        else if (avgs[s] >= 60) grade = 'B';
        else if (avgs[s] >= 40) grade = 'C';
        else grade = 'F';
        cout << "Student " << s + 1 << ": Grade " << grade << "\n";
    }
}

int main() {
    int marks[10][5], total[10];
    float average[10];
    getMarks(marks);
    computeTotalAverage(marks, total, average);
    findTopper(average);
    displayGrades(average);
    return 0;
}
