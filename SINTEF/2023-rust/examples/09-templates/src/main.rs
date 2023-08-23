use structs::{ChatMessage, ChatUser, UserJoinMessage};
use templates::{display_chat, print_slice};

use crate::templates::smallest;

mod structs;
mod templates;
mod traits;

fn pass_user<'lifetime1, 'lifetime2>(
    user1: &'lifetime1 ChatUser,
    user2: &'lifetime2 ChatUser,
) -> ChatMessage<'lifetime1> {
    println!("{} is not interesting", user2.username);
    ChatMessage::new(user1, "Hello")
}

fn say_hello_to_shortest_user<'lifetime>(
    user1: &'lifetime ChatUser,
    user2: &'lifetime ChatUser,
) -> ChatMessage<'lifetime> {

    if user1.username < user2.username {
        return ChatMessage::new(user1, format!("Hello {}! :3", user2.username).as_str())
    } 

    ChatMessage::new(user2, format!("Hello {}! <3", user1.username).as_str())
}

fn template_example_chat() {
    let mut irubataru = ChatUser::new("irubataru");
    let mut lucinellia = ChatUser::new("lucinellia");

    display_chat(UserJoinMessage::new(&irubataru));
    display_chat(ChatMessage::new(&irubataru, "Hiya! How is it going? :3"));
    display_chat(UserJoinMessage::new(&lucinellia));
    display_chat(ChatMessage::new(
        &lucinellia,
        "Hi! It's not too bad, how are you? :)",
    ));
}

fn template_example_vec() {
    let items = vec!["Hello", "world", "foo", "bar", "baz"];
    print_slice(&items);
    println!("");
}

fn template_example_iter() {
    let items = vec!["Hello", "world", "foo", "bar", "baz"];
    let smallest = smallest(items.iter());
    println!("{:?}", smallest);
}

fn lifetime_parameter_example() {
    let mut irubataru = ChatUser::new("irubataru");
    let mut lucinellia = ChatUser::new("lucinellia");

    let message = pass_user(&irubataru, &lucinellia);

    // irubataru.change_username("Aleksandra"); // Compile error, mutate after borrow
    lucinellia.change_username("Caroline"); // Ok, borrow ended at function end

    display_chat(message);
}

fn main() {
    template_example_chat();
    template_example_vec();
    template_example_iter();
    lifetime_parameter_example();

    display_chat("Hello");
    display_chat(String::from("Hello"));
    display_chat(42 as u32);
}
