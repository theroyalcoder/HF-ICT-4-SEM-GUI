#include <iostream>
#include <queue>
using namespace std;
/*
1. Durch string go
2. Ischs e "(", "{", "[" ? ja --> in e queue pushe
3. Ischs e ")", "}", "]" ? ja --> pop vo dr queue
4. verglieche
*/

queue<int> klammerDeleter (queue<int> q, int val) {
    queue<int> q2;
    bool flag = false;


    while (!q.empty()) {
        if(!flag && q.front() == val) {
            q.pop();
            flag = true;
        } else {
            q2.push(q.front());
            q.pop();
        }
    }

    return q2;
}

bool klammernCheck(string str) {
    queue<int> q;
    bool checker = false;

    for (char i : str) {
        switch (i) {
            case 40:
//                cout << "(" << endl;
                q.push(i);
                break;

            case 91:
//                cout << "[" << endl;
                q.push(i);
                break;

            case 123:
//                cout << "{" << endl;
                q.push(i);
                break;

            case 41:
//                cout << ")" << endl;
                q = klammerDeleter(q, 40);
                break;

            case 93:
//                cout << "]" << endl;
                q = klammerDeleter(q, 91);
                break;

            case 125:
//                cout << "}" << endl;
                q = klammerDeleter(q, 123);
                break;

            default:
                cout << i << " is a undefined value" << endl;
                break;
        }
    }

    //Falls queue nicht leer, dann hat es klammern uebrig
    checker = q.empty();

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return checker;
}

int main() {

//    klammernCheck("(({{[[)}]]})");
//    cout << endl << endl;

//    cout << klammernCheck("((){}[])");
//    cout << endl << endl;

//    cout << klammernCheck("(((");
//    cout << endl << endl;

    cout << klammernCheck("(({){}}[])");
    cout << endl << endl;

    return 0;
}
