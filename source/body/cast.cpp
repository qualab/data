/// @author Владимир Керимов

#include <data/cast>
#include <cstddef>
#include <cstdio>
#include <string>

#ifdef _MSC_VER
#define snscanf   _snscanf
#define snprintf  _snprintf
#define snwscanf  _snwscanf
#define snwprintf _snwprintf
#endif

#define DATA_BYTE_FORMAT_INT64  "%lld"
#define DATA_BYTE_FORMAT_INT32  "%ld"
#define DATA_BYTE_FORMAT_INT16  "%hd"
#define DATA_BYTE_FORMAT_UINT64 "%llu"
#define DATA_BYTE_FORMAT_UINT32 "%lu"
#define DATA_BYTE_FORMAT_UINT16 "%hu"
#define DATA_BYTE_FORMAT_DOUBLE "%LG"
#define DATA_BYTE_FORMAT_FLOAT  "%G"

#define DATA_BYTE_STRING_NULL   "null"
#define DATA_BYTE_STRING_TRUE   "true"
#define DATA_BYTE_STRING_FALSE  "false"

#define DATA_WIDE( literal_constant ) L ## #literal_constant

#define DATA_WIDE_FORMAT_INT64  DATA_WIDE( DATA_BYTE_FORMAT_INT64 )
#define DATA_WIDE_FORMAT_INT32  DATA_WIDE( DATA_BYTE_FORMAT_INT32 )
#define DATA_WIDE_FORMAT_INT16  DATA_WIDE( DATA_BYTE_FORMAT_INT16 )
#define DATA_WIDE_FORMAT_UINT64 DATA_WIDE( DATA_BYTE_FORMAT_UINT64 )
#define DATA_WIDE_FORMAT_UINT32 DATA_WIDE( DATA_BYTE_FORMAT_UINT32 )
#define DATA_WIDE_FORMAT_UINT16 DATA_WIDE( DATA_BYTE_FORMAT_UINT16 )
#define DATA_WIDE_FORMAT_DOUBLE DATA_WIDE( DATA_BYTE_FORMAT_DOUBLE )
#define DATA_WIDE_FORMAT_FLOAT  DATA_WIDE( DATA_BYTE_FORMAT_FLOAT )

#define DATA_WIDE_STRING_NULL   DATA_WIDE( DATA_BYTE_STRING_NULL )
#define DATA_WIDE_STRING_TRUE   DATA_WIDE( DATA_BYTE_STRING_TRUE )
#define DATA_WIDE_STRING_FALSE  DATA_WIDE( DATA_BYTE_STRING_FALSE )

namespace data
{
    char const* const byte_string_null  = DATA_BYTE_STRING_NULL;
    char const* const byte_string_true  = DATA_BYTE_STRING_TRUE;
    char const* const byte_string_false = DATA_BYTE_STRING_FALSE;

    wchar_t const* const wide_string_null  = DATA_WIDE_STRING_NULL;
    wchar_t const* const wide_string_true  = DATA_WIDE_STRING_TRUE;
    wchar_t const* const wide_string_false = DATA_WIDE_STRING_FALSE;

    template <typename char_type>
    struct string_operations
    {
        typedef int (*const read_function)(char_type const*, size_t, char_type const*, ...);
        typedef int (*const write_function)(char_type*, size_t, char_type const*, ...);
        
        static read_function  reader;
        static write_function writer;
    };

    template <> string_operations<char>::read_function string_operations<char>::reader = snscanf;
    template <> string_operations<char>::write_function string_operations<char>::writer = snprintf;
    template <> string_operations<wchar_t>::read_function string_operations<wchar_t>::reader = snwscanf;
    template <> string_operations<wchar_t>::write_function string_operations<wchar_t>::writer = snwprintf;

    template <typename value_type>
    struct string_value
    {
        static size_t const max_length;
    };

    template <typename value_type, typename char_type>
    struct string_format
    {
        static char_type const* const format;
    };

