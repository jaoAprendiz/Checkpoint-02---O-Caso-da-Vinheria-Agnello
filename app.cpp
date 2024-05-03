// Incluindo as bibliotecas necessárias para o projeto
#include <DHT.h> // Biblioteca para o sensor de temperatura e umidade DHT
#include <LiquidCrystal.h> // Biblioteca para o display LCD
#include <Wire.h> // Biblioteca para comunicação I2C
#include <Adafruit_RGBLCDShield.h> // Biblioteca para o shield LCD RGB da Adafruit
#include <utility/Adafruit_MCP23017.h> // Utilitário para o MCP23017

// Definição dos pinos de conexão do sensor DHT e o tipo do sensor
#define DHTPIN 8 // Pino conectado ao sensor DHT
#define DHTTYPE DHT22 // Tipo do sensor DHT (DHT22 neste caso)

// Inicialização do objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// Inicialização do objeto LCD com os pinos necessários
LiquidCrystal lcd(7, 11, 6, 5, 4, 3, 2); // Pinos RS, Enable, D4, D5, D6, D7

// Definição dos pinos para o buzzer, LEDs e LDR
int buzzer = 9; // Pino conectado ao buzzer
int ledVermelho = 10; // Pino conectado ao LED vermelho
int ledAmarelo = 12; // Pino conectado ao LED amarelo
int ledVerde = 13; // Pino conectado ao LED verde
int ldr = A0; // Pino de entrada analógica conectado ao LDR
int valorLdr = 0; // Variável para armazenar a leitura do LDR

// Definição de constantes para os pinos do LED amarelo, buzzer e valores de temperatura mínima e máxima aceitáveis
const int yellowLedPin = 3; // Pino conectado ao LED amarelo (já definido anteriormente)
const int buzzerPin = 4; // Pino conectado ao buzzer (já definido anteriormente)
const int TEMPERATURE_OK_MIN = 10; // Temperatura mínima aceitável
const int TEMPERATURE_OK_MAX = 15; // Temperatura máxima aceitável
const int NUM_READINGS = 5; // Número de leituras para calcular a média

// Variáveis para o cálculo da média da temperatura (já definidas anteriormente)
int currentIndex = 0;
float averageTemperature = 0;
float averageTemperatureF = 0;


// Caracteres personalizados
byte name1x6[] = { B10110, B10110, B10110, B10110, B11111, B01101, B00101, B00111 };
byte name0x5[] = { B00001, B00001, B00010, B00010, B00010, B00010, B00010, B00010 };
byte name0x6[] = { B11111, B10010, B10010, B10010, B10010, B10010, B10010, B10110 };
byte name0x7[] = { B11111, B00000, B11111, B11111, B11111, B11101, B11101, B11111 };
byte name0x8[] = { B11111, B00000, B11111, B11111, B11111, B11011, B11011, B11111 };
byte name0x9[] = { B11000, B01000, B01000, B01000, B01000, B01000, B01000, B01111 };
byte name0x10[] = { B00000, B00000, B00000, B00000, B00000, B10000, B11000, B11000 };
byte name1x5[] = { B00010, B00010, B00010, B00001, B00000, B00000, B00000, B00000 };
byte name1x7[] = { B11101, B11110, B11111, B00000, B11111, B00000, B00000, B00000 };
byte name1x8[] = { B11101, B00011, B11111, B00000, B11111, B00101, B00101, B00111 };
byte name1x9[] = { B01000, B01000, B01000, B01000, B11000, B00000, B00000, B00000 };
byte name1x10[] = { B11000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };

void setup() {
  // Inicialização do display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);
  
  // Define caracteres personalizados no display LCD
  lcd.createChar(3, name0x7); // Cria um caractere personalizado na posição 3
  lcd.createChar(4, name0x5); // Cria um caractere personalizado na posição 4
  lcd.createChar(5, name0x6); // Cria um caractere personalizado na posição 5
  lcd.createChar(6, name0x8); // Cria um caractere personalizado na posição 6
  lcd.createChar(7, name0x9); // Cria um caractere personalizado na posição 7
  lcd.createChar(8, name1x5); // Cria um caractere personalizado na posição 8
  lcd.createChar(9, name1x6); // Cria um caractere personalizado na posição 9
  lcd.createChar(10, name1x7); // Cria um caractere personalizado na posição 10
  lcd.createChar(11, name1x8); // Cria um caractere personalizado na posição 11
  lcd.createChar(12, name1x9); // Cria um caractere personalizado na posição 12
  
  // Inicialização da comunicação serial com baud rate de 9600
  Serial.begin(9600);
  
  // Inicialização do sensor DHT
  dht.begin();
  
  // Configuração dos pinos como entrada ou saída
  pinMode(A1, INPUT); // Pino A1 como entrada
  pinMode(ldr, INPUT); // Pino LDR (analógico A0) como entrada
  pinMode(buzzer, OUTPUT); // Pino buzzer como saída
  pinMode(ledVermelho, OUTPUT); // Pino LED vermelho como saída
  pinMode(ledAmarelo, OUTPUT); // Pino LED amarelo como saída
  pinMode(ledVerde, OUTPUT); // Pino LED verde como saída
  
  // Limpa o display LCD e posiciona o cursor na coluna 1, linha 0
  lcd.clear();
  lcd.setCursor(1, 0);
    
  // Exibe uma mensagem no display LCD (Nome da Empresa)
  lcd.print("Edge Solution!");
  delay(2000); // Aguarda 2 segundos
  
  // Limpa o display LCD
  lcd.clear();

  // Exibe um logo no display LCD
  ExibeLogo();
  delay(2000); // Aguarda 2 segundos
}

