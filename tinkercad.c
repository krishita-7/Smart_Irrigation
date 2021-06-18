int tmp36 = A1;
int hum = A2;
int lamp = 2;
int mtr = 12;


int temperature = 25;
int humValue = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(tmp36, INPUT);
  pinMode(lamp, OUTPUT);
  pinMode(hum, INPUT);
  pinMode(mtr, OUTPUT);
}


 




void loop()
{
  temperature = map(analogRead(tmp36),0,410,-50,70);  
  humValue = map(analogRead(hum),0,1023,0,10);
  
  if(humValue <= 6  && humValue >= 5 )
  {
    if(temperature < 10)
    {
      digitalWrite(lamp, LOW);
      digitalWrite(mtr, LOW);
      Serial.println("Temperature too Low!");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
    else if(temperature>30)
    {
      digitalWrite(lamp, HIGH);
      digitalWrite(mtr, HIGH);
      Serial.println("Temperature too High");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
    else
    {
      digitalWrite(lamp, LOW);
      digitalWrite(mtr, LOW);
      Serial.println("Plants are OK");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
    
  
  }
  
  else if(humValue < 5)
  {
    if(temperature < 10)
    {
      Serial.println("Low Temperature & Humidity!");
      Serial.println("Temperature: ");
      Serial.println(temperature);
      Serial.println("Humidity: ");
      Serial.println(humValue);
      digitalWrite(lamp, HIGH);
      digitalWrite(mtr, HIGH);
    }
    else if(temperature >10 && temperature <30)
    {
      Serial.println("Low Humidity!");
      Serial.println("Temperature: ");
      Serial.println(temperature);
      Serial.println("Humidity: ");
      Serial.println(humValue);
      digitalWrite(lamp, HIGH);
      digitalWrite(mtr, HIGH);
    }
    else
    {
      digitalWrite(lamp, HIGH);
      digitalWrite(mtr, HIGH);
      Serial.println("High Temperature & Low Humidity");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
    
  }
  else
  {
    if(temperature < 10)
    {
      digitalWrite(lamp, LOW);
      digitalWrite(mtr, LOW);
      Serial.println("High Humidity & Low Temperature");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
    else if(temperature > 30)
    {
      digitalWrite(lamp, HIGH);
      digitalWrite(mtr, HIGH);
      Serial.println("High Humidity & High Temperature!");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
    else
    {
      digitalWrite(lamp, LOW);
   	  digitalWrite(mtr, LOW);
      Serial.println("High Humidity !");
      Serial.println("Humidity: ");
      Serial.println(humValue);
      Serial.println("Temperature: ");
      Serial.println(temperature);
    }
  }
  

  
  
 
  delay(2000); // Wait for 2000 millisecond(s)
}
