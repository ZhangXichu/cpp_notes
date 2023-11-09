# include <iostream>

/**
 * @brief Handle class with counter in a separate class UPoint
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

/**
 * @brief class used for holding the count of pointers to Point
 * 
 */
class UPoint {

    // all the members are private
    friend class Handle;
    Point p;
    int u;

    UPoint(): u(1) {}
    UPoint(int x, int y) : p(x, y), u(1) {}
    UPoint(const Point& p0) : p(p0), u(1) {}
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

private:
    UPoint *up;
};

Handle::Handle() : up(new UPoint) {
    std::cout << "Init Handle without parameters." << std::endl;
}
Handle::Handle(int x, int y) : up(new UPoint(x, y)) {
    std::cout << "Init Handle using x, y value." << std::endl;
    std::cout << "x = " << x << ", y = " << y <<std::endl;
}
Handle::Handle(const Point& p) : up(new UPoint(p)) {
    std::cout << "Init Handle using Point p" <<std::endl;
    std::cout <<  "p.x() = " << p.x() << " p.y() = " << p.y() << std::endl;

    std::cout << "u = " << up->u << std::endl;
}
// copy constructor
Handle::Handle(const Handle& h) : up(h.up) {
    ++up->u;
}

Handle::~Handle() {
    if (--up->u == 0) {
        delete up;
    }
}

// assign operator
Handle& Handle::operator=(const Handle& h_input) {
    // increase the count of the Handle on the right side
    h_input.up->u++;

    std::cout << "h_input.up->u = " << h_input.up->u << std::endl;

    // reduce the count of the Handle on the left side
    if (--up->u == 0) {
        std::cout << "old up in this object is deleted." << std::endl;
        delete up;
    } 
    up = h_input.up;

    std::cout << "new up in this object up->u = " << up->u << std::endl;

    return *this;
}

int Handle::x() const {
    return up->p.x();
}

int Handle::y() const {
    return up->p.y();
}

Handle& Handle::x(int x0) {
    up->p.x(x0);
    return *this;
}

Handle& Handle::y(int y0) {
    up->p.y(y0);
    return *this;
}

int main() {

    // illegal when custom constructor is present
    // Point p;

    Point p(5, 6);
    Point p2(12, 14);

    Handle handle_p(p);
    Handle handle_p2(p2);

    handle_p = handle_p2;

    return 0;
}