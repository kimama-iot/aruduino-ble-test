//device:arduino nano every
String tempString;
int temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial1.println("+"); //エコーオン
  Serial1.println("SF,1"); //工場出荷時にリセット
  Serial1.println("SS,10000000"); //サービス設定
  Serial1.println("SR,92000000"); //セントラルかつ自動アドバタイズ設定
  Serial1.println("R,1"); //再起動
  delay(1000);
  Serial1.println("E,0,608A107D02BC"); //ペリフェラルと接続
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial1.println("CURV,2A25,0"); //センサーの温度を読み取り
  if ( Serial1.available() ) {
    tempString = Serial1.readStringUntil("\n");
    tempString = tempString.substring(2,4).toInt();
    Serial.println("現在の温度は "+tempString+" 度です");
  }
  delay(1000);
}
