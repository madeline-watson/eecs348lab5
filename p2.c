#include <stdio.h>  

void getCombinations(int gameScore) {
    for(int td = 0; td <= gameScore; td++) {
        for(int fg = 0; fg <= gameScore; fg++) {  
            for(int safety = 0; safety <= gameScore; safety++) {   
                for(int td2 = 0; td2 <= gameScore; td2++) {  
                    for(int td1 = 0; td1 <= gameScore; td1++) {  
                        if((td*6 + fg*3 + safety*2 + td2*8 + td1*7) == gameScore) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety); 
                        }
                    }
                }
            }
        }
    } 
}

int main() {
    int score; 
    while (1) {
        printf("Enter 0 or 1 to STOP\n"); 
        printf("Enter the NFL Score:"); 
        scanf("%d", &score);   
        if (score == 1 || score == 0) {
            printf("Quitting...\n");  
            break; 
        }
        getCombinations(score); 
    }
}