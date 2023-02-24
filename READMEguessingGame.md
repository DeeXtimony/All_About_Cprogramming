The srand function is used to seed the random number generator with the current time, 

so that each time the program is run, a different random number will be generated.

The num variable is set to a random number between 1 and 100 using the rand function and the modulo operator.

The user is prompted to guess a number between 1 and 100 using the printf function.

The user's input is read using the scanf function and stored in the guess variable.

The count variable is incremented to keep track of the number of guesses.

If the user's guess is higher than the random number, a message is printed saying "Too high! Guess again." using the printf function.

If the user's guess is lower than the random number, a message is printed saying "Too low! Guess again." using the printf function.

If the user's guess is correct, a congratulatory message is printed along with the number of tries it took to guess the number using the printf function.

The loop continues until the user guesses the correct number, at which point the loop is exited and the program terminates
