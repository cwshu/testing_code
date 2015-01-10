use std::thread::Thread;
use std::sync::{Arc,Mutex};

/* simple example
fn main() {
    for _ in range(0u64, 10u64) {
        /*
         * Thread::spawn() get one argument: closure ({} of statements)
         * move keyword + || + closure, means moving closure.
         */
        Thread::spawn(move || {
            println!("Hello, world!");
        });
    }
}
*/

/*
fn main() {
    let mut numbers = vec![1i, 2i, 3i];

    for i in range(0u, 3u) {
        Thread::spawn(move || {
            for j in range(0, 3) { numbers[j] += 1 }
        });
    }
}
*/

fn main() {
    let numbers = Arc::new(Mutex::new(vec![1i64, 2i64, 3i64]));

    for i in range(0u64, 3u64) {
        let number = numbers.clone();
        Thread::spawn(move || {
            let mut array = number.lock().unwrap();

            (*array)[i] += 1;

            println!("numbers[{}] is {}", i, (*array)[i]);
        });
    }
}
