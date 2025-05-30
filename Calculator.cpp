#include <bits/stdc++.h>
#include <cmath>
using namespace std;

float toRadians(float degrees) {
    return degrees * M_PI / 180.0;
}

float find(const string& s) {
    if (s.substr(0, 2) == "ln") {
        int start = s.find('(');
        int end = s.find(')');
        return log(stof(s.substr(start + 1, end - start - 1)));
    } else if (s.substr(0, 3) == "log") {
        int startBase = 3;
        int startNum = s.find('(');
        int endNum = s.find(')');
        return log(stof(s.substr(startNum + 1, endNum - startNum - 1))) / log(stof(s.substr(startBase, startNum - startBase)));
    } else if (s.substr(0, 3) == "sin") {
        int start = s.find('(');
        int end = s.find(')');
        float val = stof(s.substr(start + 1, end - start - 1));
        return sin(toRadians(val));
    } else if (s.substr(0, 3) == "cos") {
        int start = s.find('(');
        int end = s.find(')');
        float val = stof(s.substr(start + 1, end - start - 1));
        return cos(toRadians(val));
    } else if (s.substr(0, 3) == "tan") {
        int start = s.find('(');
        int end = s.find(')');
        float val = stof(s.substr(start + 1, end - start - 1));
        return tan(toRadians(val));
    } else {
        return stof(s);
    }
}

int main() {
    float result = 0.0, number;
    char operation;
    bool firstInput = true;
    string s1, s2;

    cout << "Continuous Calculator\n";
    cout << "Enter 'q' or 'Q' as operation to quit.\n";

    while (true) {
        if (firstInput) {
            cin >> s1;
            result = find(s1);
            firstInput = false;
        }

        cin >> operation;
        if (operation == 'q' || operation == 'Q') {
            cout << "Calculator stopped. Final result = " << result << endl;
            break;
        }

        cin >> s2;
        number = find(s2);

        switch (operation) {
            case '+': result += number; break;
            case '-': result -= number; break;
            case '*': result *= number; break;
            case '/':
                if (number == 0) {
                    cout << "Error: Division by zero!\n";
                    continue;
                }
                result /= number;
                break;
            default:
                cout << "Invalid operation!\n";
                continue;
        }

        cout << "Current result: " << result << endl;
        cout << result << " " << endl;
    }

    return 0;
}
