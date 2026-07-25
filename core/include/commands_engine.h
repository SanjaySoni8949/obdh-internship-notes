#ifndef COMMAND_ENGINE_H
#define COMMAND_ENGINE_H

void execute_command(int argc, char *argv[]);

void command_register(const char *name, const char *description,const char *usage
    ,void (*handler)(int argc, char *argv[]));
void command_unregister_all(void);
void command_list(void);
typedef struct
{
    const char *name;
    const char *description;
    const char *usage;
    void (*handler)(int argc, char *argv[]);
} cmd_t;

const cmd_t *command_find(const char *name);

int command_get_count(void);
#endif
