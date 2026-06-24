# Shell Architecture

User Input
    ↓
Parser
    ↓
Command Engine
    ↓
Command Table
    ↓
Command Function

Example:

ping → cmd_ping()
help → cmd_help()
status → cmd_status()

typedef struct
{
    char *name;
    void (*handler)(void);
} command_t;

void cmd_ping(void)
{
    printf("PONG\n");
}

void cmd_help(void)
{
    printf("Available commands:\n");
    printf("ping\n");
    printf("help\n");
}




command_t commands[] =
{
    {"ping", cmd_ping},
    {"help", cmd_help}
};




handler
    ↓
is a pointer
    ↓
to a function
    ↓
that returns void
    ↓
and takes no arguments
