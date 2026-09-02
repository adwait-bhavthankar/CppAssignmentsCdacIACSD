// 10. Vowel or Consonant
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    ch = tolower(ch);

    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << ch << " is a vowel." << endl;
            break;
        default:
            if (isalpha(ch)) {
                cout << ch << " is a consonant." << endl;
            } else {
                cout << "Not an alphabet!" << endl;
            }
    }

    return 0;
}
