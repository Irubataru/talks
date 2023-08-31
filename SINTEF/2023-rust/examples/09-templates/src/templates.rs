use std::fmt::Display;

use crate::traits::FormatMessage;

pub fn display_chat<T>(message: T)
where
    T: FormatMessage,
{
    let message = message.to_message();
    println!("({}B) {}", message.len(), message)
}

fn add_message_to_queue<M>(queue: &mut Vec<String>, message: &M)
where
    M: FormatMessage,
{
    queue.push(message.to_message())
}

pub fn print_slice<T>(items: &[T])
where
    T: Display,
{
    print!("[");

    let mut is_first = true;
    for item in items {
        if !is_first {
            print!(", ");
        } else {
            is_first = false;
        }

        print!("{}", item);
    }

    print!("]");
}

pub fn smallest<'a, I, T>(mut iter: I) -> Option<&'a T>
where
    I: Iterator<Item = &'a T>,
    T: PartialOrd,
{
    let mut result: Option<&'a T> = None;

    while let Some(item) = iter.next() {
        result = match result {
            Some(value) => {
                if item < value {
                    Some(item)
                } else {
                    Some(value)
                }
            }
            None => Some(item),
        };
    }

    result
}

fn find_min<'a, I>(vals: I) -> Option<&'a u32>
where
    I: Iterator<Item = &'a u32>,
{
    vals.min()
}
