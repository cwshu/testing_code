fn main() {
    // let v = vec![];
    let mut v = vec![];

    v.push("Hello");

    // let x = &v[0];
    let x = v[0].clone();

    v.push("world");

    println!("{}", x);
}
