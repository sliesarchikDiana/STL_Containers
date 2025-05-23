#ifndef PRT1_TASK1_H
#define PRT1_TASK1_H
#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <vector>
#include <deque>

class animal {
private:
    std::string species;
    std::string color;
    int age;

public:
    animal(std::string  species, std::string  color, const int age) : species(std::move(species)), color(std::move(color)), age(age){};
    ~animal() = default;

    [[nodiscard]]std::string get_species() const { return species; }
    [[nodiscard]]std::string get_color() const { return color; }
    [[nodiscard]]int get_age() const { return age; }

    friend std::ostream& operator<<(std::ostream& os, const animal& a) {
        os << a.species;
        return os;
    }

};

template<typename T, std::size_t N>
void rotateClockwise(std::array<T, N>& arr, std::size_t shift) {
    if (N == 0) return;
    shift %= N;
    if (shift == 0) return;
    std::vector<T> temp;
    temp.reserve(N);
    for (std::size_t i = 0; i < N; ++i) {
        temp.push_back(arr[(i + N - shift) % N]);
    }

    for (std::size_t i = 0; i < N; ++i) {
        arr[i] = temp[i];
    }
}



template<typename T>
void insertRange(std::vector<T>& destination, typename std::vector<T>::iterator position, const std::vector<T>& source) {
    destination.insert(position, source.begin(), source.end());
}


template<typename T>
void removeMiddleElements(std::deque<T>& dq) {
    if (dq.empty()) return;
    size_t size = dq.size();
    if (size % 2 == 1) {
        auto it = dq.begin() + size / 2;
        dq.erase(it);
    } else {
        auto it1 = dq.begin() + (size / 2 - 1);
        auto it2 = dq.begin() + size / 2 + 1;
        dq.erase(it1, it2);
    }
}

#endif // PRT1_TASK1_H