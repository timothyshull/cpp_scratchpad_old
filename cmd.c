#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

#define BUFFERLEN 128

//struct kinfo_proc {
//    struct	extern_proc kp_proc;			/* proc structure */
//    struct	eproc {
//        struct	proc *e_paddr;		/* address of proc */
//        struct	session *e_sess;	/* session pointer */
//        struct	_pcred e_pcred;		/* process credentials */
//        struct	_ucred e_ucred;		/* current credentials */
//        struct	 vmspace e_vm;		/* address space */
//        pid_t	e_ppid;			/* parent process id */
//        pid_t	e_pgid;			/* process group id */
//        short	e_jobc;			/* job control counter */
//        dev_t	e_tdev;			/* controlling tty dev */
//        pid_t	e_tpgid;		/* tty process group id */
//        struct	session *e_tsess;	/* tty session pointer */
//#define	WMESGLEN	7
//        char	e_wmesg[WMESGLEN+1];	/* wchan message */
//        segsz_t e_xsize;		/* text size */
//        short	e_xrssize;		/* text rss */
//        short	e_xccount;		/* text references */
//        short	e_xswrss;
//        int32_t	e_flag;
//#define	EPROC_CTTY	0x01	/* controlling tty vnode active */
//#define	EPROC_SLEADER	0x02	/* session leader */
//#define	COMAPT_MAXLOGNAME	12
//        char	e_login[COMAPT_MAXLOGNAME];	/* short setlogin() name */
//        int32_t	e_spare[4];
//    } kp_eproc;
//};


///* Exported fields for kern sysctls */
//struct extern_proc {
//    union {
//        struct {
//            struct	proc *__p_forw;	/* Doubly-linked run/sleep queue. */
//            struct	proc *__p_back;
//        } p_st1;
//        struct timeval __p_starttime; 	/* process start time */
//    } p_un;
//#define p_forw p_un.p_st1.__p_forw
//#define p_back p_un.p_st1.__p_back
//#define p_starttime p_un.__p_starttime
//    struct	vmspace *p_vmspace;	/* Address space. */
//    struct	sigacts *p_sigacts;	/* Signal actions, state (PROC ONLY). */
//    int	p_flag;			/* P_* flags. */
//    char	p_stat;			/* S* process status. */
//    pid_t	p_pid;			/* Process identifier. */
//    pid_t	p_oppid;	 /* Save parent pid during ptrace. XXX */
//    int	p_dupfd;	 /* Sideways return value from fdopen. XXX */
//    /* Mach related  */
//    caddr_t user_stack;	/* where user stack was allocated */
//    void	*exit_thread;	/* XXX Which thread is exiting? */
//    int		p_debugger;		/* allow to debug */
//    boolean_t	sigwait;	/* indication to suspend */
//    /* scheduling */
//    u_int	p_estcpu;	 /* Time averaged value of p_cpticks. */
//    int	p_cpticks;	 /* Ticks of cpu time. */
//    fixpt_t	p_pctcpu;	 /* %cpu for this process during p_swtime */
//    void	*p_wchan;	 /* Sleep address. */
//    char	*p_wmesg;	 /* Reason for sleep. */
//    u_int	p_swtime;	 /* Time swapped in or out. */
//    u_int	p_slptime;	 /* Time since last blocked. */
//    struct	itimerval p_realtimer;	/* Alarm timer. */
//    struct	timeval p_rtime;	/* Real time. */
//    u_quad_t p_uticks;		/* Statclock hits in user mode. */
//    u_quad_t p_sticks;		/* Statclock hits in system mode. */
//    u_quad_t p_iticks;		/* Statclock hits processing intr. */
//    int	p_traceflag;		/* Kernel trace points. */
//    struct	vnode *p_tracep;	/* Trace to vnode. */
//    int	p_siglist;		/* DEPRECATED. */
//    struct	vnode *p_textvp;	/* Vnode of executable. */
//    int	p_holdcnt;		/* If non-zero, don't swap. */
//    sigset_t p_sigmask;	/* DEPRECATED. */
//    sigset_t p_sigignore;	/* Signals being ignored. */
//    sigset_t p_sigcatch;	/* Signals being caught by user. */
//    u_char	p_priority;	/* Process priority. */
//    u_char	p_usrpri;	/* User-priority based on p_cpu and p_nice. */
//    char	p_nice;		/* Process "nice" value. */
//    char	p_comm[MAXCOMLEN+1];
//    struct 	pgrp *p_pgrp;	/* Pointer to process group. */
//    struct	user *p_addr;	/* Kernel virtual addr of u-area (PROC ONLY). */
//    u_short	p_xstat;	/* Exit status for wait; also stop signal. */
//    u_short	p_acflag;	/* Accounting flags. */
//    struct	rusage *p_ru;	/* Exit information. XXX */
//};



void printkproc(struct kinfo_proc *kp) {
    printf("%d\n", kp->kp_proc.p_pid);
    printf("%d\n", kp->kp_proc.p_flag);
    printf("%d\n", kp->kp_proc.p_stat);
    printf("%d\n\n", kp->kp_proc.p_cpticks);
//    printf("%c\n", *(kp->kp_proc.user_stack));
}

int main() {
//    char buffer[BUFFERLEN];
//    size_t bufferlen = BUFFERLEN;
//    sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);
//    printf("%s\n", buffer);


    int i, mib[4];
    size_t len;
    struct kinfo_proc kp;

    /* Fill out the first three components of the mib */
    len = 4;
    sysctlnametomib("kern.proc.pid", mib, &len);

    /* Fetch and print entries for pid's < 100 */
    for (i = 0; i < 100; i++) {
        mib[3] = i;
        len = sizeof(kp);
        if (sysctl(mib, 4, &kp, &len, NULL, 0) == -1)
            perror("sysctl");
        else if (len > 0)
            printkproc(&kp);
    }
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/syscall.h>
//#include <sys/sysctl.h>

//int main() {
//    char cmd[32];
//    brk((void *) 0x8051000);
//    sprintf(cmd, "cat /proc/self/maps");
//    system(cmd);
//    return 0;
//}