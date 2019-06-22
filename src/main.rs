fn main() {
    let world = "world";
    let explicit_world: &'static str = "world";
    println!("Hello, {}!", world);
    println!("Hello, {}!", explicit_world);
}
