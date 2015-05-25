compare fork and pthread in system call
---------------------------------------
- source code::

    # fork 
    printf("before fork\n");
    pid = fork();
    printf("after fork\n");

    # pthread
    printf("before pthread_create\n");
    pthread_create(&thread1, NULL, &thread_func, NULL);
    printf("before pthread_create\n");

- strace::

    # fork
    write(1, "before fork\n", 12)           = 12
    clone(child_stack=0, flags=CLONE_CHILD_CLEARTID|CLONE_CHILD_SETTID|SIGCHLD, child_tidptr=0x7f6059c8a9d0) = 12611
    write(1, "after fork\n", 11)            = 11

    # pthread_create 
    write(1, "before pthread_create\n", 22) = 22
    mmap(NULL, 8392704, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7ff9b37b9000
    brk(0)                                  = 0x9b0000
    brk(0x9d1000)                           = 0x9d1000
    mprotect(0x7ff9b37b9000, 4096, PROT_NONE) = 0
    clone(child_stack=0x7ff9b3fb8ff0, flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, parent_tidptr=0x7ff9b3fb99d0, tls=0x7ff9b3fb9700, child_tidptr=0x7ff9b3fb99d0) = 12302
    write(1, "before pthread_create\n", 22) = 22

``fork()`` and ``pthread_create()`` both use ``clone()`` system call with different flags.
``clone()`` copy the task and clone flags decide what resource parent and child will share.

- flags

  - ``CLONE_VM``: share address space.
  - ``CLONE_FILES``: share open files (file descriptors).
  - ``CLONE_SIGHAND``: share signal handlers.
  - ``CLONE_FS``: share filesystem information?
  - ``CLONE_SETTLS``: [not share] Create a new TLS (thread-local storage) for the child.
  - ``CLONE_SYSVSEM``: share System V SEM_UNDO semantics?
  - ``CLONE_PARENT_SETTID``, ``CLONE_CHILD_SETTID``: [not share] Set the TID in the parent/child?
  - ``CLONE_CHILD_CLEARTID``: [not share] Clear the TID in the child?

reference
---------
- `LKD 2nd - Linux Implementation of Thread <http://www.makelinux.net/books/lkd2/ch03lev1sec3>`_
- `LKD 2nd - Process Creation <http://www.makelinux.net/books/lkd2/ch03lev1sec2>`_

- p.s. LKD means Linux Kernel Development
