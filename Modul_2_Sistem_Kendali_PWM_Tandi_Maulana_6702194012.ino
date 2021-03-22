  //KELOMPOK TADIKA MESRA
  //Tandi Maulana - 6702194012

  //Inisialisasi sensor
  int sensor1 = A0;
  int sensor2 = A1;
  int sensor3 = A2;
  int sensor4 = A3;
  int sensor5 = A4;
  int sensor6 = A5;
  int baca_sensor[6];
  
  //Inisialisasi pin output
  int pinEnable = 4;
  int pinEnable2 = 2;
  
  //Inisialisasi motor kiri
  int motor_kiri1 = 5;
  int motor_kiri2 = 6;
  
  //Inisialisasi motor kanan
  int motor_kanan1 = 3;
  int motor_kanan2 = 11;
  
  //Deteksi error
  int error = 0;
  
  //Bagian setup pin
  void setup()
  {
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);
    pinMode(sensor5, INPUT);
    pinMode(sensor6, INPUT);
  
    pinMode(pinEnable, OUTPUT);
    pinMode(pinEnable2, OUTPUT);
    pinMode(motor_kiri1, OUTPUT);
    pinMode(motor_kiri2, OUTPUT);
    pinMode(motor_kanan1, OUTPUT);
    pinMode(motor_kanan2, OUTPUT);
    Serial.begin(9600);
  }
  
  //Bagian membaca sensor
  void readsensor(){
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  delay(500);
    
    for(int i=0; i<=5; i++){
      Serial.print("Sensor ");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(baca_sensor[i]);
      Serial.print("\n");
    }
  }
  //Bagian program
  void loop(){
  readsensor();
  
    Serial.print("Nilai Deteksi Error : ");
    Serial.println(error);
  
  //Jika sensor 1 dan 2 mendeteksi gelap, Duty cycle 0% motor kiri, 50% motor kanan
  if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){
  digitalWrite (pinEnable, HIGH);
  digitalWrite (pinEnable2, HIGH);
  analogWrite (motor_kiri1, 0);
  analogWrite (motor_kiri2, 0);
  analogWrite (motor_kanan1, 0.5*255);
  analogWrite (motor_kanan2, 0);
  }
  
  //Jika sensor 2 dan 3 mendeteksi gelap, Duty cycle 20% motor kiri, 50% motor kanan
  if (baca_sensor[0] > 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34){
  digitalWrite (pinEnable, HIGH);
  digitalWrite (pinEnable2, HIGH);
  analogWrite (motor_kiri1, 0.2*255);
  analogWrite (motor_kiri2, 0);
  analogWrite (motor_kanan1, 0.5*255);
  analogWrite (motor_kanan2, 0);
  }
  
  //Jika sensor 3 dan 4 mendeteksi gelap, Duty cycle 60% pada kedua motor
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && baca_sensor[2] < 34 && baca_sensor[3] < 34 && baca_sensor[4] > 34 && baca_sensor[5] > 34){
  digitalWrite (pinEnable, HIGH);
  digitalWrite (pinEnable2, HIGH);
  analogWrite (motor_kiri1, 0.6*255);
  analogWrite (motor_kiri2, 0);
  analogWrite (motor_kanan1, 0.6*255);
  analogWrite (motor_kanan2, 0);
  }
  
  //Jika sensor 4 dan 5, Duty cycle 50% motor kiri, 20% motor kanan
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && baca_sensor[2] > 34 && baca_sensor[3] < 34 && baca_sensor[4] < 34 && baca_sensor[5] > 34){
  digitalWrite (pinEnable, HIGH);
  digitalWrite (pinEnable2, HIGH);
  analogWrite (motor_kiri1, 0.5*255);
  analogWrite (motor_kiri2, 0);
  analogWrite (motor_kanan1, 0.2*255);
  analogWrite (motor_kanan2, 0);
  }
  
  //Jika sensor 5 dan 6, Duty cycle 50% Motor kiri, 0% motor kanan
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && baca_sensor[2] > 34 && baca_sensor[3] > 34 && baca_sensor[4] < 34 && baca_sensor[5] < 34){
  digitalWrite (pinEnable, HIGH);
  digitalWrite (pinEnable2, HIGH);
  analogWrite (motor_kiri1, 0.5*255);
  analogWrite (motor_kiri2, 0);
  analogWrite (motor_kanan1, 0);
  analogWrite (motor_kanan2, 0);
  }
  
  //Jika semua sensor mendeteksi gelap, Duty cycle kedua motor 0% (semua motor mati)
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && baca_sensor[2] > 34 && baca_sensor[3] > 34 && baca_sensor[4] > 34 && baca_sensor[5] > 34){
  digitalWrite (pinEnable, HIGH);
  digitalWrite (pinEnable2, HIGH);
  analogWrite (motor_kiri1, 0);
  analogWrite (motor_kiri2, 0);
  analogWrite (motor_kanan1, 0);
  analogWrite (motor_kanan2, 0);
  }
  }
