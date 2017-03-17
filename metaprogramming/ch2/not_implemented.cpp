// an alternative to deleting a function
template<typename T>
class X {
    X<T> &operator=(X<T> &that) { static_assert(false); }
};

// or
template<typename T>
class Y {
    Y<T> &operator=(Y<T> &that) { static_assert(sizeof(T) == 0); }
};
