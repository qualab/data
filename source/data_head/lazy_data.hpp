/// @author Владимир Керимов

#pragma once

#include <memory>

namespace data
{
    /// Template for lazy_data initialization and copy-on-write
    template <class data_type>
    class lazy_data
    {
    public:
        /// lazy_data initialization
        lazy_data();

        /// Storage for created data
        explicit lazy_data(data_type* created_data);

        /// Storage for created data of derived data class
        template <class derived_data_type>
        explicit lazy_data(derived_data_type* created_data);

        /// Call of non-modifying method
        data_type const* operator -> () const;

        /// Call of modifying method
        data_type* operator -> ();

        /// Clone data to the new container
        lazy_data clone() const;

        template <class base_data_type>
        lazy_data<base_data_type> clone_as() const;

    private:
        mutable std::shared_ptr<data_type> m_shared_data;

        void ensure_initialized() const;
        void ensure_unique_referenced() const;
    };

//  -- implementation of the template class methods --

    template <class data_type>
    lazy_data<data_type>::lazy_data()
        : m_shared_data()
    {
    }

    template <class data_type>
    lazy_data<data_type>::lazy_data(data_type* created_data)
        : m_shared_data(created_data)
    {
    }

    template <class data_type>
    template <class derived_data_type>
    lazy_data<data_type>::lazy_data(derived_data_type* created_data)
        : m_shared_data(created_data)
    {
    }

    template <class data_type>
    data_type const* lazy_data<data_type>::operator -> () const
    {
        ensure_initialized();
        return m_shared_data.get();
    }

    template <class data_type>
    data_type* lazy_data<data_type>::operator -> ()
    {
        ensure_unique_referenced();
        return m_shared_data.get();
    }

    template <class data_type>
    void lazy_data<data_type>::ensure_initialized() const
    {
        if (!m_shared_data)
            m_shared_data.reset(new data_type);
    }

    template <class data_type>
    void lazy_data<data_type>::ensure_unique_referenced() const
    {
        ensure_initialized();
        if (!m_shared_data.unique())
            m_shared_data.reset(new data_type(*m_shared_data));
    }

    template <class data_type>
    lazy_data<data_type> lazy_data<data_type>::clone() const
    {
        return lazy_data<data_type>(new data_type(*m_shared_data));
    }

    template <class data_type>
    template <class base_data_type>
    lazy_data<base_data_type> lazy_data<data_type>::clone_as() const
    {
        return lazy_data<base_data_type>(new data_type(*m_shared_data));
    }
}

// sine qua non
