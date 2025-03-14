
// parallelArraysV2.cpp from Canvas
#include <iostream>

using namespace std;
bool valid(int value);
void getInput(string [], int [], int [], int [], int);
void display(const string [], const int [], const int [],
             const int [], int);
int calculateTotal(const int [], const int [],
             const int [], int /**, double &**/);
char letterGrade(double );
int findMin(int, int, int);

int main()
{
    const int SIZE = 2,
              NUM_TESTS = 3;
    string names[SIZE];
    int t1Scores[SIZE];
    int t2Scores[SIZE];
    int t3Scores[SIZE];
    double average;

    getInput(names, t1Scores, t2Scores, t3Scores, SIZE);
    ///display(names, t1Scores, t2Scores, t3Scores, SIZE);

    for (int index =0; index < SIZE; index++)
    {
        int total = calculateTotal(t1Scores, t2Scores,
                            t3Scores, index);
        cout << "total: " << total << endl;
        average = static_cast<double> (total) / NUM_TESTS;

        cout << "average: " << average << endl;
        int minimum = findMin(t1Scores[index], t2Scores[index], t3Scores[index]);
        cout << minimum << endl;
        /**
        drop minimum score
        **/
        total -= minimum;
        cout << "updated total: " << total << endl;
        /**
        find updated average after dropping the minimum score
        **/
        average = static_cast<double> (total) / (NUM_TESTS - 1);
        cout << "updated average: " << average << endl;
        cout << "letter grade: " << letterGrade(average) << endl;
    }

    return 0;
}

void getInput(string name[], int t1Score[], int t2Score[], int t3Score[],
              int arrSize)
{
    for (int index = 0; index < arrSize; index++)
    {
        cout << "Enter name: ";
        getline(cin, name[index]);
        cout << "Enter test 1 score (0 - 100): ";
        cin >> t1Score[index];
        while (!valid(t1Score[index]))
        {
            cout << "Invalid input!" << endl;
            cout << "Enter test 1 score (0 - 100): ";
            cin >> t1Score[index];
        }
        cout << "Enter test 2 score (0 - 100): ";
        cin >> t2Score[index];
        while (!valid(t2Score[index]))
        {
            cout << "Invalid input!" << endl;
            cout << "Enter test 2 score (0 - 100): ";
            cin >> t2Score[index];
        }
        cout << "Enter test 3 score (0 - 100): ";
        cin >> t3Score[index];
        while (!valid(t3Score[index]))
        {
            cout << "Invalid input!" << endl;
            cout << "Enter test 3 score (0 - 100): ";
            cin >> t3Score[index];
        }
        cin.ignore();
    }
}

bool valid(int value)
{
    bool status = true;
    if (value < 0 || value > 100)
        status = false;

    return status;
}

void display(const string name[], const int t1Score[], const int t2Score[],
             const int t3Score[], int arrSize)
{
    for(int index = 0; index < arrSize; index++)
    {
        cout << "Name: " << name[index] << endl;
        cout << "Test1 score: " << t1Score[index] << endl;
        cout << "Test2 score: " << t2Score[index] << endl;
        cout << "Test3 score: " << t3Score[index] << endl;
    }
}

int calculateTotal(const int t1Score[], const int t2Score[],
             const int t3Score[], int index)
{
    int total = t1Score[index] + t2Score[index] + t3Score[index];
    //average = total / 3.0;
    return total;
}

char letterGrade(double average)
{
    char letterGrade;
    if (average >= 90.0)
        letterGrade = 'A';
    else if (average >= 80.0)
        letterGrade = 'B';
    else if (average >= 70.0)
        letterGrade = 'C';
    else if (average >= 60.0)
        letterGrade = 'D';
    else
        letterGrade = 'F';

    return letterGrade;
}

int findMin(int num1, int num2, int num3)
{
    ///12, 10, 9
    int minimum = num1;
    /**
    if (num1 <= num2 && num1 <= num3)
        minimum = num1;
    else if(num2 <= num3 && num2 <= num1)
        minimum = num2;
    else
        minimum = num3;
    **/
    if (num2 <= minimum)
        minimum = num2;
    if (num3 <= minimum)
        minimum = num3;

    return minimum;
}
