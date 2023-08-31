fn main() {
    let mut items = vec![];
    let text = String::from("foo");

    let closure = || {
        items.push(text);
    };


    let mut items = vec![];

    let closure = |text: &str| {
        items.push(String::from(text));
    };

    let text = String::from("foo");

    let text = || {
        format!("Hello {}", text)
    };

}
