 #include "pico/stdlib.h"
 #include <stdio.h>

 int main() {
     const uint led_pin = 25; 
     int i = 0;
     gpio_init(led_pin);
     gpio_set_dir(led_pin,GPIO_OUT);
     printf("Hey, sono partito!\r\n");

     while (true){
         
         gpio_put(led_pin,false);
         sleep_ms(100);
         gpio_put(led_pin,true);
         sleep_ms(100);
         gpio_put(led_pin,false);
         sleep_ms(100);
         gpio_put(led_pin,true);
         sleep_ms(1000);
         printf(i++ + "\n");
         
     }
 }
