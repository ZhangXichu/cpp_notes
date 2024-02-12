template<class T> class Seq {
public:
    // create and return a sequence with no elements
    Seq();
    // create and return a sequence with first element t and subsequent elements
    // those of s
    Seq(const T& t, const Seq& s); 
    // return the first element of the Seq, Seq must have >= 1 elements
    T hd() const;
    // create and return a sequence containing all but the first element of Seq, 
    // Seq must have >= 1 elements
    Seq tl() const;
    // return false if Seq has no elements; true otherwise
    operator bool() const;
};