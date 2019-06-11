#include <stdio.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

int contador = 0;

void delay(int number_of_seconds) { 
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
}
 
void fazendonumero1(void *pvParameters) {
    while(1) {
        printf("Fazendo xixi\n");
        delay(1);
        vTaskDelay(10 / portTICK_RATE_MS);
    }
}

void fazendonumero2(void *pvParameters) {
    while(1) {
        printf("Pessoa com dor de barriga\n");
        vTaskDelay(5000 / portTICK_RATE_MS);
    }
}
 
void app_main() {
    xTaskCreate(&fazendonumero1, "fazendonumero1", 2048, NULL, 1,NULL);
    xTaskCreate(&fazendonumero2, "fazendonumero2", 2048, NULL, 2,NULL);
}