#pragma once

#include <QString>

namespace utility
{
template <class T>
QString to_str(const T &val)
{
    using std::to_string;
    return QString::fromStdString(to_string(val));
}

inline QString to_str(const char *p)
{
    return p;
}

inline const QString& to_str(const QString &s)
{
    return s;
}
}
