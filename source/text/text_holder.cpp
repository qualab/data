/// @author Владимир Керимов

#include <text/text_holder.hpp>
#include <text/text_instance.hpp>
#include <data/decimal>

namespace data
{
    text::holder::holder()
    {
    }

    text::holder::holder(char const* byte_string)
        : m_instance(new instance(byte_string))
    {
    }

    text::holder::holder(char const* byte_string, char const* encoding)
        : m_instance(new instance(byte_string, encoding))
    {
    }

    text::holder::holder(char const* byte_string, std::string const& encoding)
        : m_instance(new instance(byte_string, encoding))
    {
    }

    text::holder::holder(std::string const& byte_string)
        : m_instance(new instance(byte_string))
    {
    }

    text::holder::holder(std::string const& byte_string, char const* encoding)
        : m_instance(new instance(byte_string, encoding))
    {
    }

    text::holder::holder(std::string const& byte_string, std::string const& encoding)
        : m_instance(new instance(byte_string, encoding))
    {
    }

    text::holder::holder(wchar_t const* wide_string)
        : m_instance(new instance(wide_string))
    {
    }

    text::holder::holder(std::wstring const& wide_string)
        : m_instance(new instance(wide_string))
    {
    }

    object::holder* text::holder::copy_to(void* address) const
    {
        return new(address) text::holder(*this);
    }

    object::holder* text::holder::move_to(void* address) const
    {
        return new(address) text::holder(std::move(*this));
    }

    std::string const& text::holder::byte_string() const
    {
        return m_instance->byte_string();
    }

    std::string const& text::holder::byte_string(char const* encoding) const
    {
        return m_instance->byte_string(encoding);
    }

    std::string const& text::holder::byte_string(std::string const& encoding) const
    {
        return m_instance->byte_string(encoding);
    }

    std::wstring const& text::holder::wide_string() const
    {
        return m_instance->wide_string();
    }

    char const* text::holder::byte_c_str() const
    {
        return m_instance->byte_c_str();
    }

    char const* text::holder::byte_c_str(char const* encoding) const
    {
        return m_instance->byte_c_str(encoding);
    }

    char const* text::holder::byte_c_str(std::string const& encoding) const
    {
        return m_instance->byte_c_str(encoding);
    }

    wchar_t const* text::holder::wide_c_str() const
    {
        return m_instance->wide_c_str();
    }

    bool text::holder::as_bool() const
    {
        return m_instance->as<bool>();
    }

    int64_t text::holder::as_int64() const
    {
        return m_instance->as<int64_t>();
    }

    int32_t text::holder::as_int32() const
    {
        return m_instance->as<int32_t>();
    }

    int16_t text::holder::as_int16() const
    {
        return m_instance->as<int16_t>();
    }

    int8_t text::holder::as_int8() const
    {
        return m_instance->as<int8_t>();
    }

    uint64_t text::holder::as_uint64() const
    {
        return m_instance->as<uint64_t>();
    }

    uint32_t text::holder::as_uint32() const
    {
        return m_instance->as<uint32_t>();
    }

    uint16_t text::holder::as_uint16() const
    {
        return m_instance->as<uint16_t>();
    }

    uint8_t text::holder::as_uint8() const
    {
        return m_instance->as<uint8_t>();
    }

    double text::holder::as_double() const
    {
        return m_instance->as<double>();
    }

    float text::holder::as_float() const
    {
        return m_instance->as<float>();
    }

    decimal text::holder::as_decimal() const
    {
        return m_instance->as<decimal>();
    }
}

// sine qua non
