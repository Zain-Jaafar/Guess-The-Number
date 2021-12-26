import random

print("""
Guess The Number!!!

---------------------
Pick a Number Between 1-100
You Get 3 Tries!
Good Luck!
""")

answer = random.randint(1, 100)
lives = 5

def main():
    global answer, lives
    
    while True:
        if lives == 5:
            player_answer = int(input("Enter Your Answer: "))
        elif lives == 4 or lives == 3 or lives == 2 or lives == 1:
            player_answer = int(input("Try Again: "))
            
        if lives != 0:
            if player_answer > answer:
                print("Too High! \n")
                lives -= 1
                
            if player_answer < answer:
                print("Too Low! \n")
                lives -= 1
            
            if player_answer == answer:
                print("You Win GGEZ! \n")
        
        if lives == 0:
            break

if __name__ == "__main__":
    main()

print("You Lose!")