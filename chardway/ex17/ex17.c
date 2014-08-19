#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database
{
    struct Address rows[MAX_ROWS];
};

struct Connection
{
    FILE *file;
    struct Database *db;
};

void die(const char *message)
{
    if(errno)
    {
        perror(message);
    }
    else
    {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);  //print stuff
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);  //takes 1 element from conn->file and puts it in conn->db
    if(rc != 1)
    {
        die("Failed to load database.");
    }
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));  //initializes a conn struct
    if(!conn)  //if(conn == NULL)
    {
        die("Memory error");
    }

    conn->db = malloc(sizeof(struct Database));  //Connection structure also contains a db struct, initialize this one
    if(!conn->db)  //if(conn->db == NULL)
    {
        die("Memory error");
    }

    if(mode == 'c')  //user will do this in the beginning
    {
        conn->file = fopen(filename, "w");  //create new file
    }
    else
    {
        conn->file = fopen(filename, "r+");  //update name/replace name

        if(conn->file)
        {
            Database_load(conn);  //see Database_load function
        }
    }

    if(!conn->file)
    {
        die("Failed to open the file");
    }

    return conn;
}

void Database_close(struct Connection *conn)
{
    if(conn)
    {
        if(conn->file)
        {
            fclose(conn->file);
        }
        if(conn->db)
        {
            free(conn->db);
        }

        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);  //sets pointer to beginning of file

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);  //takes one element from conn->db and puts it in conn->file
    if(rc != 1)
    {
        die("Failed to write database");
    }

    rc = fflush(conn->file);  //don't know...
    if(rc == -1)
    {
        die("Cannot flush database");
    }
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++)
    {
        struct Address addr = {.id = 1, .set = 0};
        conn->db->rows[i] = addr;  //initializes every row in db
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set)
    {
        die("Already set, delete it first");
    }

    addr->set = 1;  //address is set
    char *res = strncpy(addr->name, name, MAX_DATA);  //copies name to addr->name
    if(!res)
    {
        die("Name copy failed");
    }

    res = strncpy(addr->email, email, MAX_DATA);  //copies email to addr->email
    if(!res)
    {
        die("Email copy failed");
    }
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];  //obtain address of row, each row is a address structure

    if(addr->set)  //addr->set = 1
    {
        Address_print(addr);  //print info
    }
    else
    {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};  //set in addr to 0
    conn->db->rows[id] = addr;  //row where address is
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++)
    {
        struct Address *cur = &db->rows[i];

        if(cur->set)
        {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        die("USAGE: ex17 <dbfile> <action [action params]>");
    }

    char *filename = argv[1];  //assign second argument to filename
    char action  = argv[2][0];  //assign third arg to action
    struct Connection *conn = Database_open(filename, action); //creates new struct called conn
    int id = 0;

    if(argc > 3)
    {
        id = atoi(argv[3]);  //string is converted to integer and assigned to id
    }

    if(id >= MAX_ROWS) //cannot be more than 100
    {
        die("There's not that many records");
    }

    switch(action)
    {
        case 'c':
            Database_create(conn);  //initializes db, which contains a row with addresses
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4)
            {
                die("Need an id to get");
            }

            Database_get(conn, id);  //prints address info of id
            break;

        case 's':
            if(argc != 6)
            {
                die("Need id, name, email to set");
            }

            Database_set(conn, id, argv[4], argv[5]);  //set id, name, email
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4)
            {
                die("Need id to delete");
            }

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;

        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");

    }

    Database_close(conn);

    return 0;
}