void loop() {
  int cont = 1; // Inicializa o contador em 1
  int somaValorLdr = 0; // Inicializa a variável de soma do valor do LDR

  // Loop para fazer 10 leituras do sensor LDR e calcular a soma dos valores
  while (cont <= 10) {
    valorLdr = analogRead(ldr); // Lê o valor do sensor LDR e armazena em valorLdr
    Serial.print("Valor do LDR = "); // Imprime o valor do LDR no monitor serial
    Serial.println(valorLdr);
    somaValorLdr = somaValorLdr + valorLdr; // Adiciona o valor do LDR à soma
    Serial.print("Valor da soma dos LDRs = "); // Imprime a soma dos valores do LDR no monitor serial
    Serial.println(somaValorLdr);
    cont ++; // Incrementa o contador
  }
  
  int mediaLdr = somaValorLdr / 10; // Calcula a média dos valores do LDR
  Serial.println("Media dos valores LDR = "); // Imprime a média dos valores do LDR no monitor serial
  Serial.println(mediaLdr);
  int l = map(mediaLdr, 974, 54, 0, 100); // Mapeia o valor do LDR para uma escala de 0 a 100
  Serial.print("Valor de L = "); // Imprime o valor de L no monitor serial
  Serial.println(l);
  
  // Verifica o nível de luminosidade e aciona os LEDs correspondentes
  if (l <= 30) { // Se a luminosidade for baixa (menor ou igual a 30%)
    apagarLeds(); // Apaga todos os LEDs
    digitalWrite(ledVerde, HIGH); // Acende o LED verde
  } 
  else if (l > 30 && l <= 60) { // Se a luminosidade for média (entre 30% e 60%)
    apagarLeds(); // Apaga todos os LEDs
    digitalWrite(ledAmarelo, HIGH); // Acende o LED amarelo
  } 
  else { // Se a luminosidade for alta (maior que 60%)
    apagarLeds(); // Apaga todos os LEDs
    digitalWrite(ledVermelho, HIGH); // Acende o LED vermelho
    tone(buzzer, 1000); // Ativa o buzzer com uma frequência de 1000Hz
    delay(3000); // Mantém o som do buzzer por 3 segundos
    noTone(buzzer); // Desliga o buzzer
    delay(2000); // Aguarda 2 segundos antes de continuar
  }

  // Leitura da temperatura e umidade utilizando a biblioteca DHT
  int tempC = dht.readTemperature(); // Lê a temperatura em Celsius
  int tempF = (tempC * 9/5) + 32; // Converte a temperatura para Fahrenheit
  float humidade = dht.readHumidity(); // Lê a umidade

  int sum = 0; // Variável para somar as temperaturas em Celsius
  int sumF = 0; // Variável para somar as temperaturas em Fahrenheit

  // Loop para realizar 5 leituras da temperatura
  for (int i = 0; i < NUM_READINGS; i++) {
    // Verifica se a leitura da temperatura ou umidade é inválida (NaN)
    if (isnan(tempC) || isnan(humidade)) {
      Serial.println("\n ERRO..."); // Imprime mensagem de erro no monitor serial
      Serial.println(i); // Imprime o número da leitura com erro
      continue; // Pula para a próxima iteração do loop
    }
    sum += tempC; // Adiciona a temperatura em Celsius à soma
    sumF += tempF; // Adiciona a temperatura em Fahrenheit à soma

    averageTemperature = sum / NUM_READINGS; // Calcula a temperatura média em Celsius
    averageTemperatureF = sumF / NUM_READINGS; // Calcula a temperatura média em Fahrenheit
  }
      
  displayTemperatureStatus(averageTemperature, averageTemperatureF); // Chama a função para exibir o status da temperatura no display
}


void apagarLeds() { // Função para apagar todos os leds
  digitalWrite(ledVermelho, LOW); // Desliga o LED vermelho
  digitalWrite(ledAmarelo, LOW); // Desliga o LED amarelo
  digitalWrite(ledVerde, LOW); // Desliga o LED verde
}

