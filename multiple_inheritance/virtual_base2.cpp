//
// Created by Tim Shull on 10/19/16.
//

struct B {
    int n;

    B(int x) : n(x) {}
};

struct X : virtual B {
    X() : B(1) {}
};

struct Y : virtual B {
    Y() : B(2) {}
};

struct AA : X, Y {
    AA() : B(3), X(), Y() {}
};



int main() {
    // the default constructor of AA calls the default constructors of X and Y
    // but those constructors do not call the constructor of B because B is a virtual base
    AA a; // a.n == 3
    // the default constructor of X calls the constructor of B
    X x; // x.n == 1
    return 0;
}