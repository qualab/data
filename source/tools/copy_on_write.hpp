/// @author Владимир Керимов

#include <memory>

namespace data
{
    template <class instance_type>
    class copy_on_write
    {
    public:
        copy_on_write();

        instance_type* operator -> ();
        instance_type const* operator -> () const;

    private:
        std::shared_ptr<instance_type> m_instance;
    };
}

// sine qua non
