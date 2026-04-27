#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
    const size_t responseSize{20};
    array<int, responseSize> responses{1, 2, 3, 2, 4, 3, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3};
    
    const size_t frequncySize{6};
    array<unsigned int, frequncySize> frequency{};

    for (int i{0}; i < responseSize; ++i) {
      ++frequency[responses[i]];
    }

    for (int i{1}; i < frequncySize; ++i) {
      cout << "Frequency: " << i << ": " << frequency[i] << endl;
    }
    
}
