// Copyright 2018 Lenkin Slava
#ifndef MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_H_
#define MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_H_

#include <iostream>
#include <string>

class CAESAR_CIPHER{
 public:
    std::string cipher(const std::string & input_s, const int shift);
    int ABCSize;
    CAESAR_CIPHER();
    ~CAESAR_CIPHER();
 private:
    char *low_ch;
    char *high_ch;
    void Init_symbols();
};


#endif  // MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_H_
