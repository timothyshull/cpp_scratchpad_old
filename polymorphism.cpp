//#include <iostream>

class Base {
public:
    virtual int virtual_method() {
//        std::cout << "Base::virtual_method();" << "\n";
        return 0;
    }
};

class Child1 : public Base {
    int virtual_method() {
//        std::cout << "Child1::virtual_method();" << "\n";
        return 1;
    }
};

class Child2 : public Base {
    int virtual_method() {
//        std::cout << "Child2::virtual_method();" << "\n";
        return 2;
    }
};

void polymorphic_client(Base *obj) {
    obj->virtual_method();
}

int main() {
    Base b;
    Child1 c1;
    Child2 c2;
    Base *bp1 = &b;
    Base *bp2 = &c1;
    Base *bp3 = &c2;
    polymorphic_client(bp1);
    polymorphic_client(bp2);
    polymorphic_client(bp3);
    return 0;
}