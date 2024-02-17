template<class T> class Sequence {
public:
    // create and return a sequence with no elements
    Sequence()
        :item(nullptr);
    // create and return a sequence with first element t and subsequent elements
    // those of s
    Sequence(const T& t, const Sequence& s):
        item(new SequenceItem<T>(t, s.item)) {}
    // copy constructor
    Sequence(const Sequence& s)
    {
        if (item) {
            item->use_count++;
        }
    }
    // copy asssignment
    Sequence& operator=(const Sequence& s)
    {
        if (s.item)
            s.item->use_count++;
        destory(item);  // TODO : implement destory()
        item = s.item;
        return *this;
    }

    ~Sequence();
    {
        destory(item);
    }

    // return the first element of the Sequence, Sequence must have >= 1 elements
    T hd() const
    {
        if (item)
        {
            return item->data;
        } else {
            throw "hd of an empty Seq";
        }
    }
    // create and return a sequence containing all but the first element of Sequence, 
    // Sequence must have >= 1 elements
    Sequence tl() const
    {
        if (item) {
            return Sequence<T> (item->next);
        } else {
            throw "tl of an empty Sequence.";
        }
    }
    // return false if Sequence has no elements; true otherwise
    operator bool() const
    {
        return item != nullptr;
    }

private:
    SequenceItem<T>* item; // head

    Sequence(SequenceItem<T>* s) // used form creating a Sequence from a tail
        : item(s)
        {
            if (s) 
                s->use_count++;
        }

    void destory(SequenceItem* item)
    {
        while (item && --item->use == 0)
        {
            SequenceItem* next = item->next;
            delete item;
            item = next;
        }
    }
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