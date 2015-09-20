Memory Map
==========

4 types of memory map
---------------------
- MAP_SHARED

  - traditional memory map: when writing to memory, the modification will be written to the file, and be synchronized to memory mapping of same file by other processes.

- MAP_PRIVATE

  - private CoW memory map: when writing to memory, copying new memory page for dirty region

    - modification won't be written to the file, and won't be synchronized to memory mapping of same file other processes'.
    - used by loading shared library 

- MAP_ANONYMOUS

  - just allocate a memory page filled with zero
  - used by BSS segment and mallocing large memory ()
  - malloc(brk + mmap)

    - http://reborn2266.blogspot.tw/2011/11/linux-user-space.html

- MAP_GROWSDOWN

  - used by stack.
  - http://unix.stackexchange.com/questions/63742/what-is-automatic-stack-expansion/79256#79256

Misc
----

- mmap syscall
  
  - ``void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)``
  - return: start address of new mapping
  - memory (addr ~ addr+length) map to file (fd, offset ~ fd, offset+length)
    - addr=NULL means the start address of mapping memory is decided by OS
  - prot: memory protection of the mapping(not conflict with open mode of file)
    - r/w/x, NONE(not be accessed)
  - flags  
    - MAP_FIXED: 強迫用 addr, length 去 map, 有 overlap 則蓋掉原本的 page, 如果無法使用 addr, length 則 failed
    - MAP_HUGETLB

- ideas
  - 同檔案被 memory map 超過一次是否會 share?
    - 單一 executable 被執行多次是否只有一個實體?
    - 相同內容但不同名/不同路徑的 executable 能否只有一個實體?
