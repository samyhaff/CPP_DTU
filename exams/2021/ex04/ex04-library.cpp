#include "ex04-library.h"
#include <algorithm>

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and writeCount()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of readAvg()

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}

SensorBuffer::SensorBuffer(unsigned int n) {
    this->n = n;
    write_count = 0;
    values = std::vector<int>();
}

void SensorBuffer::write(int v) {
    values.push_back(v);
    write_count++;
}

int SensorBuffer::read() {
    if (values.empty()) return 0;
    return values.back();
}

int SensorBuffer::readAvg() {
    if (values.empty()) return 0;
    int avg = 0;
    for (int i = 1; i <= std::min(n, (unsigned int) values.size()); i++)
        avg += values.end()[-i];
    avg /= std::min(n, (unsigned int) values.size());
    return avg;
}

unsigned int SensorBuffer::writeCount() {
    return write_count;
}
