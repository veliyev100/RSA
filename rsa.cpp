#include "rsa.h"
#include <iostream>

bool Prime_number(cpp_int n) {
    if (n <= 1) {
        return false;
    }
    for (cpp_int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

cpp_int modPow(cpp_int mas, cpp_int e, cpp_int mod) {
    cpp_int result = 1;
    mas = mas % mod;

    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * mas) % mod;
        }
        e = e / 2;
        mas = (mas * mas) % mod;
    }
    return result;
}

cpp_int GenerateKey(cpp_int p, cpp_int q) {
    if (!Prime_number(p) || !Prime_number(q)) {
        std::cout << "error";
        return 0;
    }
    cpp_int phi = (p - 1) * (q - 1);
    cpp_int e = 65537;
    cpp_int d = 0;
    cpp_int k = 1;
    while (true) {
        if ((k * phi + 1) % e == 0) {
            d = (k * phi + 1) / e;
            break;
        }
        ++k;
    }
    return d;
}

cpp_int TextToNumber(const std::string &text) {
    cpp_int num = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        num = num * 256 + static_cast<unsigned char>(text[i]);
    }
    return num;
}

std::string NumberToText(cpp_int num) {
    std::string text;
    while (num > 0) {
        text.insert(text.begin(), static_cast<char>(num % 256));
        num /= 256;
    }
    return text;
}

cpp_int EncryptBlock(cpp_int m, cpp_int e, cpp_int n) {
    return modPow(m, e, n);
}

cpp_int DecryptBlock(cpp_int c, cpp_int d, cpp_int n) {
    return modPow(c, d, n);
}

std::vector<cpp_int> EncryptText(const std::string &message, cpp_int e, cpp_int n) {
    std::vector<cpp_int> encryptedBlocks;
    size_t blockSize = 3;
    for (size_t i = 0; i < message.size(); i += blockSize) {
        std::string block = message.substr(i, blockSize);
        cpp_int m = TextToNumber(block);
        encryptedBlocks.push_back(EncryptBlock(m, e, n));
    }
    return encryptedBlocks;
}

std::string DecryptText(const std::vector<cpp_int> &encryptedBlocks, cpp_int d, cpp_int n) {
    std::string decryptedMessage;
    for (const cpp_int &otkkluc : encryptedBlocks) {
        cpp_int decryptedBlock = DecryptBlock(otkkluc, d, n);
        decryptedMessage += NumberToText(decryptedBlock);
    }
    return decryptedMessage;
}
