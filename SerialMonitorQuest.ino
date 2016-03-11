/*
0: ship
2: start conveyor belt

           +-+
           |0|
         +-+-+
         |2|1|
         +-+-+
          |
          | on conveyor belt
          v
     +-+-+-+
     |5|4|3|-> GAME OVER
     +-+-+-+
      | | |
      | | | jump on ledge above belt
      v v v
   +-+-+-+-+
   |9|8|7|6|
   +-+-+-+-+
    |
    | climb down 
    v 
 
 
*/

int room = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("**********************"); 
  Serial.println("*                    *"); 
  Serial.println("* SerialMonitorQuest *"); 
  Serial.println("*                    *"); 
  Serial.println("**********************"); 
  Serial.println(""); 
  while (1)
  {
    Serial.println("**********************"); 
    //Serial.print("(you are in room "); Serial.print(room); Serial.println(")");
    print_room();
    while (1)
    {
      if (Serial.available())
      {
        const String s = Serial.readString();
        process_command(s);
        delay(1000);
        break;
      }
    }
  }
}

void loop() {}

void game_over()
{
  delay(500);
  Serial.println("*************");
  delay(500);
  Serial.println("*           *");
  delay(500);
  Serial.println("* GAME OVER *");
  delay(500);
  Serial.println("*           *");
  delay(500);
  Serial.println("*************");
  delay(500);
  while (1) { delay(1000); }  
}

void print_room()
{
  if (room == 0)
  {
    Serial.println("You are in a junk bay. Your trashed ship lies here.");  
    Serial.println("");  
    Serial.println("You can go south");  
  }
  else if (room == 1)
  {
    Serial.println("You are in a junk bay.");  
    Serial.println("");  
    Serial.println("You can go north and east");  
  }
  else if (room == 2)
  {
    Serial.println("You are in a junk bay.");  
    Serial.println("There is a junk conveyor that");  
    Serial.println("has big buckets with scrapmetal that go up.");  
    Serial.println("");  
    Serial.println("You can go west");  
  }
  else if (room == 3)
  {
    Serial.println("You are at the beginning of a conveyor belt.");  
    Serial.println("Above you is a ledge.");  
  }
  else if (room == 4)
  {
    Serial.println("You have travelled some distance on a conveyor belt.");  
    Serial.println("Above you is a ledge.");  
    Serial.println("You hear a loud noise.");  
  }
  else if (room == 5)
  {
    Serial.println("You have travelled a large distance on a conveyor belt.");  
    Serial.println("Above you is a ledge.");  
    Serial.println("The noise is very loud and appears to come.");  
    Serial.println("from a machine where the scrapmetal of the conveyor");  
    Serial.println("belt falls into.");  
  }
}

void process_command(const String&s)
{
  if (s == "die" || s == "commit suicide") { game_over(); }
  if (room == 0)
  {
    if (s == "s" || s == "south") { room = 1; return; }
  }
  if (room == 1)
  {
    if (s == "e") { room = 2; return; }
    if (s == "n") { room = 0; return; }
  }
  if (room == 2)
  {
    if (s == "w") { room = 1; return; }
    if (s == "jump" || s == "jump on bucket") 
    { 
      Serial.println("You jump on the bucket. It takes you up,");
      Serial.println("and dumps you on a conveyor belt");
      room = 3; 
      return; 
    }
  }
  if (room == 3)
  {
    Serial.println("The conveyor belt takes you further");
    room = 4;
    return;
  }
  if (room == 4)
  {
    Serial.println("The conveyor belt takes you further");
    room = 5;
    return;
  }
  if (room == 5)
  {
    Serial.println("You fall into the machine and get schredded to pieces.");
    game_over();
  }
}

