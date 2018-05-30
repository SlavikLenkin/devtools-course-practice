// Copyright 2018 Lenkin Slava
#include "include/Caesar_Cipher.h"
#include <string>

std::string CAESAR_CIPHER::cipher(const std::string & input_s,
                                  const int shift) {
    std::string output_s("");
    for (unsigned i = 0; i < input_s.length(); i++) {
        bool Ok = false;
        for (int j = 0; j < ABCSize; j++) {
             if (input_s[i] == low_ch[j]) {
                j += shift;
                while (j >= ABCSize) j -= ABCSize;
                while (j < 0) j += ABCSize;
                output_s += low_ch[j];
                Ok = true;
                break;
             } else {
                    if (input_s[i] == high_ch[j]) {
                       j += shift;
                       while (j >= ABCSize) j -= ABCSize; {
                         while (j < 0) j += ABCSize; {
                             output_s += high_ch[j];
                         }
                       }
                     Ok = true;
                     break;
                    }
             }
        }
        if (!Ok) {
           output_s += input_s[i];
        }
    }
      return output_s;
}

CAESAR_CIPHER::CAESAR_CIPHER() {
     Init_symbols();
}

CAESAR_CIPHER::~CAESAR_CIPHER() {
     ABCSize = 0;
     delete high_ch;
     delete low_ch;
}

void CAESAR_CIPHER::Init_symbols() {
    this->ABCSize = 26;
    this->high_ch = new char[ABCSize];
    this->low_ch = new char[ABCSize];
    const char low_ch[] = { 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z' };
    const char high_ch[] = { 'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z' };
    for (int i = 0; i < ABCSize; i++) {
        this->high_ch[i] = high_ch[i];
        this->low_ch[i] = low_ch[i];
     }
}
