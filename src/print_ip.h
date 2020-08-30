/*!
\file
\brief Заголовочный файл с реализацией функций печати ip-адреса через механизм SFINAE

Данный файл содержит в себе реализацию печати в поток вывода ip-адреса, хранимого в контейнере (std::list, std::vector),
Строке (std::string), а также в целочисленном виде
*/

#pragma once

#include <iostream>

#include "my_type_traits.h"


/*!
Выводит в поток вывода ip-адрес, хранимый в std::list или std::vector
\param[out] os Поток вывода
\param[in] address ip-адрес
*/
template <typename T, typename std::enable_if_t<is_container_v<T>, bool> Fake = true>
void print_ip(const T& address, std::ostream& os) {
    size_t i = 1;
    for (const auto& elem: address) {
        os << elem;
        os << (i++ == address.size() ? '\n' : '.');
    }
}


/*!
Выводит в поток вывода ip-адрес, хранимый в целочисленных типах
\param[out] os Поток вывода
\param[in] address ip-адрес
*/
template <typename T, typename std::enable_if_t<std::is_integral<T>::value, bool> Fake = true>
void print_ip(const T& address, std::ostream& os) {
    uint8_t const * buffer = reinterpret_cast<uint8_t const *>(&address);
    size_t value_size = sizeof(T);

    for (size_t i = 1; i <= value_size; i++) {
        os << unsigned(buffer[value_size - i]);
        os << (i == value_size ? '\n' : '.');
    }
}


/*!
Выводит в поток вывода ip-адрес, хранимый в строковой форме
\param[out] os Поток вывода
\param[in] address ip-адрес
*/
template <typename T, typename std::enable_if_t<is_string_v<T>, bool> Fake = true>
void print_ip(const T& address, std::ostream& os) {
    os << address << '\n';
}
