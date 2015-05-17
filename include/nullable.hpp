/// @author Владимир Керимов

namespace data
{
    /// Reference which allows null without crash
    template <typename value_type>
    class nullable
    {
    public:
        nullable();
        nullable(value_type* value);

        value_type* operator -> ();
        value_type const* operator -> () const;

        value_type& operator * ();
        value_type const& operator * () const;

    private:
        value_type* m_value;
    };
}

// sine qua non
