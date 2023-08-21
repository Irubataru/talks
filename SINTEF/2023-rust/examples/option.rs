
fn add_one_to_opt(value: Option<u8>) -> Option<u8> {
    Some(value? + 1)
}


fn main() {

    println!("{:?}", add_one_to_opt(None));
    println!("{:?}", add_one_to_opt(Some(8)));

}
