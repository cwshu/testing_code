This is in Rust 1.0

- dangling pointer

  - problem: pointer or reference to mutable object (ex. element of vector in c++, because dynamic capacity.)

    - solution: mutable and immutable array, value clone.

- thread data race

- Ownership type-system

  - do some validation of data racing at compilation time.
  - Rust's ownership model can track which pointers own which memory locations.

- naming

  - 看起來 function 跟 variable 的 naming 不共用.
