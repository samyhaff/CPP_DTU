#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
class SensorBuffer : public Buffer {
private:
    unsigned int n;
    int write_count;
    std::vector<int> values;
public:
    SensorBuffer(unsigned int n);
    virtual void write(int v);
    virtual int read();
    int readAvg();
    unsigned int writeCount();
};

#endif /* EX04_LIBRARY_H_ */