    template <> size_t const string_value<int64_t >::max_length = 20;
    template <> size_t const string_value<int32_t >::max_length = 11;
    template <> size_t const string_value<int16_t >::max_length = 6;
    template <> size_t const string_value<int8_t  >::max_length = 4;
    template <> size_t const string_value<uint64_t>::max_length = 20;
    template <> size_t const string_value<uint32_t>::max_length = 10;
    template <> size_t const string_value<uint16_t>::max_length = 5;
    template <> size_t const string_value<uint8_t >::max_length = 3;
    template <> size_t const string_value<double  >::max_length = 15;
    template <> size_t const string_value<float   >::max_length = 15;

    template <> char const* const string_format<int64_t,  char>::format = DATA_BYTE_FORMAT_INT64;
    template <> char const* const string_format<int32_t,  char>::format = DATA_BYTE_FORMAT_INT32;
    template <> char const* const string_format<int16_t,  char>::format = DATA_BYTE_FORMAT_INT16;
    template <> char const* const string_format<int8_t,   char>::format = DATA_BYTE_FORMAT_INT16;
    template <> char const* const string_format<uint64_t, char>::format = DATA_BYTE_FORMAT_UINT64;
    template <> char const* const string_format<uint32_t, char>::format = DATA_BYTE_FORMAT_UINT32;
    template <> char const* const string_format<uint16_t, char>::format = DATA_BYTE_FORMAT_UINT16;
    template <> char const* const string_format<uint8_t,  char>::format = DATA_BYTE_FORMAT_UINT16;
    template <> char const* const string_format<double,   char>::format = DATA_BYTE_FORMAT_DOUBLE;
    template <> char const* const string_format<float,    char>::format = DATA_BYTE_FORMAT_FLOAT;

    template <> wchar_t const* const string_format<int64_t,  wchar_t>::format = DATA_WIDE_FORMAT_INT64;
    template <> wchar_t const* const string_format<int32_t,  wchar_t>::format = DATA_WIDE_FORMAT_INT32;
    template <> wchar_t const* const string_format<int16_t,  wchar_t>::format = DATA_WIDE_FORMAT_INT16;
    template <> wchar_t const* const string_format<uint64_t, wchar_t>::format = DATA_WIDE_FORMAT_UINT64;
    template <> wchar_t const* const string_format<uint32_t, wchar_t>::format = DATA_WIDE_FORMAT_UINT32;
    template <> wchar_t const* const string_format<uint16_t, wchar_t>::format = DATA_WIDE_FORMAT_UINT16;
    template <> wchar_t const* const string_format<double,   wchar_t>::format = DATA_WIDE_FORMAT_DOUBLE;
    template <> wchar_t const* const string_format<float,    wchar_t>::format = DATA_WIDE_FORMAT_FLOAT;

    template <typename value_type, typename char_type>
    bool cast_to_string(std::basic_string<char_type>& result, value_type const& value)
    {
        result.resize(string_value<value_type>::max_length);
        int length = string_operations<char_type>::writer(&result.at(0), result.size(),
                                              string_format<value_type, char_type>::format, value);
        result.resize(length);
        return true;
    }

    template <typename value_type, typename char_type>
    bool try_cast_from_string(value_type& result, std::basic_string<char_type> const& source)
    {
        int count = string_operations<char_type>::reader(source.c_str(), source.size(),
                                            string_format<value_type, char_type>::format, &result);
        return count == 1;
    }

    bool type_cast<std::string, std::nullptr_t>::try_cast(std::string& result, std::nullptr_t const& )
    {
        result = byte_string_null;
        return true;
    }

    bool type_cast<std::string, bool>::try_cast(std::string& result, bool const& value)
    {
        result = value ? byte_string_true : byte_string_false;
        return true;
    }

