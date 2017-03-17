#include <list>
#include <mutex>

using some_list = std::list<int>;
using some_mutex = std::mutex;

void add_to_list(int new_value);

bool list_contains(int value_to_find);

int main() {

}

void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}
