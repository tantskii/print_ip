/*!
\file
\brief Заголовочный файл с реализацией стуктур для проверок типа данных

Данный файл содержит в себе реализацию проверок для в контейнеров (std::list, std::vector),
строки (std::string), а также в целочисленных типов
*/

#pragma once

#include <type_traits>
#include <list>
#include <vector>
#include <tuple>

template <typename T>
struct is_container {
    static const bool value = false;
};

template <typename T>
struct is_container<std::vector<T>> {
    static const bool value = true;
};

template <typename T>
struct is_container<std::list<T>> {
    static const bool value = true;
};

template<typename T>
inline constexpr bool is_container_v = is_container<T>::value;


template <typename T>
struct is_string {
    static const bool value = false;
};

template <>
struct is_string<std::string> {
    static const bool value = true;
};

template<typename T>
inline constexpr bool is_string_v = is_string<T>::value;










