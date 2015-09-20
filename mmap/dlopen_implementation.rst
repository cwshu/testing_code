libdl 實作，好像有些 libc 會給 stub function，真正實作去拉 dynamic linker 的實作

- bsd libc 是去拉 _rtld_xxx, 看註解是 dynamic linker

  - https://svnweb.freebsd.org/base/head/lib/libc/gen/dlfcn.c?view=markup&pathrev=283153

- bionic 的 libdl 也是做空的 definition

  - https://github.com/android/platform_bionic/blob/android-5.1.1_r13/libdl/libdl.c
  - 真正的實作藏在 linker/dlfcn.c

    - https://github.com/android/platform_bionic/blob/android-5.1.1_r13/linker/dlfcn.cpp#L82

  - dlopen -> dlopen_ext -> do_dlopen -> find_library -> find_libraries (step 0 ~ 2) 會一路跑到 dynamic linker 的實作

    - https://github.com/android/platform_bionic/blob/android-5.1.1_r13/linker/linker.cpp#L896

- glibc 有點複雜沒 trace 下去

  - http://fossies.org/dox/glibc-2.22/dlopen_8c_source.html

(p.s. 看 bionic 的說明，libdl 跟 dynamic linker 都在它的實作範圍: https://github.com/android/platform_bioni
