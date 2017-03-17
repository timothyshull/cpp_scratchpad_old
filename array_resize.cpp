#include <iostream>

template<typename Item>
void resize(Item *array, size_t orig_size, size_t new_size) {
    if (new_size < orig_size) {
        return;
    }

    if (array == nullptr) {
        std::cerr << "Bad array pointer \n";
        return;
    }

    Item *tmp;
    try {
        tmp = new Item[new_size];
    } catch (std::bad_alloc &e) {
        std::cerr << "bad_alloc: " << e.what() << "\n";
        return;  // or exit
    }
    // std::memcpy(tmp, array, orig_size);
    for (ptrdiff_t i = 0; i < orig_size; i++) {
        *(tmp + i) = *(array + i);
    }
    array = tmp;
}

int main() {
    int *array1 = new int[10];
    for (ptrdiff_t i = 0; i < 10; i++) {
        *(array1 + i) = static_cast<int>(i);
    }

    resize(array1, 10, 20);

    for (ptrdiff_t i = 0; i < 10; i++) {
        int tmp = *(array1 + i);
        std::cout << "Value at index " << i << " is " << tmp << "\n";
    }

    for (ptrdiff_t i = 10; i < 20; i++) {
        int tmp = *(array1 + i);
        std::cout << "Value of uninitialized memory at index " << i << " is " << tmp << "\n";
    }

    for (ptrdiff_t i = 10; i < 20; i++) {
        *(array1 + i) = static_cast<int>(i);
    }

    for (ptrdiff_t i = 0; i < 20; i++) {
        int tmp = *(array1 + i);
        std::cout << "Value at index " << i << " is " << tmp << "\n";
    }

    return 0;
}