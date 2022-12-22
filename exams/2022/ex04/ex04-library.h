#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <unordered_map>

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual void clear() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class CountingBuffer, by extending Buffer
class CountingBuffer : public Buffer {
private:
    std::unordered_map<int,unsigned int> frequencies;
    int most_frequent;
    int default_value;
public:
    CountingBuffer(int default_value);
    virtual void write(int v);
    virtual void clear();
    unsigned int frequency(int v);
    int mostFrequent();
};

#endif /* EX04_LIBRARY_H_ */
