#include <iostream>
using namespace std;

void enterVotes(int result[4][6]) {
    for (int c = 0; c < 4; c++) {
        cout << "Candidate " << c + 1 << " votes:\n";
        for (int s = 0; s < 6; s++) {
            cout << "  Station " << s + 1 << ": ";
            cin >> result[c][s];
        }
    }
}

void totalVotes(int result[4][6]) {
    for (int c = 0; c < 4; c++) {
        int sum = 0;
        for (int s = 0; s < 6; s++)
            sum += result[c][s];
        cout << "Total votes for Candidate " << c + 1 << ": " << sum << "\n";
    }
}

void votesPerStation(int result[4][6]) {
    for (int s = 0; s < 6; s++) {
        int sum = 0;
        for (int c = 0; c < 4; c++)
            sum += result[c][s];
        cout << "Total at Station " << s + 1 << ": " << sum;
        if (sum < 100) cout << " (Low turnout)";
        cout << "\n";
    }
}

void electionWinner(int result[4][6]) {
    int max = 0, winner = 0;
    for (int c = 0; c < 4; c++) {
        int sum = 0;
        for (int s = 0; s < 6; s++)
            sum += result[c][s];
        if (sum > max) {
            max = sum;
            winner = c;
        }
    }
    cout << "Winner: Candidate " << winner + 1 << " with " << max << " votes\n";
}

int main() {
    int votes[4][6];
    enterVotes(votes);
    totalVotes(votes);
    votesPerStation(votes);
    electionWinner(votes);
    return 0;
}
