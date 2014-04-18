/// @author Владимир Керимов

#pragma once

namespace std
{
    template <typename char_type>
    class allocator;

    template <typename char_type>
    struct char_traits;

    template <typename char_type,
              typename traits_type=char_traits<char_type>,
              typename allocator_type=allocator<char_type>>
    class basic_string;

    typedef basic_string<char> string;
    typedef basic_string<wchar_t> wstring;

    template <typename value_type>
    class shared_ptr;

    template <typename value_type>
    class unique_ptr;
}

// sine qua non
