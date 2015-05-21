/// @author Владимир Керимов

#include <data/api>

namespace data
{
    /// Reference which allows null without crash
    template <class holder_type>
    class nullable
    {
    public:
        nullable();
        nullable(holder_type* pointer);

        nullable& operator = (holder_type* pointer);

        holder_type* operator -> ();
        holder_type const* operator -> () const;

        holder_type& operator * ();
        holder_type const& operator * () const;

    private:
        holder_type* m_pointer;

        void assert_exists();
    };

    DATA_API void throw_null_reference_exception();

    template <class holder_type>
    nullable<holder_type>::nullable()
        : m_pointer(nullptr)
    {
    }

    template <class holder_type>
    nullable<holder_type>::nullable(holder_type* pointer)
        : m_pointer(pointer)
    {
    }

    template <class holder_type>
    holder_type* nullable<holder_type>::operator -> ()
    {
        assert_exists();
        return m_pointer;
    }

    template <class holder_type>
    holder_type const* nullable<holder_type>::operator -> () const
    {
        assert_exists();
        return m_pointer;
    }

    template <class holder_type>
    holder_type& nullable<holder_type>::operator * ()
    {
        assert_exists();
        return *m_pointer;
    }

    template <class holder_type>
    holder_type const& nullable<holder_type>::operator * () const
    {
        assert_exists();
        return *m_pointer;
    }

    template <class holder_type>
    void nullable<holder_type>::assert_exists() const
    {
        if (!m_pointer)
            throw_null_reference_exception();
    }
}

// sine qua non
