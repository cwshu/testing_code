- mmap syscall
  
  - ``void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)``
  - return: start address of new mapping
  - memory (addr ~ addr+length) map to file (fd, offset ~ fd, offset+length)
    - addr=NULL means the start address of mapping memory is decided by OS
  - prot: memory protection of the mapping(not conflict with open mode of file)
    - r/w/x, NONE(not be accessed)
  - flags  
    - MAP_ANONYMOUS: not map any file, content initial to zero.
    - MAP_SHARED/MAP_PRIVATE
      - share: memory modification will be written back to file.
        - msync
      - private: private CoW mapping
    - MAP_FIXED: 強迫用 addr, length 去 map, 有 overlap 則蓋掉原本的 page, 如果無法使用 addr, length 則 failed
    - MAP_GROWSDOWN: 給 stack 用的 

    - MAP_HUGETLB

- ideas
  - 同檔案被 memory map 超過一次是否會 share?
    - 單一 executable 被執行多次是否只有一個實體?
    - 相同內容但不同名/不同路徑的 executable 能否只有一個實體?
