#pragma once

#include <dbtypes.h>

static const std::map<DBTables, QString> TableMapper {
    { DBTables::users, "users" },
    { DBTables::theory, "theory" }
};

static const std::map<QString, QString> TableMapping{
    { "users", "number, login, password, role, last_exam, fio" },
    { "theory", "text_id, name, data" }
};
