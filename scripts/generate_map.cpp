#include <iostream>

int main(int argc, char** argv){
    // Seed
    srand(clock()); 
    // Err check
    if(argc != 2 || atoi(argv[1]) == 0){
        fprintf(stderr, "Usage: ./generate_map #N where N is the dimension of an NxN matrix\n");
        fflush(stderr);
        exit(1);
    }
    int n = atoi(argv[1]);
    int tiles = rand()%100;
    if(tiles < 6) tiles = 6;
    char* chars = new char[tiles];
    int* costs = new int[tiles];
    fprintf(stdout, "%d\n", tiles);
    fflush(stdout);
    // Gen blocks and cache them
    for(int i = 0; i < tiles; i++){
        chars[i] = rand()%60+65;
        costs[i] = rand()%n+1;
        fprintf(stdout, "%c %d\n", chars[i], costs[i]);
        fflush(stdout);
    }
    fprintf(stdout, "%d %d\n", n, n);
    // Rand gen map from tiles we have
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fprintf(stdout, "%c ", chars[rand()%tiles]);
        }
        fprintf(stdout, "\n");
        fflush(stdout);
    }
    // Start from beg and end at the end
    fprintf(stdout, "%d %d\n", 0, 0);
    fflush(stdout);
    fprintf(stdout, "%d %d\n", n-1, n-1);
    fflush(stdout);
    return 0;
}
