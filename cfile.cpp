#include <fstream>
#include "cfile.h"
#include "cexception.h"


EImg::CFile::CFile()
    : fName {}
    , fSize {0}
{ }

EImg::CFile::CFile(std::string f_name)
    : fName {f_name}
    , fSize {0}
{
    openFile();
}

EImg::CFile::CFile(const CFile &obj)
    : fName {obj.fName}
    , fData {obj.fData}
    , fSize {obj.fSize}
{ }

EImg::CFile::~CFile() {}

void EImg::CFile::openFile() {
    std::ifstream fIn(fName.data(), std::ifstream::ate | std::fstream::binary);

    if (!fIn) {       
        throw EImg::CFileOpneError();
    }

    fSize = fIn.tellg();
    fData.resize(fSize);

    fIn.seekg(std::fstream::beg);
    fIn.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        for (unsigned int i = 0; i < fSize; ++i) {
            fData[i] = fIn.get();
        }

        fIn.close();
    } catch (const std::ifstream::failure &e) {
        fIn.close();
        throw EImg::CFileReadError();
    }
}


/*
 * Save fData to file "path".
 * if path == "" than save to fName.
 * if fName == "" than raise excepion
 */
void EImg::CFile::save(std::string path) const {
    if (path == "") {
        throw EImg::CFileSaveError();
    }

    std::ofstream fOut(path.data(), std::fstream::binary);
    if (!fOut) {
        throw EImg::CFileOpneError();
    }

    fOut.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        for (unsigned int i = 0; i < fSize; ++i) {
            fOut.put(fData[i]);
        }

        fOut.close();
    } catch (const std::ofstream::failure &e) {
        fOut.close();
        throw EImg::CFileWriteError();
    }

}
