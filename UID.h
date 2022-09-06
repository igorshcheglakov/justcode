#ifndef UID_H_
#define UID_H_

#include <boost/uuid/uuid.hpp>

#include <string>

class UID final
{
public:
    UID();
    UID(const std::string &str);
    UID(const UID &n);
    ~UID() = default;

    UID &operator=(const UID &other);
    bool operator==(const UID &n) const;
    bool operator!=(const UID &n) const;
    bool operator >(const UID &n) const;
    bool operator <(const UID &n) const;

    std::string toString() const;
public:
    static UID NONE;

private:
    boost::uuids::uuid m_id;
};

#endif // UID_H_

