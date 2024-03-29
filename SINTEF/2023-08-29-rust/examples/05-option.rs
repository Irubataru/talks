fn add_one_to_opt(value: Option<u8>) -> Option<u8> {
    Some(value? + 1)
}

fn main() {
    let none = add_one_to_opt(None);
    let some = add_one_to_opt(Some(8));

    dbg!(none);
    dbg!(some);
}
