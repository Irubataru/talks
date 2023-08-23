use chrono::{DateTime, Utc};

struct ChatUser {
    username: String,
}

struct ChatMessage {
    user: ChatUser,
    timestamp: DateTime<Utc>,
    message: String,
}

trait FormatMessage {
    fn to_message(&self) -> String;
}

impl FormatMessage for ChatMessage {
    fn to_message(&self) -> String {
        format!(
            "{}  @{} | {}",
            self.timestamp.time(),
            self.user.username,
            self.message
        )
    }
}

fn main() {
    let user = ChatUser {
        username: String::from("irubataru"),
    };
    let message = ChatMessage {
        user,
        timestamp: Utc::now(),
        message: String::from("Hiya! How are you all doing? :3"),
    };
    println!("{}", message.to_message());
}
