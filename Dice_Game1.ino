/*
Yasmin Kullab
 Dice Game 
 
 This code explains a dice game that has two players: Green and Blue.
 Each player gets a chance to roll the dice during a game play. 
 The highest roll wins the game. 
 If the rolls are the same, then the game is tied. 
*/
int led1=13;
int led2=7;
int led3=11;
long player1;
long player2;
int inputCode;

void setup()
{
   Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  Serial.println("Welcome to the dice game.");
  Serial.println("Press 1 if you would like to play a round of dice. "); // Start playing
      Serial.println();
} 

 void loop()
{
   
      
  // check the serial monitor for user input
  if (Serial.available())
  {
    // read the input 
    inputCode = Serial.read();
      
    // process the input
    switch (inputCode) 
    {
      case '0': // play the game 
      Serial.println("OK. Maybe later.");
      Serial.println("Press 1 if you would like to play a round of dice. ");
      Serial.println();
      
      break;
      case '1': // play the game 
       playGame(); 
       Serial.println("Press 1 if you would like to play a round of dice. ");
       Serial.println(); 
       break; 
      default:  // somthing other than Y or N has been entered 
       Serial.println("Error: Press 1 if you would like to play a round of dice. ");
       Serial.println();
    }
  }
}
void playGame(){
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
 //if player1 is playing, then will be asssigned to green, so then
 //renadom function will be used to generate a number for green 1-6 
  		player1 = random(1, 6);

  //if player2 is playing, then blue will be selected, so then 
  // random function will be used to generate numbers from 1-6
   player2 = random(1, 6);
    // if Player1 got a higher number then GREEN_LED will turn on
  if (player1>player2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    analogWrite(led3, 0);
   Serial.print("Green Wins!"); // GREEN_LED will be On!
       Serial.println();
       Serial.println();
    
   Serial.print("Player 1 rolled: "); 
   Serial.println(player1);
   Serial.print("Player 2 rolled: "); 
   Serial.println(player2);
       Serial.println();
  }
  // if Player2 got a higher number then BLUE_LED will turn on
    if (player2>player1){
     digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      analogWrite(led3, 0);
   Serial.print("Blue Wins!"); // BLUE_LED will be On!
    Serial.println();
    Serial.println();
      
   Serial.print("Player 1 rolled: "); 
   Serial.println(player1);
   Serial.print("Player 2 rolled: "); 
   Serial.println(player2);
       Serial.println();
  }
 // if both numbers are the same then WHITE_LED will turn on
  else if(player1==player2){
  
  analogWrite(led3, 100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
    
  Serial.print("Tie! Both rolls were "); // WHITE_LED will be On!
   Serial.println(player2);
    Serial.println(); 
  }
  
}
      