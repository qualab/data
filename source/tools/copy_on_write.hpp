/// @author Владимир Керимов

#include <memory>

namespace data
{
    template <class instance_type>
    class copy_on_write
    {
    public:
        copy_on_write();
        copy_on_write(instance_type* new_instance);

        instance_type* operator -> ();
        instance_type const* operator -> () const;

    private:
        mutable std::shared_ptr<instance_type> m_instance;

        bool ensure_exists() const;
        bool ensure_unique() const;
    };

    template <class instance_type>
    copy_on_write<instance_type>::copy_on_write()
    {
    }

    template <class instance_type>
    copy_on_write<instance_type>::copy_on_write(instance_type* new_instance)
        : m_instance(new_instance)
    {
    }

    template <class instance_type>
    instance_type* copy_on_write<instance_type>::operator -> ()
    {
        ensure_unique();
        return m_instance.get();
    }

    template <class instance_type>
    instance_type const* copy_on_write<instance_type>::operator -> () const
    {
        ensure_exists();
        return m_instance.get();
    }

    template <class instance_type>
    bool copy_on_write<instance_type>::ensure_exists() const
    {
        bool not_exists = !m_instance;
        if (not_exists)
            m_instance.reset(new instance_type);
        return not_exists;
    }

    template <class instance_type>
    bool copy_on_write<instance_type>::ensure_unique() const
    {
        bool not_unique = !ensure_exists() && !m_instance.unique();
        if (not_unique)
            m_instance.reset(new instance_type(instance_type));
        return not_unique;
    }
}

// sine qua non
