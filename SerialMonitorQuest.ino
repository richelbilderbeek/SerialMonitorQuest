int room = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("**********************"); 
  Serial.println("*                    *"); 
  Serial.println("* SerialMonitorQuest *"); 
  Serial.println("*                    *"); 
  Serial.println("**********************"); 
  while (1)
  {
    Serial.print("(you are in room "); Serial.print(room); Serial.println(")");
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

void print_room()
{
  if (room == 0)
  {
    Serial.println("You are in a forest.");  
    Serial.println("");  
    Serial.println("You can go east");  
  }
  else if (room == 1)
  {
    Serial.println("You are in a forest.");  
    Serial.println("");  
    Serial.println("You can go east and west");  
  }
  else if (room == 2)
  {
    Serial.println("You are in a forest.");  
    Serial.println("");  
    Serial.println("You can go west");  
  }
}

void process_command(const String&s)
{
  if (room == 0)
  {
    if (s == "east") { room = 1; return; }
  }
  if (room == 1)
  {
    if (s == "east") { room = 2; return; }
    if (s == "west") { room = 0; return; }
  }
  if (room == 2)
  {
    if (s == "west") { room = 1; return; }
  }
}

