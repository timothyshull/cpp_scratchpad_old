// dynamic allocation and polymorphism
#include <iostream>
#include <json_spirit/json_spirit.h>

class Polygon {
protected:
    int width, height;
public:
    Polygon(int a, int b) : width(a), height(b) {}

    virtual ~Polygon() {}

    virtual int area(void) =0;

    json_spirit::Object get_json_object() {
        json_spirit::Object poly_obj;
        poly_obj["width"] = this->width;
        poly_obj["height"] = this->height;
        poly_obj["area"] = this->area();
        return poly_obj;
    }

    void printarea() { std::cout << this->area() << '\n'; }
};

class Rectangle : public Polygon {
public:
    Rectangle(int a, int b) : Polygon(a, b) {}

    int area() { return width * height; }
};

class Triangle : public Polygon {
public:
    Triangle(int a, int b) : Polygon(a, b) {}

    int area() { return width * height / 2; }
};

int main() {
    Polygon *ppoly1 = new Rectangle(4, 5);
    Polygon *ppoly2 = new Triangle(4, 5);
    json_spirit::Object poly_obj = ppoly1->get_json_object();
    json_spirit::write_formatted(poly_obj, std::cout);
    std::cout << std::endl;
//    ppoly1->printarea();
//    ppoly2->printarea();
    delete ppoly1;
    delete ppoly2;
    return 0;
}