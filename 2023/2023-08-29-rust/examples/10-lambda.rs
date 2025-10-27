fn main() {
    let passthrough = |x| x;
    let text = passthrough(String::from("Hello world"));
    let number = passthrough(42); // Compile error, only one type can be inferred
}
