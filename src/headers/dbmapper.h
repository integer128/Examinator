#pragma once

#include "dbtypes.h"

#include <QString>

#include <map>

namespace database
{
static const std::map<DBTables, QString> tableMapper
{
    { DBTables::Contacts, "Contacts" },
    { DBTables::Theory, "Theory" }
};

static const std::map<QString, QString> tablesMapping
{

};
}
