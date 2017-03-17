#ifndef EXPERIMENTS_NODE_H
#define EXPERIMENTS_NODE_H

#include <memory>

namespace experiments {
    template<typename Tp>
    class node {
        using value_type = Tp;
        using pointer = std::unique_ptr<value_type>;
        using node_pointer = std::unique_ptr<node>;
        value_type _data;
        node_pointer _next;
    public:
        void set_data(value_type d) {
            _data = d;
        }

        value_type get_data() {
            return _data;
        }

        void set_next(node_pointer p) {
            _next = std::move(p);
        }

        node_pointer get_next() {
            return std::move(_next);
        }
    };
}

#endif // EXPERIMENTS_NODE_H


//#ifndef LIST_H
//#define LIST_H
//
//#include <memory>
//#include <iostream>
//
//class List {
//    struct Link {
//        int datum;
//        std::shared_ptr<Link> next;
//        explicit Link(int val = 0) : datum{ val } {
//            std::cout << "Link constructor invoked.\n";
//        }
//        ~Link() {
//            std::cout << "Link destructor invoked.\n";
//        }
//    };
//
//    std::shared_ptr<Link> root;
//    void reverse_print(std::shared_ptr<Link>) const;
//
//public:
//    explicit List() : root{ nullptr } {
//        std::cout << "List constructor invoked.\n";
//    }
//    ~List() {
//        std::cout << "List destructor invoked.\n";
//    }
//
//    void push_front(int);
//    void push_back(int);
//    void insert(int, int);
//    int length() const;
//    void print() const;
//    void reverse_print() const;
//    void initialize_list() const;
//
//    std::shared_ptr<Link> get_first( ) const;
//    void destroy_list( );
//    bool empty( ) const;
//
//    //void delete_first( );
//    //void delete_last( );
//    //bool delete_link(int val);
//};
//
//#endif