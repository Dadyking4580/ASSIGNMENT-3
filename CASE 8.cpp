#include <iostream>
using namespace std;

void showBooks(char books[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < 5; j++)
            cout << books[i][j] << " ";
        cout << "\n";
    }
}

void countStatus(char books[5][5]) {
    int a = 0, i = 0, m = 0;
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++) {
            if (books[r][c] == 'A') a++;
            else if (books[r][c] == 'I') i++;
            else if (books[r][c] == 'M') m++;
        }
    cout << "Available: " << a << ", Issued: " << i << ", Missing: " << m << "\n";
}

void mostMissingShelf(char books[5][5]) {
    int maxMissing = 0, shelf = 0;
    for (int r = 0; r < 5; r++) {
        int count = 0;
        for (int c = 0; c < 5; c++)
            if (books[r][c] == 'M') count++;
        if (count > maxMissing) {
            maxMissing = count;
            shelf = r;
        }
    }
    cout << "Shelf with most missing books: " << shelf + 1 << "\n";
}

int main() {
    char status[5][5] = {
        {'A','I','M','A','I'},
        {'A','A','M','M','I'},
        {'I','A','A','A','I'},
        {'M','M','M','A','I'},
        {'A','I','A','M','M'}
    };
    showBooks(status);
    countStatus(status);
    mostMissingShelf(status);
    return 0;
}
