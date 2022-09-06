#include "UID.h"

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

UID UID::NONE;

UID::UID()
    : m_id(boost::uuids::random_generator()())
{
}

UID::UID(const std::string &str)
{
    m_id = NONE.m_id;

    if (str.length() > 0)
    {
        try
        {
            m_id = boost::lexical_cast<boost::uuids::uuid>(str);
        }
        catch (...)
        {
            // noop
        }
    }
}

UID::UID(const UID &n)
    : m_id(n.m_id)
{
}

UID &UID::operator=(const UID &other)
{
    if (this != &other)
    {
        m_id = other.m_id;
    }

    return *this;
}

bool UID::operator==(const UID &n) const
{
    return m_id == n.m_id;
}

bool UID::operator!=(const UID &n) const
{
    return m_id != n.m_id;
}

bool UID::operator>(const UID &n) const
{
    return m_id > n.m_id;
}

bool UID::operator<(const UID &n) const
{
    return m_id < n.m_id;
}

std::string UID::toString() const
{
    return to_string(m_id);
}
