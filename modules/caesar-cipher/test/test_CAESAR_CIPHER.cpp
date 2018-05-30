// Copyright 2018 Lenkin Slava

#include <gtest/gtest.h>
#include <string>
#include "include/Caesar_Cipher.h"

TEST(CAESAR_CIPHER_Test, Can_Convert1) {
    // Arrage
    std::string input_s = "a";
    int shift = 1;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s,  shift);
    // Assert
    EXPECT_EQ("b", result);
}
TEST(CAESAR_CIPHER_Test, Can_Convert2) {
    // Arrage
    std::string input_s = "abc";
    int shift = 1;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s, shift);
    // Assert
    EXPECT_EQ("bcd", result);
}
TEST(CAESAR_CIPHER_Test, Can_Convert3) {
    // Arrage
    std::string input_s = "aa bb";
    int shift = 1;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s, shift);
    // Assert
    EXPECT_EQ("bb cc", result);
}
TEST(CAESAR_CIPHER_Test, zero_string) {
    // Arrage
    std::string input_s = "";
    // Assert
    ASSERT_NO_THROW();
}
TEST(CAESAR_CIPHER_Test, Can_Convert4) {
    // Arrage
    std::string input_s = "bbb";
    int shift = -1;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s, shift);
    // Assert
    EXPECT_EQ("aaa", result);
}
TEST(CAESAR_CIPHER_Test, Can_Convert5) {
    // Arrage
    std::string input_s = "aaa";
    int shift = -1;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s, shift);
    // Assert
    EXPECT_EQ("zzz", result);
}
TEST(CAESAR_CIPHER_Test, Can_Convert6) {
    // Arrage
    std::string input_s = "zzz";
    int shift = 1;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s, shift);
    // Assert
    EXPECT_EQ("aaa", result);
}
TEST(CAESAR_CIPHER_Test, Can_Convert7) {
    // Arrage
    std::string input_s = "aaabbb";
    int shift = 2;
    CAESAR_CIPHER tmp;
    // Act
    std::string result = tmp.cipher(input_s, shift);
    // Assert
    EXPECT_EQ("cccddd", result);
}
