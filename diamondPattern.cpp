#include <iostream> /* Krispachi */
using namespace std;

int main() {
    int input, l;
    cout << "Masukkan n : ";
    cin >> input;
    int n = input * 2 - 1;

    for(int i = 1; i <= n; i++) {
        l = i;
        if(i > input) {
            l -= (i - input) * 2;
        }
        for(int j = input; j > l; j--) {
            cout << "'";
        }
        for(int k = 1; k <= (l*2-1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}