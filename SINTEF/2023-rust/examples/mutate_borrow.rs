fn main() {
    let mut a = String::from("Hello");
    let b = &a;
    a.push_str(" Optimisation!");
    println!("{}", b);
}
