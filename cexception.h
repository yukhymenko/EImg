#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <exception>

namespace EImg {

class CException : public std::exception {
    virtual const char * what() const throw() {
        return "EImg Base exception";
    }
};

class CFileReadError : public CException {
    virtual const char * what() const throw() {
        return "EImg File Read Exception";
    }
};

class CFileWriteError : public CException {
    virtual const char * what() const throw() {
        return "EImg File Write Exception";
    }
};

class CFileOpneError : public CException {
    virtual const char * what() const throw() {
        return "EImg File Open Exception";
    }
};

class CFileSaveError : public CException {
    virtual const char * what() const throw() {
        return "EImg File Save Exception";
    }
};

}

#endif // CEXCEPTION_H
