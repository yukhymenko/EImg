#include <iostream>
#include "cfile.h"


int main() {
    EImg::CFile f1("q1.bmp");

    std::cout  << "f1.name() " << f1.getFName() << std::endl;
    std::cout << "f1.size() " << f1.getFSize() << std::endl;
    f1.save("w1.bmp");

    return 0;
}
