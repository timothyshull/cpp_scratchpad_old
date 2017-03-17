// dynamic allocation and polymorphism
//#include <iostream>

class Polygon {
protected:
    int width, height;
public:
    Polygon(int a, int b) : width(a), height(b) {}

    virtual ~Polygon() {}

    virtual int area(void) =0;

//    void printarea() { std::cout << this->area() << '\n'; }
};

class Rectangle : public Polygon {
public:
    Rectangle(int a, int b) : Polygon(a, b) {}

    int area() { return width * height; }
};

//class Triangle : public Polygon {
//public:
//    Triangle(int a, int b) : Polygon(a, b) {}
//
//    int area() { return width * height / 2; }
//};

int main() {
//    Polygon poly1(4, 5);
    Rectangle rect(4, 5);
//    Polygon *ppoly1 = new Rectangle(4, 5);
//    Polygon *ppoly2 = new Triangle(4, 5);
//    std::cout << std::endl;
//    ppoly1->printarea();
//    ppoly2->printarea();
//    int a = ppoly1->area();
//    ppoly2->area();
//    delete ppoly1;
//    delete ppoly2;
    return 0;
}