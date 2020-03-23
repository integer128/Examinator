#pragma once

#include "dbtypes.h"

#include <QString>

#include <map>

namespace database
{
static const std::map<DBTables, QString> tableMapper
{
    { DBTables::Contacts, "Contacts" },
    { DBTables::Theory, "Theory" },
    { DBTables::Questions, "Questions" },
    { DBTables::Answers, "Answers" },
    { DBTables::Contacts_Answers, "Contacts_Answers" }
};

static const std::map<QString, QString> tablesMapping
{

};
}
