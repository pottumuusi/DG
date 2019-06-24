// If prefixed with "_" compiler will not warn that the parameter is not used.
// The parameter name is not mandatory, simply "_" can be used.
fn get_world(_x: &'static str) -> &'static str {
    return "world";
}

fn is_less_than_10(x: i32) -> &'static str {
    let result: &'static str;

    if x < 10 {
        result = "less than 10";
    } else {
        result = "10 or more";
    }

    return result;
}

fn is_less_than_10_brief(x: i32) -> &'static str {
    if x < 10 {
        "less than 10"
    } else {
        "10 or more"
    }
}

// Explicitly tell that return value is of void type.
fn run_if_examples() -> () {
    let mut test_value = 2;
    let want_bananas = true;
    let wanted_fruit: &'static str;

    wanted_fruit = if want_bananas
        { "banana" } else
        { "orange" };

    println!("test_value ({}) is: {}", test_value, is_less_than_10(test_value));
    println!("test_value ({}) is: {}", test_value, is_less_than_10_brief(test_value));
    test_value = 15;
    println!("test_value ({}) is: {}", test_value, is_less_than_10(test_value));
    println!("test_value ({}) is: {}", test_value, is_less_than_10_brief(test_value));

    println!("Wanted fruit is: {}", wanted_fruit);
}

fn main() {
    let world = "world";
    let explicit_world: &'static str = "world";

    println!("Hello, {}! 1", world);
    println!("Hello, {}! 2", explicit_world);
    println!("Hello, {}! 3", get_world("anything"));

    run_if_examples();
}
