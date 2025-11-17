import random

def number_heist():
    print("💣 Welcome to NUMBER HEIST 💣")
    print("Crack the vault code (between 1 and 100).")
    print("You have 7 attempts. Good luck!\n")

    secret = random.randint(1, 100)
    attempts_left = 7
    previous_diff = None

    while attempts_left > 0:
        try:
            guess = int(input(f"🔐 Enter your guess ({attempts_left} attempts left): "))
        except ValueError:
            print("❗ Invalid input! Please enter a number between 1 and 100.\n")
            continue

        if not 1 <= guess <= 100:
            print("🚫 Number must be between 1 and 100!\n")
            continue

        if guess == secret:
            print("\n🎯 JACKPOT! VAULT UNLOCKED!")
            print(f"The vault code was: {secret}")
            break

        current_diff = abs(secret - guess)

        if previous_diff is None:
            print("Too high!" if guess > secret else "Too low!")
        else:
            if current_diff < previous_diff:
                print("🔥 Getting Warmer!")
            elif current_diff > previous_diff:
                print("🧊 Getting Colder!")
            else:
                print("😐 Same distance...")

        previous_diff = current_diff
        attempts_left -= 1
        print()

    if attempts_left == 0 and guess != secret:
        print("💥 HEIST FAILED!")
        print(f"The vault code was: {secret}")

# Run the game
if __name__ == "__main__":
    number_heist()