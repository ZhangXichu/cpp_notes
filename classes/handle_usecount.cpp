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
    UseCount u;
};