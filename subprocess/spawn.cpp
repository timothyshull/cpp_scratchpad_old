//
// Created by Tim Shull on 10/22/16.
//

//#include <process.h>
//int spawnl(   mode, path, arg0, arg1..., argn,
//              NULL );
//int spawnle(  mode, path, arg0, arg1..., argn,
//              NULL, envp);
//int spawnlp(  mode, file, arg0, arg1..., argn,
//              NULL );
//int spawnlpe( mode, file, arg0, arg1..., argn,
//              NULL, envp);
//int spawnv(   mode, path, argv );
//int spawnve(  mode, path, argv, envp );
//int spawnvp(  mode, file, argv );
//int spawnvpe( mode, file, argv, envp );
//
//int         mode;      /* mode for parent      */
//const char *path;      /* file name incl. path */
//const char *file;      /* file name            */
//const char *arg0,...,
//*argn;      /* arguments            */
//char *const argv[];    /* array of arguments   */
//char *const envp[];    /* environment strings  */

//
//#include <stdio.h>
//#include <process.h>
//
//int main(void) {
//
//    puts("Spawning child with spawnl");
//
//    spawnl(P_WAIT, "child.exe",
//           "child.exe", "Using spawnl", "Arg1", "Arg2", NULL);
//
//    return 0;
//}
//
///*
// * Program output:
// Spawning child with spawnl
// I am the child
// Arg 1 Using
// Arg 2 spawnl
// Arg 3 Arg1
// Arg 4 Arg2
// *
// */

#include <stdio.h>
#include <process.h>

int main(void) {
    char *my_args[4];

    my_args[0] = "child.exe";
    my_args[1] = "arg1";
    my_args[2] = "arg2";
    my_args[3] = NULL;

    puts("Spawning child with spawnv");

    spawnv(P_WAIT, "child.exe", my_args);

    return 0;
}

/*
 * Program output:
 Spawning child with spawnv
 I am the child
 Arg 1 arg1
 Arg 2 arg2
 *
 */