#include <iostream>

using namespace std;

int count(int A, bool forward) {
    if (A > 0) {
        if (forward) {
            int sum = A + count(A - 1, forward);
            cout << " " << A;
            return sum;
        }
        else {
            cout << " " << A;
            return A + count(A - 1, forward);
        }
    }
    return 0;
}

int main() {
    int sum = count(1, true);
    cout << " sum = " << sum << '\n';

    sum = count(2, true) + count(1, false);
    cout << " sum = " << sum << '\n';

    sum = count(3, true) + count(2, false);
    cout << " sum = " << sum << '\n';

    sum = count(2, true) + count(1, false);
    cout << " sum = " << sum << '\n';

    sum = count(1, true);
    cout << " sum = " << sum;

    return 0;
}
