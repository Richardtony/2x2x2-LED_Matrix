#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
int Layer[] = {14, 2};
int rows_columns[] = {16, 5, 0, 4};
int Layer_len = sizeof(Layer) / sizeof(int);
int rows_columns_len = sizeof(rows_columns) / sizeof(int);

WiFiClient client;
unsigned long channelNumber = 1352466;
const char * ReadAPIKey = "6T4T32FBVEZQWDM5";
const int FieldNumber1 = 1;


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < Layer_len; i++) {
    pinMode(Layer[i], OUTPUT);
  }
  for (int j = 0; j < rows_columns_len; j++) {
    pinMode(rows_columns[j], OUTPUT);
  }
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("tony", "NNFHTP7TE3");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected, IP Address: ");
  Serial.print(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  int A = ThingSpeak.readLongField(channelNumber , FieldNumber1, ReadAPIKey);
  Serial.println(A);
  //Turn ON all the LED's//
  if (A == 1) {
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], HIGH);
    }
    for (int j = 0; j < rows_columns_len; j++) {
      digitalWrite(rows_columns[j], LOW);
    }
  }
  //Turn OFF all the LED's//
  else if (A == 0) {
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], LOW);
    }
    for (int j = 0; j < rows_columns_len; j++) {
      digitalWrite(rows_columns[j], LOW);
    }
  }
  
  //Turn ON layer 1 of the Matrix//
  else if (A == 2) {
    digitalWrite(Layer[0], HIGH);
    digitalWrite(Layer[1], LOW);
    for (int j = 0; j < rows_columns_len; j++) {
      digitalWrite(rows_columns[j], LOW);
    }
  }
  
  //Turn ON layer 2 of the Matrix//
  else if (A == 3) {
    digitalWrite(Layer[1], HIGH);
    digitalWrite(Layer[0], LOW);
    for (int j = 0; j < rows_columns_len; j++) {
      digitalWrite(rows_columns[j], LOW);
    }
  }

  //SEQUENCE 1//
  else if (A == 4) {
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], HIGH);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], LOW);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
  }

  //SEQUENCE 2//
  else if (A == 5) {
    for (int i = Layer_len - 1; i >= 0; i--) {
      digitalWrite(Layer[i], HIGH);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
    for (int i = Layer_len - 1; i >= 0; i--) {
      digitalWrite(Layer[i], LOW);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
  }

  //SEQUENCE 3//
  else if (A == 6) {
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], HIGH);
    }
    for (int j = 0; j < rows_columns_len; j++) {
      digitalWrite(rows_columns[j], LOW);
    }
    delay(100);
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], HIGH);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], LOW);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
  }

  //SEQUENCE 4//
  else if (A == 7) {
    for (int i = 0; i < Layer_len; i++) {
      digitalWrite(Layer[i], HIGH);
    }
    for (int j = 0; j < rows_columns_len; j++) {
      digitalWrite(rows_columns[j], LOW);
    }
    delay(100);
    for (int i = Layer_len - 1; i >= 0; i--) {
      digitalWrite(Layer[i], HIGH);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
    for (int i = Layer_len - 1; i >= 0; i--) {
      digitalWrite(Layer[i], LOW);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(100);
      }
    }
  }

  //SEQUENCE 5//
  else if (A == 8) {
    for (int i = Layer_len - 1; i >= 0; i--) {
      digitalWrite(Layer[i], HIGH);
      for (int j = 0; j < rows_columns_len; j++) {
        digitalWrite(rows_columns[j], LOW);
        delay(500);
        digitalWrite(rows_columns[j],HIGH);
        delay(500);
      }
      digitalWrite(Layer[i], LOW);
    }
  }
}
