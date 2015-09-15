process in memory experiment
============================
在 C 程式裡印出各區段(segment)變數的指標值, 以及 program counter, 並跟 procfs 中看到的 process memory map 做比較, 驗證每個變數的確存在於對應的記憶體區段(segment)中.

程式碼請見 ``process_in_memory.c``, ``process_in_memory_lib.c``

running
-------
::

    make all               # build executable and shared library
    LD_LIBRARY_PATH=`pwd`  # use shared library in this directory.
    ./process_in_memory    # run experiment
    cat /proc/`pgrep process`/maps  # print procfs map

result
------

process output::

    > ./process_in_memory 
    [code]  0x000000000040081b
    [data]  0x0000000000600d2c
    [stack] 0x00007ffc8b2f5c40
    [stack] 0x00007ffc8b2f3c40
    [heap]  0x0000000001b0b010
    
    In share library libpim:
    [code]  0x00007faaee793878
    [data]  0x00007faaee993c88
    [stack] 0x00007ffc8b2f1c10
    [stack] 0x00007ffc8b2efc10
    [heap]  0x0000000001b0b420

procfs map(為了方便觀看, 程式 output 中有出現的區段加上 ``!`` 標注)::

    ! 00400000-00401000 r-xp 00000000 08:06 2561888                            /home/susu/testing_code/mmap/process_in_memory/process_in_memory
    ! 00600000-00601000 rw-p 00000000 08:06 2561888                            /home/susu/testing_code/mmap/process_in_memory/process_in_memory
    ! 01b0b000-01b2c000 rw-p 00000000 00:00 0                                  [heap]
    7faaee3ef000-7faaee58a000 r-xp 00000000 08:06 8783585                    /usr/lib/libc-2.22.so
    7faaee58a000-7faaee789000 ---p 0019b000 08:06 8783585                    /usr/lib/libc-2.22.so
    7faaee789000-7faaee78d000 r--p 0019a000 08:06 8783585                    /usr/lib/libc-2.22.so
    7faaee78d000-7faaee78f000 rw-p 0019e000 08:06 8783585                    /usr/lib/libc-2.22.so
    7faaee78f000-7faaee793000 rw-p 00000000 00:00 0 
    ! 7faaee793000-7faaee794000 r-xp 00000000 08:06 2561891                    /home/susu/testing_code/mmap/process_in_memory/libpim.so.1.0.0
    7faaee794000-7faaee993000 ---p 00001000 08:06 2561891                    /home/susu/testing_code/mmap/process_in_memory/libpim.so.1.0.0
    ! 7faaee993000-7faaee994000 rw-p 00000000 08:06 2561891                    /home/susu/testing_code/mmap/process_in_memory/libpim.so.1.0.0
    7faaee994000-7faaee9b6000 r-xp 00000000 08:06 8783474                    /usr/lib/ld-2.22.so
    7faaeeb77000-7faaeeb7a000 rw-p 00000000 00:00 0 
    7faaeebb2000-7faaeebb5000 rw-p 00000000 00:00 0 
    7faaeebb5000-7faaeebb6000 r--p 00021000 08:06 8783474                    /usr/lib/ld-2.22.so
    7faaeebb6000-7faaeebb7000 rw-p 00022000 08:06 8783474                    /usr/lib/ld-2.22.so
    7faaeebb7000-7faaeebb8000 rw-p 00000000 00:00 0 
    ! 7ffc8b2d8000-7ffc8b2f9000 rw-p 00000000 00:00 0                          [stack]
    7ffc8b37a000-7ffc8b37c000 r--p 00000000 00:00 0                          [vvar]
    7ffc8b37c000-7ffc8b37e000 r-xp 00000000 00:00 0                          [vdso]
    ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
