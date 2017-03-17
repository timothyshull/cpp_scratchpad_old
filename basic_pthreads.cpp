#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#include <string>
#include <cstdlib>
#include <cstdio>

void handle_error_en(int en, std::string&& msg)
{
    errno = en;
    std::perror(msg.c_str());
    exit(EXIT_FAILURE);
}

void handle_error(std::string&& msg)
{
    std::perror(msg.c_str());
    exit(EXIT_FAILURE);
}

struct thread_info {    /* Used as argument to thread_start() */
    pthread_t thread_id;        /* ID returned by pthread_create() */
    int thread_num;       /* Application-defined thread # */
    char* argv_string;      /* From command-line argument */
};

/* Thread start function: display address near top of our stack,
   and return upper-cased copy of argv_string */

static void* thread_start(void* arg)
{
    struct thread_info* tinfo = static_cast<thread_info*>(arg);
    char* uargv;
    char* p;

    printf("Thread %d: top of stack near %p; argv_string=%s\n", tinfo->thread_num, &p, tinfo->argv_string);

    uargv = strdup(tinfo->argv_string);
    if (uargv == nullptr) { handle_error("strdup"); }

    for (p = uargv; *p != '\0'; ++p) { *p = static_cast<char>(std::toupper(*p)); }

    return uargv;
}

int main(int argc, char* argv[])
{
    int stack_size = -1;
    int opt;
    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
            case 's':
                stack_size = static_cast<int>(std::strtoul(optarg, nullptr, 0));
                break;
            default:
                fprintf(stderr, "Usage: %s [-s stack-size] arg...\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    auto num_threads = argc - optind;

    /* Initialize thread creation attributes */

    pthread_attr_t attr;
    auto s = pthread_attr_init(&attr);
    if (s != 0) { handle_error_en(s, "pthread_attr_init"); }

    if (stack_size > 0) {
        s = pthread_attr_setstacksize(&attr, static_cast<std::size_t>(stack_size));
        if (s != 0) { handle_error_en(s, "pthread_attr_setstacksize"); }
    }

    /* Allocate memory for pthread_create() arguments */

    auto tinfo = static_cast<thread_info*>(calloc(static_cast<std::size_t>(num_threads), sizeof(struct thread_info)));
    if (tinfo == nullptr) { handle_error("calloc"); }

    /* Create one thread for each command-line argument */

    for (auto tnum = 0; tnum < num_threads; ++tnum) {
        tinfo[tnum].thread_num = tnum + 1;
        tinfo[tnum].argv_string = argv[optind + tnum];

        /* The pthread_create() call stores the thread ID into
           corresponding element of tinfo[] */

        s = pthread_create(&tinfo[tnum].thread_id, &attr, &thread_start, &tinfo[tnum]);
        if (s != 0) { handle_error_en(s, "pthread_create"); }
    }

    /* Destroy the thread attributes object, since it is no
       longer needed */

    s = pthread_attr_destroy(&attr);
    if (s != 0) { handle_error_en(s, "pthread_attr_destroy"); }

    /* Now join with each thread, and display its returned value */

    for (auto tnum = 0; tnum < num_threads; tnum++) {
        void* res;
        s = pthread_join(tinfo[tnum].thread_id, &res);
        if (s != 0) { handle_error_en(s, "pthread_join"); }
        printf("Joined with thread %d; returned value was %s\n", tinfo[tnum].thread_num, (char*) res);
        free(res);      /* Free memory allocated by thread */
    }

    free(tinfo);
    return 0;
}

//int main()
//{
//    // int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
//    pthread_create(&tid, NULL, start_fn, arg);
//    pthread_exit(status);
//}