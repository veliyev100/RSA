# RSA

- Этот проект реализует алгоритм шифрования и дешифрования RSA на языке C++
- Для хранения больших чисел используется библиотека Boost
## Функционал
- Генерация ключей (публичного и приватного).
- Шифрование текста с использованием RSA.
- Дешифрование текста, зашифрованного RSA.
## Функции
- Prime_number(cpp_int n) (Проверка простоты числа)
- modPow(cpp_int mas, cpp_int exp, cpp_int mod) (Быстрое возведение в степень по модулю)
- GenerateKey(cpp_int p, cpp_int q) (Генерация закрытой экспоненты d)
- TextToNumber(const std::string &text) (Преобразование строки в число)
- NumberToText(cpp_int num) (Преобразование числа в строку)
- EncryptBlock(cpp_int m, cpp_int e, cpp_int n) (Шифрование блока текста.Размер блока будет соответствовать размеру сообщения, но при желании его можно изменить)
- DecryptBlock(cpp_int c, cpp_int d, cpp_int n); Дешифрование блока текста 
- EncryptText(const std::string &message, cpp_int e, cpp_int n,cpp_int l); Шифрование текста
- DecryptText(const std::vector<cpp_int> &encryptedBlocks, cpp_int d, cpp_int n); Дешифрование текста
