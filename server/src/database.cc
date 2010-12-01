#include "database.h"

Database::Database()
{
}

Database::~Database()
{
    sqlite3_close(db);
}

int Database::create_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   return 0; 
}


