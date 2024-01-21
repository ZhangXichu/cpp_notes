# include <iostream>

/**
 * @brief counter is in the Handle class
 * 
 */

class Point {
    
public:
    Point() : xval(0), yval(0) {
        std::cout << "Init Point." << std::endl;
    }
    Point(int x, int y): xval(x), yval(y) {
        std::cout << "Init x to " << x << ", init y to " << y << std::endl;
     }
    int x() const { 
        return xval; 
        
    }
    int y() const { 
        return yval; 
        
    }
    Point& x(int xv) { 
        std::cout << "Setting x to " << xv << std::endl;
        xval = xv; 
        return *this; 
        
    }
    Point& y(int yv) { 
        std::cout << "Setting y to " << yv << std::endl;
        yval = yv; 
        return *this; 
    }
    
private:
    int xval, yval;
    
};

class Handle {
public:
    Handle();
    Handle(int, int);
    Handle(const Point&);
    Handle(const Handle&);
    Handle& operator=(const Handle&);
    ~Handle();

    int x() const;
    Handle& x(int);
    int y() const;
    Handle& y(int);

    int handle_count();

private:
    Point* p;
    // using Point* instead of UPoint* allows us to not only attach Handle with a Ponter
    // but also to a drived class of Pointer
    int* u;
};

Handle::Handle():
        u(new int(1)), p(new Point) {}

Handle::Handle(int x, int y):
        u(new int(1)), p(new Point(x, y)) {}

Handle::Handle(const Point& p0):
        u(new int(1)), p(new Point(p0)) {}

Handle::Handle(const Handle& h):
    u(h.u), p(h.p) { ++*u; }

Handle& Handle::operator=(const Handle& h)
{
    ++*h.u;
    if (--*u == 0)
    {
        delete u;
        delete p;
    }
    u = h.u;
    p = h.p;
    return *this;
}

Handle::~Handle()
{
    if (--*u == 0)
    {
        delete u;
        delete p;
    }
}

int Handle::handle_count ()
{
    return *u;
}

int main() 
{
    Point p1(1, 2);
    Point p2(3, 4);
    
    Handle p1_h1(p1);
    Handle p1_h2(p1_h1); // create Handle from another Handle to increase the count u
    Handle p1_h3(p1_h1);

    std::cout << "Number of handles of p1:" << p1_h3.handle_count() << std::endl;

    return 0;
}