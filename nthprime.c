/*
* Copyright (c) 2012, Kevin Peterson
* Released under the MIT License <http://opensource.org/licenses/mit-license.php>
*/
#include <math.h>
#include <stdio.h>

int get_nth_prime(int nth_prime) {
    int primes = 0;
    int current_prime;

    int i;
    for(i=2;primes<nth_prime;i++){
        char prime = 1;
        int j;
        for(j=2;j<=sqrt(i);j++){
            if(i % j == 0 && i != j){
                prime = 0;
                break;
            }
        }
        if(prime){
            current_prime = i;
            primes++;
        }
    }

    return current_prime;
}

int main(int argc, char* argv[]) {
    int nth = atoi(argv[1]);

    int prime = get_nth_prime(nth);

    printf("%i\n", prime);

    return 0;
}

