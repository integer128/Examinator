#pragma once

#include "dbtypes.h"

#include <QString>

#include <map>

namespace db
{
static const std::map<DBTypes::DBTables, QString> tableMapper
{
    { DBTypes::DBTables::Contacts, "Contacts" },
    { DBTypes::DBTables::Theory, "Theory" }
};

static const std::map<QString, QString> tablesMapping
{

};
}
