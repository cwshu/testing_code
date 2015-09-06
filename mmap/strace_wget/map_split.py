#!/usr/bin/env python3

def test():

    test_str="""00400000-00464000 r-xp 00000000 08:06 8783229                            /usr/bin/wget
00663000-00667000 rw-p 00063000 08:06 8783229                            /usr/bin/wget
00667000-0066e000 rw-p 00000000 00:00 0                                  [heap]
7ffff7b6b000-7ffff7ddb000 r-xp 00000000 08:06 8785854                    /usr/lib/libpcre.so.1.2.5
7ffff7ddb000-7ffff7dfd000 r-xp 00000000 08:06 8783474                    /usr/lib/ld-2.22.so
7ffff7fbd000-7ffff7fbe000 rw-p 00000000 00:00 0 
7ffff7fbe000-7ffff7ff8000 r--p 00000000 08:06 3935731                    /etc/ld.so.cache
7ffff7ff8000-7ffff7ffa000 r--p 00000000 00:00 0                          [vvar]
7ffff7ffa000-7ffff7ffc000 r-xp 00000000 00:00 0                          [vdso]
7ffff7ffc000-7ffff7ffe000 rw-p 00021000 08:06 8783474                    /usr/lib/ld-2.22.so
7ffff7ffe000-7ffff7fff000 rw-p 00000000 00:00 0 
7ffffffde000-7ffffffff000 rw-p 00000000 00:00 0                          [stack]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
"""

    test_str_list = test_str.splitlines()
    prev_end_addr = 0
    for test_str_line in test_str_list:
        start_addr = test_str_line[:test_str_line.find('-')]
        end_addr = test_str_line[test_str_line.find('-')+1:test_str_line.find(' ')]

        if prev_end_addr == 0:
            pass
        elif start_addr == prev_end_addr:
            pass
        else:
            print("")

        print(test_str_line)
        prev_end_addr = end_addr


import sys

map_string = sys.stdin.read()
prev_end_addr = 0
for map_string_line in map_string.splitlines():
    start_addr = map_string_line[:map_string_line.find('-')]
    end_addr = map_string_line[map_string_line.find('-')+1:map_string_line.find(' ')]

    if prev_end_addr == 0:
        pass
    elif start_addr == prev_end_addr:
        pass
    else:
        print("")

    print(map_string_line)
    prev_end_addr = end_addr

