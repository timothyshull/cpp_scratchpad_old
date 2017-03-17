#include <iostream>
#include <thread>
#include <vector>


std::mutex m;
int i{0};


class background_task {
private:
    int id_;
public:
    background_task(int id) : id_{id} { }

    void operator()() const {
        std::lock_guard<std::mutex> lock(m);
        i += 1;
        std::cout << i << "\n";
    }
};

int main() {
    std::vector<std::thread> threads;

    for (int j{0}; j < 20; ++j) {
        threads.push_back(std::thread(background_task{j}));
    }

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return 0;
}