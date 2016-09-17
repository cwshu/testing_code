This is a little experiment of the behavior told in `Zero Copy I: User-Mode Perspective <http://www.linuxjournal.com/article/6345>`_

::

    You will fall into one of them when you memory map a file and then call write while another process truncates the same file.
    Your write system call will be interrupted by the bus error signal SIGBUS, because you performed a bad memory access. 

``man 2 mmap`` also tells that::

    ERRORS

      SIGBUS:
        Attempted access to a portion of the buffer that does not correspond to the file 
        (for example, beyond the end of the file, including the case where another process has truncated the file).

Currently, this experiment is failed, I only get ``write()`` system call return -1 and have ``EFAULT`` errno.

Testing
-------
- build::

    make all

- test::

    make init
    ./mmap_write
