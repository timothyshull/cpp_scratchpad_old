#include <thread>
#include <iostream>

void do_something(int& i) {
    i += 1;
//    std::cout << "doing something: " << i;

}

struct func {
    int& i;

    func(int& i_) : i{i_} { }

    void operator()() {
        for (unsigned j = 0; j < 10000000; ++j) {
            do_something(i);
        }
        std::cout << std::endl;
    }
};

void oops() {
    int some_local_state{0};
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
}

int main() {
    oops();
    sleep(5000);
}
