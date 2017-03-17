//
// Created by Tim Shull on 10/22/16.
//

//#include <unistd.h>
//int execl(   path, arg0, arg1..., argn, NULL );
//int execle(  path, arg0, arg1..., argn, NULL,
//             envp );
//int execlp(  file, arg0, arg1..., argn, NULL );
//int execlpe( file, arg0, arg1..., argn, NULL,
//             envp );
//int execv(   path, argv );
//int execve(  path, argv, envp );
//int execvp(  file, argv );
//int execvpe( file, argv, envp );
//
//const char *path;     /* file name incl. path */
//const char *file;     /* file name            */
//const char *arg0,...,
//*argn;     /* arguments            */
//char *const argv[];   /* array of arguments   */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void) {
    char *my_args[5];
    pid_t pid;

    my_args[0] = "child.exe";
    my_args[1] = "arg1";
    my_args[2] = "arg2";
    my_args[3] = NULL;

    puts("fork()ing");

    switch ((pid = fork())) {
        case -1:
            /* Fork() has failed */
            perror("fork");
            break;
        case 0:
            /* This is processed by the child */
            execv("child.exe", my_args);
            puts("Uh oh! If this prints, execv() must have failed");
            exit(EXIT_FAILURE);
            break;
        default:
            /* This is processed by the parent */
            puts("This is a message from the parent");
            break;
    }

    puts("End of parent program");
    return 0;
}

/*
 * Program output:
 fork()ing
 This is a message from the parent
 End of parent program
 I am the child
 Arg 1 arg1
 Arg 2 arg2
 *
 */