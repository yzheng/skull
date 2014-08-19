#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "api/sk_utils.h"
#include "api/sk.h"

static
void _print_usage()
{
    fprintf(stderr, "usage: skull -c config\n");
}

static
void _read_commands(int argc, char** argv, skull_cmd_args_t* cmd_args)
{
    if (argc == 1) {
        _print_usage();
        exit(1);
    }

    char opt;
    while ((opt = getopt(argc, argv, "c:")) != -1) {
        switch (opt) {
        case 'c':
            cmd_args->config_location = optarg;
            sk_print("config location: %s\n", cmd_args->config_location);
            break;
        default:
            fprintf(stderr, "unknow parameter '%s'\n", optarg);
            _print_usage();
            exit(2);
        }
    }
}

static
void _check_args(skull_cmd_args_t* cmd_args)
{
    if (NULL == cmd_args->config_location) {
        fprintf(stderr, "empty configuraton\n");
        _print_usage();
        exit(2);
    }
}

int main(int argc, char** argv)
{
    skull_core_t core;
    memset(&core, 0, sizeof(core));
    _read_commands(argc, argv, &core.cmd_args);
    _check_args(&core.cmd_args);

    skull_init(&core);
    skull_start(&core);
    return 0;
}
