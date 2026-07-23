                    +--------------------+
                    |       main.c       |
                    +--------------------+
                               |
                               v
                    Character Processor
                               |
                               v
                    +--------------------+
                    |    tokenizer.c     |
                    +--------------------+
                               |
                               v
                     argc / argv (tokens)
                               |
                               v
                    +--------------------+
                    | command_engine.c   |
                    +--------------------+
                               |
                +--------------+--------------+
                |              |              |
                v              v              v
           command_ping   command_help   command_status
                              ...
                    (implemented in commands.c)