    bool type_cast<std::string, int64_t>::try_cast(std::string& result, int64_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, int32_t>::try_cast(std::string& result, int32_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, int16_t>::try_cast(std::string& result, int16_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, int8_t>::try_cast(std::string& result, int8_t const& value)
    {
        return cast_to_string(result, static_cast<int16_t>(value));
    }

    bool type_cast<std::string, uint64_t>::try_cast(std::string& result, uint64_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, uint32_t>::try_cast(std::string& result, uint32_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, uint16_t>::try_cast(std::string& result, uint16_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, uint8_t>::try_cast(std::string& result, uint8_t const& value)
    {
        return cast_to_string(result, static_cast<uint16_t>(value));
    }

    bool type_cast<std::string, double>::try_cast(std::string& result, double const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::string, float>::try_cast(std::string& result, float const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<bool, std::string>::try_cast(bool& result, std::string const& value)
    {
        result = !value.empty();
        return true;
    }

    bool type_cast<int64_t, std::string>::try_cast(int64_t& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<int32_t, std::string>::try_cast(int32_t& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<int16_t, std::string>::try_cast(int16_t& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<int8_t, std::string>::try_cast(int8_t& result, std::string const& value)
    {
        int16_t holder;
        if (!try_cast_from_string(holder, value))
            return false;
        result = cast<int8_t>(holder);
        return true;
    }

    bool type_cast<uint64_t, std::string>::try_cast(uint64_t& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<uint32_t, std::string>::try_cast(uint32_t& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<uint16_t, std::string>::try_cast(uint16_t& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<uint8_t, std::string>::try_cast(uint8_t& result, std::string const& value)
    {
        uint16_t holder;
        if (!try_cast_from_string(holder, value))
            return false;
        result = cast<uint8_t>(holder);
        return true;
    }

    bool type_cast<double, std::string>::try_cast(double& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<float, std::string>::try_cast(float& result, std::string const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<std::wstring, std::nullptr_t>::try_cast(std::wstring& result, std::nullptr_t const& )
    {
        result = wide_string_null;
        return true;
    }

    bool type_cast<std::wstring, bool>::try_cast(std::wstring& result, bool const& value)
    {
        result = value ? wide_string_true : wide_string_false;
        return true;
    }

    bool type_cast<std::wstring, int64_t>::try_cast(std::wstring& result, int64_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, int32_t>::try_cast(std::wstring& result, int32_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, int16_t>::try_cast(std::wstring& result, int16_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, int8_t>::try_cast(std::wstring& result, int8_t const& value)
    {
        return cast_to_string(result, static_cast<int16_t>(value));
    }

    bool type_cast<std::wstring, uint64_t>::try_cast(std::wstring& result, uint64_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, uint32_t>::try_cast(std::wstring& result, uint32_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, uint16_t>::try_cast(std::wstring& result, uint16_t const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, uint8_t>::try_cast(std::wstring& result, uint8_t const& value)
    {
        return cast_to_string(result, static_cast<uint16_t>(value));
    }

    bool type_cast<std::wstring, double>::try_cast(std::wstring& result, double const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<std::wstring, float>::try_cast(std::wstring& result, float const& value)
    {
        return cast_to_string(result, value);
    }

    bool type_cast<bool, std::wstring>::try_cast(bool& result, std::wstring const& value)
    {
        result = !value.empty();
        return true;
    }

    bool type_cast<int64_t, std::wstring>::try_cast(int64_t& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<int32_t, std::wstring>::try_cast(int32_t& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<int16_t, std::wstring>::try_cast(int16_t& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<int8_t, std::wstring>::try_cast(int8_t& result, std::wstring const& value)
    {
        int16_t holder;
        if (!try_cast_from_string(holder, value))
            return false;
        result = cast<int8_t>(holder);
        return true;
    }

    bool type_cast<uint64_t, std::wstring>::try_cast(uint64_t& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<uint32_t, std::wstring>::try_cast(uint32_t& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<uint16_t, std::wstring>::try_cast(uint16_t& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<uint8_t, std::wstring>::try_cast(uint8_t& result, std::wstring const& value)
    {
        uint16_t holder;
        if (!try_cast_from_string(holder, value))
            return false;
        result = cast<uint8_t>(holder);
        return true;
    }

    bool type_cast<double, std::wstring>::try_cast(double& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }

    bool type_cast<float, std::wstring>::try_cast(float& result, std::wstring const& value)
    {
        return try_cast_from_string(result, value);
    }
}

// sine qua non
