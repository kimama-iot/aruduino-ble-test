//device:arduino nano every
String tempString;
int temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial1.println("+"); //エコーオン
  Serial1.println("SF,1"); //factory reset
  Serial1.println("SS,90000000"); //サービス設定
  Serial1.println("SR,32000000"); //ペリフェラルかつ自動アドバタイズ
  Serial1.println("R,1"); //再起動
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  readTemperature(); //センサーから温度測定
  tempString = String(temperature); //温度を文字に変換
  Serial1.println("SUW,2A25,"+tempString); //RN4020へ温度を書き込み
  delay(1000);
}

void readTemperature() {
   int ans , tv ;
   ans = analogRead(0) ;              // アナログ０番ピンからセンサー値を読込む
   tv  = map(ans,0,1023,0,5000) ;     // センサー値を電圧に変換する
   temperature = map(tv,300,1600,-30,100) ;  // 電圧から温度に変換する
   Serial.println(temperature) ;             // 値をパソコン(ＩＤＥ)に送る
}
