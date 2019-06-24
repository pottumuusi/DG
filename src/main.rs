// If prefixed with "_" compiler will not warn that the parameter is not used.
// The parameter name is not mandatory, simply "_" can be used.
fn get_world(_x: &'static str) -> &'static str {
    return "world";
}

fn main() {
    let world = "world";
    let explicit_world: &'static str = "world";
    println!("Hello, {}! 1", world);
    println!("Hello, {}! 2", explicit_world);

    println!("Hello, {}! 3", get_world("anything"));
}
