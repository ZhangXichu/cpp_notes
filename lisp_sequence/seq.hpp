template<class T> class Sequence {
public:
    // create and return a sequence with no elements
    Sequence();
    // create and return a sequence with first element t and subsequent elements
    // those of s
    Sequence(const T& t, const Sequence& s); 
    // return the first element of the Sequence, Sequence must have >= 1 elements
    T hd() const;
    // create and return a sequence containing all but the first element of Sequence, 
    // Sequence must have >= 1 elements
    Sequence tl() const;
    // return false if Sequence has no elements; true otherwise
    operator bool() const;
};


template <class T> 
class SequenceItem {
    friend class Sequence<T>;

    int use_count;
    const T data;
    SequenceItem* next;

    SequenceItem(const T& t, SequenceItem* s);
    SequenceItem(const T& t) : use_count(1), data(t), next(nullptr) {}
};


template <class T> 
SequenceItem<T>::SequenceItem(const T& t, SequenceItem* s)
    : use_count(1), data(t), next(s)
{
    if (s)
    {
        s->use_count++;
    }
}