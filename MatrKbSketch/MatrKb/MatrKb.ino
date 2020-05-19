#include <Wire.h>

#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte ROWS = 4; //число строк клавиатуры
const byte COLS = 3; //число столбцов клавиатуры

char hexaKeys[ROWS][COLS] = {
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'},
      {'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; //к каким выводам подключаем управление строками

byte colPins[COLS] = {4, 3, 2}; //к каким выводам подключаем управление столбцами

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
      Serial.begin(9600);

      lcd.init(); // Инициализируем экран
      lcd.backlight();
}

void loop(){
      lcd.setCursor(0,0); //устанавливаем курсор на начало первой строки
      lcd.print("Press any key!");   
      char customKey = customKeypad.getKey();
      if (customKey){
            Serial.println(customKey);
            lcd.setCursor(0,1); //устанавливаем курсор на начало второй строки
            lcd.print(customKey);
      }
}

