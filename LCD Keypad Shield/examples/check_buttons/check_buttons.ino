#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// ----- Buttons (A0) -----
enum Button { BTN_NONE=0, BTN_RIGHT, BTN_UP, BTN_DOWN, BTN_LEFT, BTN_SELECT };

Button buttonEvent = BTN_NONE;

Button readButton() {
  int v = analogRead(A0);
  Serial.println(v);
  if (v < 10) return BTN_RIGHT;
  if (v < 150) return BTN_UP;
  if (v < 350) return BTN_DOWN;
  if (v < 500) return BTN_LEFT;
  if (v < 800) return BTN_SELECT;
  return BTN_NONE;
}

bool updateButtons() {
  buttonEvent = readButton();
}

void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
  
  lcd.print("Hola ... ");
  delay(1000);

}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(buttonEvent == BTN_NONE ? "presione boton..." : "Presionando...");
  updateButtons();
  
  lcd.setCursor(1, 1);
  switch (buttonEvent) {
    case BTN_SELECT:
      lcd.print("Boton Select         ");
      break;

    case BTN_LEFT:
      lcd.print("Boton Izquierda      ");
      break;

    case BTN_RIGHT:
      lcd.print("Boton Derecha        ");
      break;
    case BTN_UP:
      lcd.print("Boton Arriba         ");
      break;
    case BTN_DOWN:
      lcd.print("Boton Abajo          ");
      break;

    default:
      lcd.print("--              ");
      break;
  }
}
