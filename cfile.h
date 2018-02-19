#ifndef CFILE_H
#define CFILE_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "eicore.h"

namespace EImg {
/*
 *
 *
 */
class CFile {
    std::string fName;
    std::vector<BYTE> fData;
    unsigned int fSize;

    void openFile();

public:
    CFile();
    CFile(std::string f_name);
    CFile(const CFile &obj);
   ~CFile();

    inline std::string  getFName() const { return fName; }
    inline void         setFName(std::string f_name) { fName = f_name; }

    // return file size in bytes
    inline unsigned int getFSize() const { return fSize; }

    inline std::shared_ptr<std::vector<BYTE>> getFData() const { return std::make_shared<std::vector<BYTE>>(fData); }

    void save(std::string path="") const;

};




}

#endif // CFILE_H
