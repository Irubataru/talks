#[derive(Debug, Copy, Clone)]
enum DogSpecies {
    Dachs,
    GoldenRetriever
}

enum Thing {
    City(String),
    Prime(u32),
    Colour(u8,u8,u8),
    Dog {name: String, species: DogSpecies}
}

fn pretty_print_thing(thing: &Thing) {
    match thing {
        Thing::City(city_name) => println!("You are in {}", city_name),
        Thing::Prime(number) => println!("The prime number is {}", number),
        Thing::Colour(red, green, blue) => println!("Hex code for colour is {:02x}{:02x}{:02x}", red, green, blue),
        Thing::Dog { name, species } => println!("{} is a good dog! A perfect {:?}", name, species)
    }
}

fn get_dog_species(thing: &Thing) -> Option<DogSpecies> {

   if let Thing::Dog { name: _, species} = thing {
       return Some(*species);
   }

   None
}


fn main() {
    pretty_print_thing(&Thing::City(String::from("Oslo")));
    pretty_print_thing(&Thing::Prime(43));
    pretty_print_thing(&Thing::Colour(122, 162, 247));
    pretty_print_thing(&Thing::Dog { name: String::from("Nala"), species: DogSpecies::Dachs });

    let nala = Thing::Dog { name: String::from("Nala"), species: DogSpecies::Dachs };
    println!("Nala is a {:?}", get_dog_species(&nala) );

}