void displayTemperatureStatus(int temperature, int temperatureF) {
  lcd.clear(); // Limpa o display LCD

  float humidade = dht.readHumidity(); // Lê a umidade
  
  // Verifica se a temperatura está dentro da faixa aceitável
  if (temperature >= TEMPERATURE_OK_MIN && temperature <= TEMPERATURE_OK_MAX) {
    // Exibe "Temperatura OK" no display
    lcd.setCursor(0, 0);
    lcd.print("Temperatura OK");
    lcd.setCursor(3, 1);
    lcd.print(temperature);
    lcd.print("C");
    lcd.setCursor(9, 1);
    lcd.print(temperatureF);
    lcd.print("F");
    delay(1500); // Aguarda 1.5 segundos
    lcd.clear(); // Limpa o display
    
    // Exibe "Humidade OK" no display
    lcd.setCursor(0, 0);
    lcd.print("Humidade OK");
    lcd.setCursor(5, 1);
    lcd.print(humidade);
    lcd.print("%");
    delay(1500); // Aguarda 1.5 segundos
    lcd.clear(); // Limpa o display

    digitalWrite(yellowLedPin, LOW); // Desliga o LED amarelo
    noTone(buzzerPin); // Desliga o buzzer
    
    Serial.print("\n Temperatura OK: "); // Imprime no monitor serial que a temperatura está OK 
    Serial.print(temperature); // Imprime a temperatura em Celsius
    Serial.print("\n Humidade OK: "); // Imprime no monitor serial que a umidade está OK 
    Serial.print(humidade); // Imprime a umidade
  } 
  else {
    if (temperature > TEMPERATURE_OK_MAX) { // Se a temperatura estiver alta
      // Exibe "Temperatura Alta" no display
      lcd.setCursor(0, 0);
      lcd.print("Temperatura Alta");
      lcd.setCursor(3, 1);
      lcd.print(temperature);
      lcd.print("C");
      lcd.setCursor(9, 1);
      lcd.print(temperatureF);
      lcd.print("F");
      delay(1500); // Aguarda 1.5 segundos
      lcd.clear(); // Limpa o display
      
      // Exibe "Humidade Alta" no display
      lcd.setCursor(0, 0);
      lcd.print("Humidade Alta");
      lcd.setCursor(5, 1);
      lcd.print(humidade);
      lcd.print("%");
      delay(1500); // Aguarda 1.5 segundos
      lcd.clear(); // Limpa o display

      Serial.print("\n Temperatura Alta: "); // Imprime no monitor serial que a temperatura está alta
      Serial.print(temperature); // Imprime a temperatura em Celsius
      Serial.print("\n Humidade Alta: "); // Imprime no monitor serial que a umidade está alta
      Serial.print(humidade); // Imprime a umidade
      tone(buzzer, 1000); // Ativa o buzzer com uma frequência de 1000Hz
    } 
    else { // Se a temperatura estiver baixa
      // Exibe "Temperatura Baixa" no display
      lcd.setCursor(0, 0);
      lcd.print("Temp. Baixa");
      lcd.setCursor(3, 1);
      lcd.print(temperature);
      lcd.print("C");
      lcd.setCursor(9, 1);
      lcd.print(temperatureF);
      lcd.print("F");
      delay(1500); // Aguarda 1.5 segundos
      lcd.clear(); // Limpa o display
      
      // Exibe "Humidade Baixa" no display
      lcd.setCursor(0, 0);
      lcd.print("Humidade Baixa");
      lcd.setCursor(5, 1);
      lcd.print(humidade);
      lcd.print("%");
      delay(1500); // Aguarda 1.5 segundos
      lcd.clear(); // Limpa o display

      Serial.print("\n Temperatura Baixa: "); // Imprime no monitor serial que a temperatura está baixa
      Serial.print(temperature); // Imprime a temperatura em Celsius
      Serial.print("\n Humidade Baixa: "); // Imprime no monitor serial que a umidade está baixa
      Serial.print(humidade); // Imprime a umidade
      tone(buzzer, 1000); // Ativa o buzzer com uma frequência de 1000Hz
    }
  }
}


void ExibeLogo() {
 //Limpa o LCD e coloca o cursor na coluna 1, linha 0
  lcd.clear();
  lcd.setCursor(1, 0);
  
  //Exibe Logo
  lcd.setCursor(7, 0);  
  lcd.write(byte(3));
  
  lcd.setCursor(5, 0);  
  lcd.write(byte(4));

  lcd.setCursor(6, 0);  
  lcd.write(byte(5));

  lcd.setCursor(8, 0);  
  lcd.write(byte(6));
  
  lcd.setCursor(9, 0);  
  lcd.write(byte(7));
  
  lcd.setCursor(5, 1);  
  lcd.write(byte(8));
  
  lcd.setCursor(6, 1);  
  lcd.write(byte(9));
  
  lcd.setCursor(7, 1);  
  lcd.write(byte(10));
  
  lcd.setCursor(8, 1);  
  lcd.write(byte(11));
  
  lcd.setCursor(9, 1);  
  lcd.write(byte(12));
}