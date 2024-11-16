#include "rsa.h"
#include <iostream>
#include <string>

int main() {
    cpp_int p = 406586897;
    cpp_int q = 562448657;

    cpp_int d = GenerateKey(p, q);
    cpp_int e = 65537;
    cpp_int n = p * q;

    std::string message;
    std::cout << "Введите сообщение для шифрования: ";

    std::cin >> message;
    std::vector<cpp_int> encryptedMessage = EncryptText(message, e, n);
    std::cout << "Зашифрованное сообщение: ";
    for (const auto &block : encryptedMessage) {
        std::cout << block << " ";
    }
    std::cout << std::endl;

    std::string decryptedMessage = DecryptText(encryptedMessage, d, n);
    std::cout << "Расшифрованное сообщение: " << decryptedMessage << std::endl;

    return 0;
}
