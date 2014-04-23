/// @author Владимир Керимов

#include <data/api>
#include <data/stdfwd>
#include <cstdint>

namespace data
{
    class text;
    class object;

    template <typename result_type, typename argument_type>
    result_type cast(argument_type value);

    template<> DATA_API int64_t cast(int64_t value);
    template<> DATA_API int64_t cast(int32_t value);
    template<> DATA_API int64_t cast(int16_t value);
    template<> DATA_API int64_t cast(int8_t value);
    template<> DATA_API int64_t cast(uint64_t value);
    template<> DATA_API int64_t cast(uint32_t value);
    template<> DATA_API int64_t cast(uint16_t value);
    template<> DATA_API int64_t cast(uint8_t value);
    template<> DATA_API int64_t cast(double value);
    template<> DATA_API int64_t cast(float value);
    template<> DATA_API int64_t cast(bool value);
    template<> DATA_API int64_t cast(text value);
    template<> DATA_API int64_t cast(char const* value);
    template<> DATA_API int64_t cast(wchar_t const* value);
    template<> DATA_API int64_t cast(std::string const& value);
    template<> DATA_API int64_t cast(std::wstring const& value);
    template<> DATA_API int64_t cast(object value);

    template<> DATA_API uint64_t cast(int64_t value);
    template<> DATA_API uint64_t cast(int32_t value);
    template<> DATA_API uint64_t cast(int16_t value);
    template<> DATA_API uint64_t cast(int8_t value);
    template<> DATA_API uint64_t cast(uint64_t value);
    template<> DATA_API uint64_t cast(uint32_t value);
    template<> DATA_API uint64_t cast(uint16_t value);
    template<> DATA_API uint64_t cast(uint8_t value);
    template<> DATA_API uint64_t cast(double value);
    template<> DATA_API uint64_t cast(float value);
    template<> DATA_API uint64_t cast(bool value);
    template<> DATA_API uint64_t cast(text value);
    template<> DATA_API uint64_t cast(char const* value);
    template<> DATA_API uint64_t cast(wchar_t const* value);
    template<> DATA_API uint64_t cast(std::string const& value);
    template<> DATA_API uint64_t cast(std::wstring const& value);
    template<> DATA_API uint64_t cast(object value);

    template<> DATA_API int32_t cast(int64_t value);
    template<> DATA_API int32_t cast(int32_t value);
    template<> DATA_API int32_t cast(int16_t value);
    template<> DATA_API int32_t cast(int8_t value);
    template<> DATA_API int32_t cast(uint64_t value);
    template<> DATA_API int32_t cast(uint32_t value);
    template<> DATA_API int32_t cast(uint16_t value);
    template<> DATA_API int32_t cast(uint8_t value);
    template<> DATA_API int32_t cast(double value);
    template<> DATA_API int32_t cast(float value);
    template<> DATA_API int32_t cast(bool value);
    template<> DATA_API int32_t cast(text value);
    template<> DATA_API int32_t cast(char const* value);
    template<> DATA_API int32_t cast(wchar_t const* value);
    template<> DATA_API int32_t cast(std::string const& value);
    template<> DATA_API int32_t cast(std::wstring const& value);
    template<> DATA_API int32_t cast(object value);

    template<> DATA_API uint32_t cast(int64_t value);
    template<> DATA_API uint32_t cast(int32_t value);
    template<> DATA_API uint32_t cast(int16_t value);
    template<> DATA_API uint32_t cast(int8_t value);
    template<> DATA_API uint32_t cast(uint64_t value);
    template<> DATA_API uint32_t cast(uint32_t value);
    template<> DATA_API uint32_t cast(uint16_t value);
    template<> DATA_API uint32_t cast(uint8_t value);
    template<> DATA_API uint32_t cast(double value);
    template<> DATA_API uint32_t cast(float value);
    template<> DATA_API uint32_t cast(bool value);
    template<> DATA_API uint32_t cast(text value);
    template<> DATA_API uint32_t cast(char const* value);
    template<> DATA_API uint32_t cast(wchar_t const* value);
    template<> DATA_API uint32_t cast(std::string const& value);
    template<> DATA_API uint32_t cast(std::wstring const& value);
    template<> DATA_API uint32_t cast(object value);

    template<> DATA_API int16_t cast(int64_t value);
    template<> DATA_API int16_t cast(int32_t value);
    template<> DATA_API int16_t cast(int16_t value);
    template<> DATA_API int16_t cast(int8_t value);
    template<> DATA_API int16_t cast(uint64_t value);
    template<> DATA_API int16_t cast(uint32_t value);
    template<> DATA_API int16_t cast(uint16_t value);
    template<> DATA_API int16_t cast(uint8_t value);
    template<> DATA_API int16_t cast(double value);
    template<> DATA_API int16_t cast(float value);
    template<> DATA_API int16_t cast(bool value);
    template<> DATA_API int16_t cast(text value);
    template<> DATA_API int16_t cast(char const* value);
    template<> DATA_API int16_t cast(wchar_t const* value);
    template<> DATA_API int16_t cast(object value);

