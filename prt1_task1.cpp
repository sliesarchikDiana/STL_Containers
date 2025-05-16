#include "prt1_task1.h"
#include <iostream>

int main() {
    const animal cat{"cat", "white", 2};
    const animal pug{"dog", "brown", 3};
    const animal fish{"goldfish", "golden", 1};
    const animal rabbit{"rabbit", "white", 2};
    const animal parrot{"parakeet", "green", 3};

    std::array<animal, 5> arr = {cat, pug, fish, rabbit, parrot};
    std::cout << " Array before clockwise shift: ";
    for (const auto& elem : arr) {
        std::cout << elem <<" ";
    }
    std::cout << std::endl;
    rotateClockwise(arr, 3);

    std::cout << " Array after clockwise shift: ";
    for (const auto& elem : arr) {
        std::cout << elem <<" ";
    }
    std::cout << std::endl;
    std::array<int, 5> int_arr = {1, 2, 3, 4, 5};
    std::cout << " Array before clockwise shift: ";
    for (const auto& elem : int_arr) {
        std::cout << elem <<" ";
    }
    std::cout << std::endl;
    rotateClockwise(int_arr, 2);
    std::cout << " Array after clockwise shift: ";
    for (const auto& elem : int_arr) {
        std::cout << elem <<" ";
    }
    std::cout << std::endl<<std::endl;




    std::vector<int> numbers1 {1, 2, 3, 4, 5};
    std::vector<int> numbers2 {10, 20, 30};
    std::cout << "First vector before insertion: ";
    for (const auto& num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    insertRange(numbers1, numbers1.begin() + 3, numbers2);

    std::cout << "First vector after insertion: ";
    for (const auto& num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    std::vector<animal> animals1 {cat, pug, fish};
    std::vector<animal> animals2 {rabbit, parrot};

    std::cout << "Animal vector before insertion: ";
    for (const auto& a : animals1) {
        std::cout << a << " ";
    }
    std::cout << std::endl;


    insertRange(animals1, animals1.end(), animals2);

    std::cout << "Animal vector after insertion: ";
    for (const auto& a : animals1) {
        std::cout << a << " ";
    }
    std::cout << std::endl<<std::endl;




    std::deque<int> dq1 {1, 2, 3, 4, 5};

    std::cout << "Deque before erase (odd amount of elements): ";
    for (const auto& elem : dq1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    removeMiddleElements(dq1);
    std::cout << "Deque after erase: ";
    for (const auto& elem : dq1) {
        std::cout << elem << " ";
    }
    std::cout <<std::endl;


    std::deque<std::string> dq2 {"apple", "banana", "pear", "orange", "tangerine", "plum"};

    std::cout << "Deque before erase (even amount of elements): ";
    for (const auto& elem : dq2) {
        std::cout << elem << " ";
    }
    std::cout <<std::endl;
    removeMiddleElements(dq2);
    std::cout << "Deque after erase: ";
    for (const auto& elem : dq2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::deque<animal> animals {cat, pug, fish, rabbit, parrot};
    std::cout << "Animal deque before erase: ";
    for (const auto& a : animals) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    removeMiddleElements(animals);

    std::cout << "Animal deque after erase: ";
    for (const auto& a : animals) {
        std::cout << a << " ";
    }
    std::cout << "\n";

    return 0;
}