# include <iostream>


class Point {
    
public:
    Point() : xval(0), yval(0) {
        std::cout << "Init Point." << std::endl;
    }
    Point(int x, int y): xval(x), yval(y) {
        std::cout << "Init x to " << x << ", init y to " << y << std::endl;
     }
    int x() const { 
        std::cout << "x = " << xval << std::endl;
        return xval; 
        
    }
    int y() const { 
        std::cout << "y = " << yval << std::endl;
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


int main() {

    // illegal when custom constructor is present
    // Point p;

    Point p(5, 6);

    return 0;
}