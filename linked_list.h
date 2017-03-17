#include <memory>
#include <iostream>

template<typename Tp>
class linked_list;

template<typename Tp>
class list_node {
public:
    using value_type = Tp;
    using pointer = std::shared_ptr<list_node<value_type>>;

    list_node() : _data{value_type{}} { }

    explicit list_node(const value_type& value) : _data{value} { }

    friend class linked_list<value_type>;

private:
    value_type _data;
    pointer _next;
};

template<typename Tp>
class linked_list {
public:
    using value_type = Tp;
    using node_pointer = std::shared_ptr<list_node<value_type>>;

    void push_back(const value_type& value) {
        if (_root) {
//            list_node<value_type>* current_node(_root.get());
            node_pointer current_node{_root};
            while (current_node->_next != nullptr) {
//                current_node = current_node->_next.get();
                current_node = current_node->_next;
            }
//            current_node->_next = std::make_shared<list_node<value_type>>(value);
            current_node->_next = node_pointer {new list_node<value_type>{value}};
        }
        else {
//            _root = std::make_shared<list_node<value_type>>(value);
            _root = node_pointer {new list_node<value_type>{value}};
        }
    }

    void print() const {
        node_pointer current_node{_root};

        while (current_node != nullptr) {
            std::cout << current_node->_data << "\n";
            current_node = current_node->_next;
        }

        std::cout << std::endl;
    }


private:
    node_pointer _root;
};