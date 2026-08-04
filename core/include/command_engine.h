#ifndef COMMAND_ENGINE_H
#define COMMAND_ENGINE_H

/**
 * @brief Execute a command.
 *
 * Searches the command registry and executes the corresponding callback.
 *
 * @param argc Number of command arguments.
 * @param argv Command argument array.
 */

void execute_command(int argc, char *argv[]);

/**
 * @brief Register a new shell command.
 *
 * Adds a command to the command registry. The command can later be
 * executed by typing its name in the shell.
 *
 * @param name Command name.
 * @param description Short description displayed by the help command.
 * @param usage Usage string displayed by help <command>.
 * @param handler Callback function executed when the command is invoked.
 */
void command_register(const char *name,
                      const char *description,
                      const char *usage,
                      void (*handler)(int argc, char *argv[]));
typedef struct
{
    const char *name;
    const char *description;
    const char *usage;
    void (*handler)(int argc, char *argv[]);
} cmd_t;


/**
 * @brief Find a command by its name.
 *
 * @param name Command name.
 * @return Pointer to the command entry if found, otherwise NULL.
 */
const cmd_t *command_find(const char *name);


/**
 * @brief Get the number of registered commands.
 *
 * @return Number of registered commands.
 */
int command_get_count(void);
#endif