    template<> DATA_API uint16_t cast(int64_t value);
    template<> DATA_API uint16_t cast(int32_t value);
    template<> DATA_API uint16_t cast(int16_t value);
    template<> DATA_API uint16_t cast(int8_t value);
    template<> DATA_API uint16_t cast(uint64_t value);
    template<> DATA_API uint16_t cast(uint32_t value);
    template<> DATA_API uint16_t cast(uint16_t value);
    template<> DATA_API uint16_t cast(uint8_t value);
    template<> DATA_API uint16_t cast(double value);
    template<> DATA_API uint16_t cast(float value);
    template<> DATA_API uint16_t cast(bool value);
    template<> DATA_API uint16_t cast(text value);
    template<> DATA_API uint16_t cast(char const* value);
    template<> DATA_API uint16_t cast(wchar_t const* value);
    template<> DATA_API uint16_t cast(object value);

    template<> DATA_API int8_t cast(int64_t value);
    template<> DATA_API int8_t cast(int32_t value);
    template<> DATA_API int8_t cast(int16_t value);
    template<> DATA_API int8_t cast(int8_t value);
    template<> DATA_API int8_t cast(uint64_t value);
    template<> DATA_API int8_t cast(uint32_t value);
    template<> DATA_API int8_t cast(uint16_t value);
    template<> DATA_API int8_t cast(uint8_t value);
    template<> DATA_API int8_t cast(double value);
    template<> DATA_API int8_t cast(float value);
    template<> DATA_API int8_t cast(bool value);
    template<> DATA_API int8_t cast(text value);
    template<> DATA_API int8_t cast(char const* value);
    template<> DATA_API int8_t cast(wchar_t const* value);
    template<> DATA_API int8_t cast(object value);

    template<> DATA_API uint8_t cast(int64_t value);
    template<> DATA_API uint8_t cast(int32_t value);
    template<> DATA_API uint8_t cast(int16_t value);
    template<> DATA_API uint8_t cast(int8_t value);
    template<> DATA_API uint8_t cast(uint64_t value);
    template<> DATA_API uint8_t cast(uint32_t value);
    template<> DATA_API uint8_t cast(uint16_t value);
    template<> DATA_API uint8_t cast(uint8_t value);
    template<> DATA_API uint8_t cast(double value);
    template<> DATA_API uint8_t cast(float value);
    template<> DATA_API uint8_t cast(bool value);
    template<> DATA_API uint8_t cast(text value);
    template<> DATA_API uint8_t cast(char const* value);
    template<> DATA_API uint8_t cast(wchar_t const* value);
    template<> DATA_API uint8_t cast(object value);

    template<> DATA_API double cast(int64_t value);
    template<> DATA_API double cast(int32_t value);
    template<> DATA_API double cast(int16_t value);
    template<> DATA_API double cast(int8_t value);
    template<> DATA_API double cast(uint64_t value);
    template<> DATA_API double cast(uint32_t value);
    template<> DATA_API double cast(uint16_t value);
    template<> DATA_API double cast(uint8_t value);
    template<> DATA_API double cast(double value);
    template<> DATA_API double cast(float value);
    template<> DATA_API double cast(bool value);
    template<> DATA_API double cast(text value);
    template<> DATA_API double cast(char const* value);
    template<> DATA_API double cast(wchar_t const* value);
    template<> DATA_API double cast(object value);

    template<> DATA_API float cast(int64_t value);
    template<> DATA_API float cast(int32_t value);
    template<> DATA_API float cast(int16_t value);
    template<> DATA_API float cast(int8_t value);
    template<> DATA_API float cast(uint64_t value);
    template<> DATA_API float cast(uint32_t value);
    template<> DATA_API float cast(uint16_t value);
    template<> DATA_API float cast(uint8_t value);
    template<> DATA_API float cast(double value);
    template<> DATA_API float cast(float value);
    template<> DATA_API float cast(bool value);
    template<> DATA_API float cast(text value);
    template<> DATA_API float cast(char const* value);
    template<> DATA_API float cast(wchar_t const* value);
    template<> DATA_API float cast(object value);

    template<> DATA_API bool cast(int64_t value);
    template<> DATA_API bool cast(int32_t value);
    template<> DATA_API bool cast(int16_t value);
    template<> DATA_API bool cast(int8_t value);
    template<> DATA_API bool cast(uint64_t value);
    template<> DATA_API bool cast(uint32_t value);
    template<> DATA_API bool cast(uint16_t value);
    template<> DATA_API bool cast(uint8_t value);
    template<> DATA_API bool cast(double value);
    template<> DATA_API bool cast(float value);
    template<> DATA_API bool cast(bool value);
    template<> DATA_API bool cast(text value);
    template<> DATA_API bool cast(char const* value);
    template<> DATA_API bool cast(wchar_t const* value);
    template<> DATA_API bool cast(object value);

    template<> DATA_API text cast(int64_t value);
    template<> DATA_API text cast(int32_t value);
    template<> DATA_API text cast(int16_t value);
    template<> DATA_API text cast(int8_t value);
    template<> DATA_API text cast(uint64_t value);
    template<> DATA_API text cast(uint32_t value);
    template<> DATA_API text cast(uint16_t value);
    template<> DATA_API text cast(uint8_t value);
    template<> DATA_API text cast(double value);
    template<> DATA_API text cast(float value);
    template<> DATA_API text cast(bool value);
    template<> DATA_API text cast(text value);
    template<> DATA_API text cast(char const* value);
    template<> DATA_API text cast(wchar_t const* value);
    template<> DATA_API text cast(object value);
}

// sine qua non
