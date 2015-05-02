/// @author Владимир Керимов

namespace data
{
    template <typename holder_type>
    class allow_null
    {
    public:
        allow_null();
        allow_null(holder_type* holder);

    private:
        holder_type m_holder;
    };
}

// sine qua non
