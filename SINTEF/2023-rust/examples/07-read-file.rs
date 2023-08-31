use std::{error::Error, fs::File, io::BufReader, io::prelude::*};

fn read_file(filename: &str) -> Result<String, Box<dyn Error>> {
    let file = File::open(filename)?;
    let reader = BufReader::new(file);
    
    let mut result = String::new();
    for line in reader.lines() {
        result.push_str(line?.as_str());
    }

    Ok(result)
}

fn main() -> Result<(), Box<dyn Error>> {
    Ok(())
}
