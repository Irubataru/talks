fn main() {
    let value = Ok(42);
    value.unwrap();      // panics if value is Err
    value.unwrap_or(12); // returns 12 is value is Err
    value.expect("Expect no errors"); // Unwrap with custom error message
}
