#include <random>
#include <cstdio>

int main(int argc, char** argv){

    if(argc != 2){
        fprintf(stderr, "Usage: ./guess [wallet file]\n");
        fflush(stderr);
        exit(1);
    }

    FILE* fptr = fopen(*(argv+1), "r");
    if(fptr == NULL){
        fprintf(stderr, "Your wallet does not exist.\n");
        fflush(stderr);
        exit(1);
    }

    int guess, wager, balance, secret;

    fscanf(fptr, "%d", &balance);
    fclose(fptr);
    if(balance <= 0){
        fprintf(stderr, "You have no money left, or you have overdrafted, deposit more.\n");
        fflush(stderr);
        exit(1);
    }

    fprintf(stdout, "Your current balance is %d.\n", balance);
    fprintf(stdout, "Enter your wager: ");
    fflush(stdout);
    fscanf(stdin, " %d", &wager);

    if(wager > balance){
        fprintf(stderr, "You have entered a wager larger than your balance.\n");
        fflush(stderr);
        exit(1);
    }

    std::random_device rd;
    std::mt19937_64 gen64{rd()};
    std::uniform_int_distribution<int> dist(1, 100);

    fprintf(stdout, "Guess a number between %d and %d: ", 1, 100);
    fflush(stdout);
    fscanf(stdin, "%d", &guess);

    secret = dist(gen64);

    fptr = fopen(*(argv+1), "w");
    if(guess == secret){
        balance += wager;
        fprintf(stdout, "You guessed the number correctly.\n");
        fflush(stdout);
    }
    else{
        balance -= wager;
        fprintf(stdout, "You guess the number incorrectly, it was %d.\n", secret);
        fflush(stdout);
    }
    fprintf(fptr, "%d\n", balance);
    fflush(fptr);
    fclose(fptr);
    fprintf(stdout, "Your remaining balance is $%d.\n", balance);
    fflush(stdout);
    return 0;
}