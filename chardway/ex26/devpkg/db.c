#include <unistd.h>
#include <apr_errno.h>
#include <apr_file_io.h>

#include "db.h"
#include "bstrlib.h"
#include "dbg.h"

static FILE *DB_open(const char *path, const char *mode)
{
    return fopen(path, mode);  //file, mode
}

static void DB_close(FILE *db)  //takes in file pointer
{
    fclose(db);
}

static bstring DB_load()
{
    FILE *db = NULL;
    bstring data = NULL;

    db = DB_open(DB_FILE, "r");  //read data from DB_FILE
    check(db, "Failed to read from db file: %s", DB_FILE);

    data = bread((bNread)fread, db); //bread takes two arguments: pointer to function and stream pointer
    check(data, "Failed to read from db file: %s", DB_FILE);

    DB_close(db);  //closes the db pointer
    return data;

error:
    if(db) DB_close(db);
    if(data) bdestroy(data);
    return NULL;
}

int DB_update(const char *url)
{
    if(DB_find(url))
    {
        log_info("Already recorded as installed: %s", url);
    }

    FILE *db = DB_open(DB_FILE, "a+");  //opens file for reading writing, appends if file exists
    check(db, "Failed to open DB file: %s", DB_file);

    bstring line = bfromcstr(url);
    bconchar(line, '\n');  //adds \n to the end of 'line'
    int rc = fwrite(line->data, blength(line), 1, db);
    check(rc == 1, "Failed to append to the db.");

    return 0;

error:
    if(db) DB_close(db);
    return -1;
}

int DB_find(const char *url)
{
    bstring data = NULL;
    bstring line = bfromcstr(url);  //convert url to other type
    int res = -1;

    data = DB_load();
    check(data, "Failed to load: %s", DB_FILE);

    if(binstr(data, 0, line) == BSTR_ERR)  //search for line in data at position 0 and increasing; BSTR_ERR is equivalent to NULL
    {
        res = 0;
    }
    else
    {
        res = 1;
    }

error:
    if(data) bdestroy(data);
    if(line) bdestroy(line);

    return res;
}

int DB_init()
{
    apr_pool_t *p = NULL;  //allocates memory
    apr_pool_initialize();  //sets up internal structures to use pools
    apr_pool_create(&p, NULL);  //creates new pool

    if(access(DB_DIR, W_OK | X_OK) == -1)  // checks if the file 'DB_DIR' can be accessed for writing and execute/search
    {
        apr_status_t rc = apr_dir_make_recursive(DB_DIR,
                APR_UREAD | APR_UWRITE | APR_UEXECUTE |
                APR_GREAD | APR_GWRITE | APR_GEXECUTE, p);
        check(rc == APR_SUCCESS, "Failed to make database dir: %s", DB_DIR);
    }

    if(access(DB_FILE, W_OK) == -1)
    {
        FILE *db = DB_open(DB_FILE, "w");
        check(db, "Cannot open database: %s", DB_FILE);
        DB_close(db);
    }

    apr_pool_destroy(p);
    return 0;

error:
    apr_pool_destroy(p);
    return -1;
}

int DB_list()
{
    bstring data = DB_load();
    check(data, "Failed to read load: %s", DB_FILE);

    printf("%s", bdata(data));  //prints data
    bdestroy(data);
    return 0;

error:
    return -1;
}
