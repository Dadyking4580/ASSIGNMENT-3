#include <iostream>
using namespace std;

void enterScores(int board[6][4]) {
    for (int t = 0; t < 6; t++) {
        cout << "Team " << t + 1 << " scores:\n";
        for (int r = 0; r < 4; r++) {
            cout << "  Round " << r + 1 << ": ";
            cin >> board[t][r];
        }
    }
}

void computeTotals(int board[6][4], int sum[6]) {
    for (int t = 0; t < 6; t++) {
        sum[t] = 0;
        for (int r = 0; r < 4; r++)
            sum[t] += board[t][r];
    }
}

void findWinners(int sum[6]) {
    int win = 0, run = 0;
    for (int t = 1; t < 6; t++) {
        if (sum[t] > sum[win]) {
            run = win;
            win = t;
        }
        else if (sum[t] > sum[run] && t != win) {
            run = t;
        }
    }
    cout << "Winner: Team " << win + 1 << ", Runner-up: Team " << run + 1 << "\n";
}

void lowScoringRounds(int board[6][4]) {
    for (int t = 0; t < 6; t++) {
        for (int r = 0; r < 4; r++) {
            if (board[t][r] <= 10) {
                cout << "Team " << t + 1 << " scored <= 10 in Round " << r + 1 << "\n";
                break;
            }
        }
    }
}

int main() {
    int scores[6][4], totals[6];
    enterScores(scores);
    computeTotals(scores, totals);
    findWinners(totals);
    lowScoringRounds(scores);
    return 0;
}
