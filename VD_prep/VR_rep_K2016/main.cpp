#include <iostream>
using namespace std;

//Klausur 2015
int crossumRec(unsigned int n, int result) {
    return result + (n % 10);
}
int crossum(unsigned int n) {
    int result = 0;
    int localN = n;

    while (localN > 0) {
        result = crossumRec(localN, result);
        localN /= 10;
    }
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout << crossum(123);

    srand(static_cast<unsigned int>(time(nullptr)));


    return 0;
}
