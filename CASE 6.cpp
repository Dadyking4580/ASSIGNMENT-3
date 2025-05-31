#include <iostream>
using namespace std;

void displaySeats(char layout[6][4]) {
    cout << "Seating Chart (E=Empty, B=Booked):\n";
    for (int r = 0; r < 6; r++) {
        for (int s = 0; s < 4; s++) {
            cout << layout[r][s] << " ";
        }
        cout << "\n";
    }
}

void reserveSeat(char layout[6][4]) {
    int row, seat;
    cout << "Enter row (1-6) and seat (1-4) to book: ";
    cin >> row >> seat;
    if (layout[row - 1][seat - 1] == 'E') {
        layout[row - 1][seat - 1] = 'B';
        cout << "Seat booked.\n";
    }
    else {
        cout << "Seat already booked.\n";
    }
}

void countEmptySeats(char layout[6][4]) {
    int count = 0;
    for (int r = 0; r < 6; r++)
        for (int s = 0; s < 4; s++)
            if (layout[r][s] == 'E') count++;
    cout << "Available seats: " << count << "\n";
}

void rowWithMostEmpty(char layout[6][4]) {
    int maxEmpty = 0, bestRow = 0;
    for (int r = 0; r < 6; r++) {
        int empty = 0;
        for (int s = 0; s < 4; s++)
            if (layout[r][s] == 'E') empty++;
        if (empty > maxEmpty) {
            maxEmpty = empty;
            bestRow = r;
        }
    }
    cout << "Row with most empty seats: " << bestRow + 1 << "\n";
}

int main() {
    char seats[6][4] = {
        {'E','E','E','E'},
        {'E','E','E','E'},
        {'E','E','E','E'},
        {'E','E','E','E'},
        {'E','E','E','E'},
        {'E','E','E','E'}
    };
    displaySeats(seats);
    reserveSeat(seats);
    displaySeats(seats);
    countEmptySeats(seats);
    rowWithMostEmpty(seats);
    return 0;
}
