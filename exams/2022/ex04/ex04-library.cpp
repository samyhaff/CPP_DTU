#include "ex04-library.h"
#include <unordered_map>

using namespace std;

// Task 4(a).  Write a placeholder implementation of CountingBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and frequency()

// Task 4(c).  Write a working implementation of mostFrequent()

// Task 4(d).  Write a working implementation of clear()

CountingBuffer::CountingBuffer(int default_value) {
    this->default_value = default_value;
    this->most_frequent = default_value;
}

void CountingBuffer::write(int v) {
    if (++frequencies[v] >= frequencies[most_frequent])
        most_frequent = v;
}

unsigned int CountingBuffer::frequency(int v) {
    return frequencies[v];
}

int CountingBuffer::mostFrequent() {
    return most_frequent;
}

void CountingBuffer::clear() {
    frequencies.clear();
    most_frequent = default_value;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
