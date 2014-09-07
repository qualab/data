/// @author Владимир Керимов

#pragma once

namespace std
{
    template <typename char_type>
    class allocator;

    template <typename char_type>
    struct char_traits;

    template <typename char_type,
              typename traits_type,
              typename allocator_type>
    class basic_string;

    // std::string forward declaration
    typedef basic_string<char,
                         char_traits<char>,
                         allocator<char>> string;

    // std::wstring forward declaration
    typedef basic_string<wchar_t,
                         char_traits<wchar_t>,
                         allocator<wchar_t>> wstring;

    // std::nullptr_t forward declaration
    typedef decltype(nullptr) nullptr_t;
}

// sine qua non
