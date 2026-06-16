#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    vector<double> grade(n), credit(n);

    double totalCredits = 0, totalGradePoints = 0;

    // Input grades and credits
    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter Grade Point: ";
        cin >> grade[i];
        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    // Calculate GPA/CGPA
    double cgpa = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n------ Course Details ------\n";
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " -> Grade Point: " << grade[i]
             << ", Credit Hours: " << credit[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Semester GPA / Overall CGPA: " << cgpa << endl;

    return 0;
}