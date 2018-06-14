#include <iostream>
using namespace std;

string decode(const string &str)
{
    int val = 0;
    string newstr = "";


    for (auto x : str) {
        if (x < 57 && x > 48) {
            //ist eine Zahl
            cout << endl << "Zahl: \t \t" << x << endl;


            decode();

        } else {
            // ist ein Buchstabe

            val = (int)x - 48;
            string tmpstr[val];

            for (int j = 0; j < val; j++) {
                tmpstr[j] = x;
            }

            for (auto y: tmpstr) {
                cout << y;

                newstr += y;
            }
            cout << endl;
        }
    }

    cout << endl;

    return newstr;
}

int main() {
    cout << decode("3n5m11f");
    return 0;
}