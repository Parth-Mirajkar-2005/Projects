import random

def number_guessing_game():
    print("🎮 Welcome to the Ultimate Number Guessing Game! 🎉")
    print("Choose your difficulty level:")
    print("1. Easy   (Range: 1-50, Attempts: 10)")
    print("2. Medium (Range: 1-100, Attempts: 7)")
    print("3. Hard   (Range: 1-200, Attempts: 5)")
    print("4. Custom (Choose your own range and attempts!)")

    # Get difficulty choice
    while True:
        try:
            difficulty = int(input("Enter the difficulty level (1-4): "))
            if difficulty not in [1, 2, 3, 4]:
                print("⚠️ Please choose a valid option (1-4).")
                continue
            break
        except ValueError:
            print("⚠️ Invalid input! Please enter a number (1-4).")
    
    # Set parameters based on difficulty
    if difficulty == 1:
        lower_bound, upper_bound = 1, 50
        max_attempts = 10
    elif difficulty == 2:
        lower_bound, upper_bound = 1, 100
        max_attempts = 7
    elif difficulty == 3:
        lower_bound, upper_bound = 1, 200
        max_attempts = 5
    else:
        while True:
            try:
                lower_bound = int(input("Enter the lower bound of the range: "))
                upper_bound = int(input("Enter the upper bound of the range: "))
                if lower_bound >= upper_bound:
                    print("⚠️ Lower bound must be less than upper bound.")
                    continue
                max_attempts = int(input("Enter the number of attempts: "))
                if max_attempts <= 0:
                    print("⚠️ Number of attempts must be greater than zero.")
                    continue
                break
            except ValueError:
                print("⚠️ Invalid input! Please enter valid numbers.")
    
    print(f"\nGreat! Your range is [{lower_bound}, {upper_bound}], and you have {max_attempts} attempts.")
    number_to_guess = random.randint(lower_bound, upper_bound)
    attempts = 0
    
    # Fun prompts
    fun_prompts = [
        "Not even close. Try harder! 🤷",
        "Ouch! That’s way off. 😅",
        "Getting warmer, but still no. 🌡️",
        "Are you guessing blindly? 🎯",
        "You’re not psychic, are you? 🔮",
    ]
    
    while attempts < max_attempts:
        try:
            print(f"\n🔍 Current Range: [{lower_bound}, {upper_bound}]")
            guess = int(input(f"Attempt {attempts + 1}/{max_attempts}: What's your guess? "))
            
            if guess < lower_bound or guess > upper_bound:
                print("🚫 Out of bounds! Stay within the range.")
                continue
            
            attempts += 1
            
            if guess == number_to_guess:
                print(f"🎉 Woohoo! You guessed it in {attempts} attempts!")
                break
            else:
                if abs(guess - number_to_guess) <= 5:
                    print("🔥 So close, yet so far! You're within 5 of the correct number.")
                elif abs(guess - number_to_guess) <= 10:
                    print("🌟 You're within 10! Keep going.")
                else:
                    print(random.choice(fun_prompts))
                
                # Shrink the range
                if guess < number_to_guess:
                    print("Hint: It's higher! 📈")
                    lower_bound = max(lower_bound, guess + 1)
                else:
                    print("Hint: It's lower! 📉")
                    upper_bound = min(upper_bound, guess - 1)
        
        except ValueError:
            print("⚠️ Invalid input! Please enter a valid number.")
    
    if attempts == max_attempts:
        print(f"😞 You've used all your attempts! The correct number was {number_to_guess}. Better luck next time!")
    print("Game Over! Thanks for playing. 🎮")

# Run the game
number_guessing_game()