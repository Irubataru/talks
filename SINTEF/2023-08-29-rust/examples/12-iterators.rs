fn main() {
    let items = vec!["Hello", "world", "foo", "bar", "baz"];
    let value = items
        .iter()
        .filter(|&s| s.len() == 3)
        .map(|&s| s.to_uppercase())
        .reduce(|acc, s| format!("{} - {}", acc, s));

    dbg!(value);
}
