/* Photoresistor Code UCSD ECE 5 Lab 4 */
/* Variables for Light Sensors*/

// Initialize Photo Resistor Array
int LDR_Pin[] = {1, 2, 3, 4, 5, 6, 7}; 

int totalPhotoResistors = sizeof(LDR_Pin) / sizeof(LDR_Pin[0]);  

int LDR[99];

void setup() {
  Serial.begin(9600); // For serial communication set up
}

void loop() {
  ReadPhotoResistors();
  Print();
}

// ************************************************************************************************* //
// function to read photo resistors
void ReadPhotoResistors() {
  // looping through analog pins 1-7 and storing their values into our LDR array
  for (int i = 0; i < totalPhotoResistors; i++) {
    LDR[i] = map(analogRead(LDR_Pin[i]),0,4095,0,100);
    delay(2);
  }
}

// ************************************************************************************************* //
// function to print values of interest
void Print() {
  for (int i = 0; i < totalPhotoResistors; i++) {
    // Printing the photo resistor reading values one by one
    Serial.print(LDR[i]);
    Serial.print(" ");
  }
  Serial.println(); // This just prints a new line, allowing the next set of readings to be on a new line

  delay(200); //just here to slow down the output for easier reading if desired
}
