//MGA4
#include <iostream>

using namespace std;

void addGrade(double grades[], int& count);
double getAvg(const double grades[], int count);
char getLetter(double avg);
const char* getPassFail(double avg);
void showSummary(const double grades[], int count);
void showMenu();

int main() {
    const int MAX_GRADES = 100;
    double grades[MAX_GRADES];
    int count = 0;
    int choice = 0;

    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Bad input. Type a number from 1 to 3.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addGrade(grades, count);
                break;
            case 2:
                showSummary(grades, count);
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Pick 1, 2, or 3.\n\n";
        }
    } while (choice != 3);

    return 0;
}

void showMenu() {
    cout << "=== Grade Book ===\n";
    cout << "1. Add Grade\n";
    cout << "2. View Summary\n";
    cout << "3. Exit\n";
    cout << "Choice: ";
}

void addGrade(double grades[], int& count) {
    if (count >= 100) {
        cout << "Grade list is full!\n\n";
        return;
    }

    double g = -1;
    while (true) {
        cout << "Enter grade (0 to 100): ";
        if (cin >> g) {
            if (g >= 0 && g <= 100) {
                break;
            } else {
                cout << "Must be between 0 and 100.\n";
            }
        } else {
            cout << "Not a number. Try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    grades[count] = g;
    count++;
    cout << "Grade added!\n\n";
}

double getAvg(const double grades[], int count) {
    if (count == 0) return 0;
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += grades[i];
    }
    return sum / count;
}

char getLetter(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

const char* getPassFail(double avg) {
    if (avg >= 60) {
        return "Pass";
    }
    return "Fail";
}

void showSummary(const double grades[], int count) {
    if (count == 0) {
        cout << "\nNo grades yet.\n\n";
        return;
    }

    double avg = getAvg(grades, count);
    char letter = getLetter(avg);
    const char* stat = getPassFail(avg);

    cout << "\n--- SUMMARY ---\n";
    cout << "Total grades: " << count << "\n";
    cout << "Grades: ";
    for (int i = 0; i < count; ++i) {
        cout << grades[i] << (i + 1 < count ? ", " : "");
    }
    cout << "\nAverage: " << avg << "%\n";
    cout << "Letter:  " << letter << "\n";
    cout << "Status:  " << stat << "\n";
    cout << "---------------\n\n";
} return 0;