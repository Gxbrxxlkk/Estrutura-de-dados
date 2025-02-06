#include <stdio.h>
#include <string.h>

int main() {

    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};  // Indices: 0-9

    int N;
    scanf("%d", &N); 
    getchar(); // para capturar o enter 

    for (int i = 0; i < N; i++) {
        char numero[101]; // 101 para capturar o \n
        fgets(numero, sizeof(numero), stdin);

        // Remove o caractere de nova linha, caso exista
        numero[strcspn(numero, "\n")] = 0;

        int total_leds = 0;
        for (int j = 0; j < strlen(numero); j++) {
            int digito = numero[j] - '0';  // Converte o caractere para o valor inteiro atraves da subtração dos valores ASCII
            total_leds += leds[digito]; 
        }

        printf("%d leds\n", total_leds);  

    return 0;
}}
