#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graphic
{
public:
    virtual int calculate_area() = 0;
    virtual void show_area() = 0;
    bool compareGraph(Graphic &g1, Graphic &g2)
    {
        if (g1.calculate_area() > g2.calculate_area())
            return true;
        else
            return false;
    }
};

class Rectangle : public Graphic
{
protected:
    int width, length;

public:
    Rectangle(int w, int l)
    {
        width = w;
        length = l;
    }

    // TODO: (Hint: Implement virtual function)
    int calculate_area()
    {
        return width * length;
    }

    // TODO: (Hint: Implement virtual function)
    void show_area()
    {
        cout << "Rectangle area: " << calculate_area() << endl;
    }
};

class Circle : public Graphic
{
protected:
    int radius;
    float PI = 3.14;

public:
    Circle(int r)
    {
        // TODO
        radius = r;
    }

    // TODO: (Hint: Implement virtual function, Circle area need integer type)
    int calculate_area()
    {
        return radius * radius * PI;
    }

    // TODO: (Hint: Implement virtual function)
    void show_area()
    {
        cout << "Circle area: " << calculate_area() << endl;
    }
};

class Triangle : public Graphic
{
protected:
    int base, height;

public:
    Triangle(int b, int h)
    {
        base = b;
        height = h;
    }

    // TODO: (Hint: Implement virtual function)
    int calculate_area()
    {
        return (base * height) / 2;
    }

    // TODO: (Hint: Implement virtual function)
    void show_area()
    {
        cout << "Triangle area: " << calculate_area() << endl;
    }
};

int main()
{
    int r, b, h, l, w;
    // TODO: (Hint: Input)
    cin >> r >> b >> h >> l >> w;

    Graphic *graphic;
    Circle circle(r);
    Triangle triangle(b, h);
    Rectangle rectangle(l, w);

    // TODO: (Hint: show area)
    circle.show_area();

    // TODO: (Hint: show area)
    triangle.show_area();

    // TODO: (Hint: show area)
    rectangle.show_area();

    if (graphic->compareGraph(circle, triangle) && graphic->compareGraph(circle, rectangle))
        cout << "Circle has the largest area.";
    else if (graphic->compareGraph(triangle, circle) && graphic->compareGraph(triangle, rectangle))
        cout << "Triangle has the largest area.";
    else if (graphic->compareGraph(rectangle, circle) && graphic->compareGraph(rectangle, triangle))
        cout << "Rectangle has the largest area.";
    else
        cout << "At least two graphics are the same size.";

    return 0;
}