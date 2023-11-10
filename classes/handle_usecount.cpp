# include <iostream>

/**
 * @brief use class UseCount
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

class UseCount {
public:
    UseCount();
    UseCount(const UseCount&);
    UseCount& operator=(const UseCount&);
    ~UseCount();
    bool only();
    bool reattach(const UseCount&);
    bool makeonly();
private:
    int* p;
};

UseCount::UseCount(): p(new int(1)) {}

UseCount::UseCount(const UseCount& u): p(u.p) 
{
    ++*p; 
}

UseCount::~UseCount() 
{
    if (--*p == 0) {
        delete p;
    }
}

bool UseCount::only() 
{
    return *p == 1;
}

bool UseCount::reattach(const UseCount& u)
{
    ++*u.p;
    if (--*p == 0) 
    {
        delete p;
        p = u.p;
        return true;
    }
    p = u.p;
    return false;
}

bool UseCount::makeonly()
{
    if (*p == 1)
    {
        return false;
    }
    --*p;
    p = new int(1);
    return true;
}


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

    // int handle_count();

private:
    Point* p;
    // using Point* instead of UPoint* allows us to not only attach Handle with a Ponter
    // but also to a drived class of Pointer
    UseCount u;
};

Handle::Handle(): p(new Point) {}

Handle::Handle(int x, int y): p(new Point(x, y)) {}

Handle::Handle(const Point& p0): p(new Point(p0)) {}

Handle::Handle(const Handle& h): u(h.u), p(h.p) { }

Handle& Handle::operator=(const Handle& h) 
{
    if (u.reattach(h.u)) 
    {
        delete p;
    }
    p = h.p;
    return *this;
}

Handle::~Handle()
{
    if (u.only())
    {
        delete p;
    }
}

int Handle::x() const {
    return p->x();
}

Handle& Handle::x(int x0) 
{
    if(u.makeonly())
    {
        p = new Point(*p);
    }
    p->x(x0);
    return *this;
}

// int Handle::handle_count ()
// {
//     return u->p;
// }


int main() 
{
    Point p1(1, 2);
    Point p2(3, 4);
    
    Handle p1_h1(p1);
    Handle p1_h2(p1_h1); // create Handle from another Handle to increase the count u
    Handle p1_h3(p1_h1);

    // std::cout << "Number of handles of p1:" << p1_h3.handle_count() << std::endl;

    return 0;
}