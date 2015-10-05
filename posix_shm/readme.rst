http://man7.org/training/download/posix_shm_slides.pdf

command::

    ./pshm_create_simple <shm_name> <size>
    ./pshm_write <shm_name> <string>
    ./pshm_read <shm_name>

shared memory at ``/dev/shm/<shm_name>``

example use::
    
    ./pshm_create_simple hello_shm 128
    ./pshm_write hello_shm hello_world!
    ./pshm_read

