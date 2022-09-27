#include <fcntl.h>            /* Definition of O_* constants */
#include <sys/syscall.h>      /* Definition of SYS_* constants */
#include <unistd.h>
#include <stdio.h>

#define err(msg) perror(msg)
#define ok(msg) printf("%s: OK", msg)

void check_userfaultfd() {
    int uffd = syscall(__NR_userfaultfd, O_CLOEXEC | O_NONBLOCK);
    char *to_check = "userfaultfd";
    if (uffd == -1)
        err(to_check);
    else
        ok(to_check);
}

int main(int argc, char * argv[]) {
    check_userfaultfd();

    return 0;
}


