Perfect 👍 since your teacher is using folder + multiple files, I’ll give you proper structure (like your other assignments).

Clean, simple, beginner style.


---

📂 FILE STRUCTURE

shape.h
shape.cpp
circle.h
circle.cpp
square.h
square.cpp
triangle.h
triangle.cpp
righttriangle.h
righttriangle.cpp
equilateraltriangle.h
equilateraltriangle.cpp
client.cpp


---

✅ shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
};

#endif


---

✅ circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
    float r;

public:
    Circle(float);
    void area();
    void perimeter();
};

#endif


---

✅ circle.cpp

#include "circle.h"

Circle::Circle(float x)
{
    r = x;
}

void Circle::area()
{
    cout << "Area of Circle: " << 3.14 * r * r << endl;
}

void Circle::perimeter()
{
    cout << "Circumference: " << 2 * 3.14 * r << endl;
}


---

✅ square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
    float s;

public:
    Square(float);
    void area();
    void perimeter();
};

#endif


---

✅ square.cpp

#include "square.h"

Square::Square(float x)
{
    s = x;
}

void Square::area()
{
    cout << "Area of Square: " << s * s << endl;
}

void Square::perimeter()
{
    cout << "Perimeter: " << 4 * s << endl;
}


---

✅ triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
protected:
    float a, b, c;

public:
    Triangle(float, float, float);
    void perimeter();
};

#endif


---

✅ triangle.cpp

#include "triangle.h"

Triangle::Triangle(float x, float y, float z)
{
    a = x;
    b = y;
    c = z;
}

void Triangle::perimeter()
{
    cout << "Perimeter: " << a + b + c << endl;
}


---

✅ righttriangle.h

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle(float, float, float);
    void area();
};

#endif


---

✅ righttriangle.cpp

#include "righttriangle.h"

RightTriangle::RightTriangle(float x, float y, float z)
    : Triangle(x, y, z) {}

void RightTriangle::area()
{
    cout << "Area of Right Triangle: " << 0.5 * a * b << endl;
}


---

✅ equilateraltriangle.h

#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(float);
    void area();
};

#endif


---

✅ equilateraltriangle.cpp

#include "equilateraltriangle.h"
#include<math.h>

EquilateralTriangle::EquilateralTriangle(float x)
    : Triangle(x, x, x) {}

void EquilateralTriangle::area()
{
    cout << "Area of Equilateral Triangle: "
         << (sqrt(3)/4) * a * a << endl;
}


---

✅ client.cpp

#include "circle.h"
#include "square.h"
#include "righttriangle.h"
#include "equilateraltriangle.h"

int main()
{
    Shape *s;
    int choice;

    cout << "1.Circle 2.Square 3.Right Triangle 4.Equilateral Triangle\n";
    cin >> choice;

    if(choice == 1)
    {
        float r;
        cin >> r;
        s = new Circle(r);
    }
    else if(choice == 2)
    {
        float x;
        cin >> x;
        s = new Square(x);
    }
    else if(choice == 3)
    {
        float a,b,c;
        cin >> a >> b >> c;
        s = new RightTriangle(a,b,c);
    }
    else if(choice == 4)
    {
        float a;
        cin >> a;
        s = new EquilateralTriangle(a);
    }

    s->area();
    s->perimeter();

    return 0;
}


---

⚠️ COMPILE COMMAND

g++ *.cpp -o new


---

🔥 What this covers

✔ inheritance
✔ multilevel inheritance
✔ abstract class
✔ function overriding
✔ runtime polymorphism
✔ multiple files
✔ header guards


---

🎯 Viva gold answers

👉 Why Shape is abstract?

> Because it has pure virtual functions.



👉 Why pointer used?

> To achieve runtime polymorphism.



👉 Which inheritance used?

> Hierarchical + multilevel.




---

🚀 You’re now fully ready

This is exactly teacher-level submission.


---

If you want next: 👉 I can draw full inheritance diagram (VERY useful for exam)
👉 or give expected output + sample run
