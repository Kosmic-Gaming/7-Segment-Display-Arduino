/*
   Made By Ankur Parchure
   April 13, 2022
   Hardware Tested on: Arduino Nano [ATmega 328p - Old Bootloader] and 7 Segment Display-Common Cathode
*/

//Define Hardware Pins
const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
const int DP = 9;

//Computation Variable - to make our calculations easy!
int N = 0;

void setup() {

  // Start the Serial Monitor (to debug any errors!)
  Serial.begin (9600);

  //Define the Pins
  pinMode (A, OUTPUT); pinMode (B, OUTPUT); pinMode (C, OUTPUT); pinMode (D, OUTPUT); pinMode (E, OUTPUT); pinMode (F, OUTPUT); pinMode (G, OUTPUT); pinMode (DP, OUTPUT);

  //Clear the 7 Segment Display and Test all Pins.
  clearseg ();
  test ();
}

void loop() {
  //Pretty Basic Loop to display numbers...
  printseg (N);
  delay (1000);
  clearseg ();
  N++;
  if (N > 9) {
    N = 0;
  }
}
void clearseg () {
  //Clear the Display
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, LOW);
}
void test () {
  //Test the Display: Includes a sick animation!
  Serial.print ("Testing...");
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
  digitalWrite (DP, HIGH);
  delay (2000);
  digitalWrite (G, LOW);
  delay (100);
  digitalWrite (A, LOW);
  delay (100);
  digitalWrite (B, LOW);
  delay (100);
  digitalWrite (C, LOW);
  delay (100);
  digitalWrite (D, LOW);
  delay (100);
  digitalWrite (E, LOW);
  delay (100);
  digitalWrite (F, LOW);
  delay (100);
  digitalWrite (DP, LOW);
  delay (1000);
}
void printseg (int n) {
  //Converting variables from code into actual hardware output
  if (n == 0) {
     /*
     *  --
     * |  |
     * |  |
     *  --
     *  
     * [I'm terrible at this dont judge me]
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (C, HIGH);
    digitalWrite (D, HIGH);
    digitalWrite (E, HIGH);
    digitalWrite (F, HIGH);
    Serial.println (0);
  }
  else if (n == 1) {
    /*
     *    
     *    |
     *    |
     *    
     *  
     */
     
    digitalWrite (B, HIGH);
    digitalWrite (C, HIGH);
    Serial.println (1);
  }
  else if (n == 2) {
    /*
     *  --  
     *  __|
     * |  
     *  --  
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (G, HIGH);
    digitalWrite (E, HIGH);
    digitalWrite (D, HIGH);
    Serial.println (2);
  }
  else if (n == 3) {
    /*
     *  --  
     *  __|
     *    |
     *  --  
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (G, HIGH);
    digitalWrite (C, HIGH);
    digitalWrite (D, HIGH);
    Serial.println (3);
  }
  else if (n == 4) {
    /*
     *    
     * |__|
     *    |
     *    
     *  
     */
     
    digitalWrite (F, HIGH);
    digitalWrite (G, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (C, HIGH);
    Serial.println (4);

  }
  else if (n == 5) {
    /*
     *  --  
     * |__
     *    |
     *  --  
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (F, HIGH);
    digitalWrite (G, HIGH);
    digitalWrite (C, HIGH);
    digitalWrite (D, HIGH);
    Serial.println (5);
  }
  else if (n == 6) {
      /*
     *  --  
     * |__
     * |  | 
     *  --  
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (F, HIGH);
    digitalWrite (G, HIGH);
    digitalWrite (C, HIGH);
    digitalWrite (D, HIGH);
    digitalWrite (E, HIGH);
    Serial.println (6);
  }
  else if (n == 7) {
        /*
     *  --  
     *    |
     *    |
     *   
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (C, HIGH);
    Serial.println (7);
  }
  else if (n == 8) {
     /*
     *  --  
     * |__|
     * |  |
     *  --  
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (C, HIGH);
    digitalWrite (D, HIGH);
    digitalWrite (E, HIGH);
    digitalWrite (F, HIGH);
    digitalWrite (G, HIGH);
    Serial.println (8);
  }
  else if (n == 9) {
        /*
     *  --  
     * |__|
     *    |
     *  --  
     *  
     */
     
    digitalWrite (A, HIGH);
    digitalWrite (B, HIGH);
    digitalWrite (C, HIGH);
    digitalWrite (D, HIGH);
    digitalWrite (F, HIGH);
    digitalWrite (G, HIGH);
    Serial.println (9);
  }
  else if (n < 0 or n > 9) {
     /*
     *   
     * 
     *    
     *     . 
     *  
     */
     
    digitalWrite (DP, HIGH);
    Serial.println ("Invalid Value!");
  }
  pulse ();
}
void pulse () {
   //For Aesthetic purposes lol
   
  digitalWrite (DP, HIGH);
  delay (20);
  digitalWrite (DP, LOW);
}
