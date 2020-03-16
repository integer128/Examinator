#pragma once

namespace DBTypes
{
enum class DBResult {
    OK,
    FAIL
};

enum class DBTables {
    Contacts = 1,
    Theory
};

enum class DBState {
    OK,
    ERROR_NO_DRIVER,
    ERROR_WORKSPACE,
    ERROR_TABLES,
    ERROR_OPENING
};
}
