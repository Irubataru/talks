pub trait FormatMessage {
    fn to_message(&self) -> String;
}

impl FormatMessage for &str {
    fn to_message(&self) -> String {
        String::from(*self)
    }
}

impl FormatMessage for u32 {
    fn to_message(&self) -> String {
        self.to_string()
    }
}

impl FormatMessage for String {
    fn to_message(&self) -> String {
        self.clone()
    }
}
