#include <iostream>

// Base class representing a generic shape
class Shape {
public:
    // Virtual function to calculate the area of a shape (to be overridden by derived classes)
    virtual double area() {
        return 0.0; // Default implementation (for generic shapes)
    }
};

// Derived class representing a rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor with function overloading
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the base class area() function to calculate the area of a rectangle
    double area() override {
        return length * width;
    }
};

// Derived class representing a circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor with function overloading
    Circle(double r) : radius(r) {}

    // Override the base class area() function to calculate the area of a circle
    double area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Create an array of Shape pointers to store various shapes
    Shape* shapes[3];

    // Populate the array with instances of Rectangle and Circle
    shapes[0] = new Rectangle(5.0, 3.0);
    shapes[1] = new Circle(2.5);
    shapes[2] = new Rectangle(4.0, 4.0);

    // Calculate and print the areas of the shapes
    for (int i = 0; i < 3; i++) {
        std::cout << "Shape " << i + 1 << " Area: " << shapes[i]->area() << std::endl;
        delete shapes[i]; // Delete dynamically allocated objects
    }

    return 0;
}
