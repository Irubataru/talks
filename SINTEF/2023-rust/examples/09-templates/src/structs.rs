use chrono::{DateTime, Utc};

use crate::traits::FormatMessage;

pub struct ChatUser {
    pub username: String,
}

pub struct ChatMessage<'a> {
    user: &'a ChatUser,
    timestamp: DateTime<Utc>,
    message: String,
}

pub struct UserJoinMessage<'a> {
    user: &'a ChatUser,
    timestamp: DateTime<Utc>,
}

impl ChatUser {
    pub fn new(username: &str) -> Self {
        Self {
            username: String::from(username),
        }
    }

    pub fn change_username(&mut self, new_username: &str) {
        self.username = String::from(new_username);
    }
}

impl<'a> ChatMessage<'a> {
    pub fn new(user: &'a ChatUser, message: &str) -> Self {
        Self {
            user,
            timestamp: Utc::now(),
            message: String::from(message),
        }
    }
}

impl<'a> UserJoinMessage<'a> {
    pub fn new(user: &'a ChatUser) -> Self {
        Self {
            user,
            timestamp: Utc::now(),
        }
    }
}

impl<'a> FormatMessage for ChatMessage<'a> {
    fn to_message(&self) -> String {
        format!(
            "{}   @{} | {}",
            self.timestamp.time(),
            self.user.username,
            self.message
        )
    }
}

impl<'a> FormatMessage for UserJoinMessage<'a> {
    fn to_message(&self) -> String {
        format!("{} -> {} joined the chat", self.timestamp.time(), self.user.username)
    }
}
