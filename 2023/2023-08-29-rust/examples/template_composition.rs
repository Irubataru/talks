use std::fmt::{Debug, Display};

fn print_normal_and_debug<T>(thing: T)
where
    T: Debug + Display
{
    println!("{}, {:?}", &thing, &thing);
}

fn main() {

    print_normal_and_debug("Hello");

}
