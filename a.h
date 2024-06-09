#pragma once 
#include <iostream>

using namespace std;
class mnog{
private:
    int LEN = 0;
    int* kof = new int[LEN];
    int x = 0;
    int otvet = 0;

public:  
    mnog() {
        LEN = 15;
        kof = new int[LEN];
        x = 0;
        otvet = 0;
    }
    mnog(int a, int* b, int x1) {
        LEN = a;
            for (int i = 0; i < LEN; i++){
                kof[i] = b[i];
            }
        x = x1;
    }
mnog(const mnog& other) : LEN(other.LEN) {
    kof = new int[LEN];
    for (int i = 0; i < LEN; i++) {
        kof[i] = other.kof[i];
    }
    x = other.x;
    otvet = other.otvet;
    LEN = other.LEN;
}

    ~mnog() {
        delete[] kof;
    }
    friend std::istream& operator>>(std::istream& is, mnog& num);
    friend std::ostream& operator<<(std::ostream& out, const mnog& s);
    void calculations();
    void print();
    void input(int a, int* b, int x);
    mnog operator+(mnog& num);
    mnog operator-(mnog& num);
    mnog operator*(mnog& num);
    mnog operator/(mnog& num);
    void operator=(mnog& num);

};
