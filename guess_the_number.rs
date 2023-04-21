use rand::Rng;
use std::io;

fn main() {
    let mut restart: String = String::new();

    while restart != "y" {
        let mut attempts_remaining: i8 = 5;
        let random_number: i8 = rand::thread_rng().gen_range(1..101);
        let mut player_won: bool = false;

        println!("Welcome to Guess the Number!!!");
        println!("You need to guess a number between 1 and 100");
        println!("Random number: {}", random_number); // Delete this line later

        while attempts_remaining > 0 {
            println!("You have {} attempts remaining.", attempts_remaining);
            println!("Enter your guess: ");
            let mut player_guess: String = String::new();
            io::stdin().read_line(&mut player_guess);
            let player_guess: i8 = player_guess.trim().parse().unwrap();

            if player_guess > random_number {
                attempts_remaining -= 1;
                println!("Too High!");

                if attempts_remaining == 0 {
                    player_won = false;
                    break;
                }
            } else if player_guess < random_number {
                attempts_remaining -= 1;
                println!("Too Low!");

                if attempts_remaining == 0 {
                    player_won = false;
                    break;
                }
            } else {
                player_won = true;
                break;
            }
        }

        if player_won {
            println!("You Win! Good Job!");
        } else {
            println!("You Lose! Unlucky!");
        }
        println!("Would you like to play again? [y/n]");
        io::stdin().read_line(&mut restart);
        if restart == "y" {
            println!("\n");
        } else if restart == "n" {
            println!("gg!");
        }
    }
}
