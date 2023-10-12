#include <stdio.h> 
#include <stdbool.h> 


char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"}; 

float sales[12] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200}; 
 
int min() {
    float min = sales[0];
    int index = 0;
    int i;
    for (i = 1; i < 12; i++) { 
        if (sales[i] < min) {
            index = i; 
            min = sales[i];
        }
    }
    return index; 
}

int max() {
    float max = sales[0];
    int index = 0; 
    int i;
    for (i = 1; i < 12; i++) { 
        if (sales[i] > max) {
            index = i;
            max = sales[i];
        }
    }
    return index;     
}

float average(int start, int end) {  
    return sum(start, end) / (end - start);      
}

void printSummary() {
    printf("Sales Summary:\n"); 
    printf("%-15s $%.2f (%s)\n", "Minimum Sales:", sales[min()], month[min()]); 
    printf("%-15s $%.2f (%s)\n", "Maximum Sales:", sales[max()], month[max()]);    
    printf("%-15s $%.2f\n", "Average Sales:", average(0, 12));     
}

void printSales() {
    printf("Monthly Sales Report:\n");   
    printf("%-10s %s\n", "Month", "Sales");      
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%-.2f\n", month[i], sales[i]);          
    }
    printf("\n"); 
}

void printAverage() {
    printf("\nSix-Month Moving Average Report:\n"); 
    printf("%-8s - %-10s $%.2f\n", month[0], month[5], average(0, 6));    
    printf("%-8s - %-10s $%.2f\n", month[1], month[6], average(1, 7));  
    printf("%-8s - %-10s $%.2f\n", month[2], month[7], average(2, 8));  
    printf("%-8s - %-10s $%.2f\n", month[3], month[8], average(3, 9));  
    printf("%-8s - %-10s $%.2f\n", month[4], month[9], average(4, 10));  
    printf("%-8s - %-10s $%.2f\n", month[5], month[10], average(5, 11));  
    printf("%-8s - %-10s $%.2f\n", month[6], month[11], average(6, 12));  
}

float sum(int start, int end) {
    float sum = 0; 
    for (int i = start; i < end; i++) { 
        sum += sales[i]; 
    }
    return sum; 
}

int* sort() {
    static int indexes[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };   

    float salesCopy[12] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200}; 

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {   
            if (salesCopy[j] < salesCopy[j+1]) { 
                float temp = salesCopy[j];  
                int tempI = indexes[j]; 
                salesCopy[j] = salesCopy[j+1]; 
                indexes[j] = indexes[j+1]; 
                salesCopy[j+1] = temp;  
                indexes[j+1] = tempI; 
            }
        }
    }
    return indexes; 
}

void printReport() {
    int* indexPtr; 
    indexPtr = sort(); 
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-11s %s\n ", "Month", "Sales");          
    for (int i = 0; i < 12; i++) {  
        printf( "%-10s  $%.2f\n", month[*(indexPtr + i)], sales[*(indexPtr + i)]);        
    }
}

int main() {
    printSales(); 
    printSummary(); 
    printAverage(); 
    printReport(); 
    return 0; 
}