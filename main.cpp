#include "rsa.h"
#include <iostream>
#include <string>

int main() {
    cpp_int p = 2305843009213693951;
    cpp_int q = 18014398241046527;

    cpp_int d = GenerateKey(p, q);
    cpp_int e = 65537;
    cpp_int n = p * q;
    int l = 0;

    std::string message;
    std::cout << "Введите сообщение для шифрования: ";

    std::cin >> message;
    l = message.size();
    std::vector<cpp_int> encryptedMessage = EncryptText(message, e, n, l);
    std::cout << "Зашифрованное сообщение: ";
    for (const auto &block : encryptedMessage) {
        std::cout << block << " ";
    }
    std::cout << std::endl;

    std::string decryptedMessage = DecryptText(encryptedMessage, d, n);
    std::cout << "Расшифрованное сообщение: " << decryptedMessage << std::endl;

    return 0;
}