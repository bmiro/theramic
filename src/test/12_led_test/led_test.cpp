#include <Arduino.h>

#define PIN_LED_DO    0
#define PIN_LED_DO_S  7
#define PIN_LED_RE    1
#define PIN_LED_RE_S  8
#define PIN_LED_MI    2
#define PIN_LED_FA    3
#define PIN_LED_FA_S  9
#define PIN_LED_SOL   4
#define PIN_LED_SOL_S 10
#define PIN_LED_LA    5
#define PIN_LED_LA_S  12
#define PIN_LED_SI    6

#define DELAY 1000

int toggle;

void setup() {                
    pinMode(PIN_LED_DO, OUTPUT);
    pinMode(PIN_LED_DO, OUTPUT);   
    pinMode(PIN_LED_DO_S, OUTPUT);  
    pinMode(PIN_LED_RE, OUTPUT);    
    pinMode(PIN_LED_RE_S, OUTPUT);  
    pinMode(PIN_LED_MI, OUTPUT);    
    pinMode(PIN_LED_FA, OUTPUT);    
    pinMode(PIN_LED_FA_S, OUTPUT);  
    pinMode(PIN_LED_SOL, OUTPUT);   
    pinMode(PIN_LED_SOL_S, OUTPUT);
    pinMode(PIN_LED_LA, OUTPUT);    
    pinMode(PIN_LED_LA_S, OUTPUT);  
    pinMode(PIN_LED_SI, OUTPUT);    

    toggle = 0;

}

void loop() {
    int v_out, v_out_s;

    toggle = !toggle;
    v_out = (toggle) ? HIGH : LOW;
    v_out_s = (toggle) ? LOW : HIGH;

    digitalWrite(PIN_LED_DO, v_out);
    digitalWrite(PIN_LED_DO, v_out);   
    digitalWrite(PIN_LED_DO_S, v_out_s);  
    digitalWrite(PIN_LED_RE, v_out);    
    digitalWrite(PIN_LED_RE_S, v_out_s);  
    digitalWrite(PIN_LED_MI, v_out);    
    digitalWrite(PIN_LED_FA, v_out);    
    digitalWrite(PIN_LED_FA_S, v_out_s);  
    digitalWrite(PIN_LED_SOL, v_out);   
    digitalWrite(PIN_LED_SOL_S, v_out_s);
    digitalWrite(PIN_LED_LA, v_out);    
    digitalWrite(PIN_LED_LA_S, v_out_s);  
    digitalWrite(PIN_LED_SI, v_out);    
    
    delay(DELAY);
}



