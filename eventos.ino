void Atuar(String state) {
  int intensidade = state.toInt();
  if (intensidade == 1) {
    Serial.println("A lampada ligou!");
    analogWrite(luz, HIGH);
  }
  else if (intensidade == 0) {
    Serial.println("Desligado");
    analogWrite(luz, LOW);
  }
  else if (intensidade > 0 && intensidade < 256) {
    Serial.println("A lampada ligou intensidade maior");
    analogWrite(luz, intensidade);
  }
  Serial.print("Valor atual da lampada: " + state);
}

void Debug(String state) {
  tempoDebug = millis();
  Serial.print(tempoDebug);
  Serial.print("debug -- " + state);
  Serial.print("\n" );
  CalculaTempo();
}

void Estado(String state) {
  socket.emit("estado", "{ \"serial\": \"lampada001\", \"valor\": 200 }");
}

void Valor(String state) {
  socket.emit("valor", "10");
}
