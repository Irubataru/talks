fn main() {
    let mut a = String::from("Hello");
    let b = &mut a;
    a.push_str(" Optimisation!");
    println!("{}", b);
}
