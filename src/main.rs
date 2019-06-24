// TODO Continue from line where "enumerate()" is mentioned

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

fn print_10_to_0() -> () {
    let mut x = 10;

    println!("Running: print_10_to_0");
    while x > 0 {
        println!("Current value of x is: {}", x);
        x = x - 1;
    }
}

fn break_infinite_loop() -> () {
    let mut x = 3;

    println!("Running: break_infinite_loop");
    loop {
        println!("Current value of x is: {}", x);

        if x <= 0 {
            break;
        }

        x = x - 1;
    }
}

fn iterate_through_vector(integers: Vec<i32>) -> () {
    let iterator;

    println!("Running: iterate_through_vector");

    // iterator = &integers;
    // iterator = integers;
    // The above should be usable somehow as well
    iterator = integers.iter();

    for i in iterator {
        println!("i is: {}", i);
    }

    for i in 0..integers.len() {
        println!("i is: {}, integers[i] is: {}", i, integers[i]);
    }
}

fn run_loop_examples() -> () {
    let mut vec: Vec<i32> = Vec::new();
    vec.push(0);
    vec.push(1);
    vec.push(2);
    vec.push(3);

    print_10_to_0();
    break_infinite_loop();

    iterate_through_vector(vec);
}

fn main() {
    let world = "world";
    let explicit_world: &'static str = "world";

    println!("Hello, {}! 1", world);
    println!("Hello, {}! 2", explicit_world);
    println!("Hello, {}! 3", get_world("anything"));

    println!("\nConditional examples:");
    run_if_examples();

    println!("\nLoop examples:");
    run_loop_examples();
}
