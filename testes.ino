unsigned long Teste() {
  tempoEmit = millis();
  socket.emit("/post/dispositivo/", "teste de tempo de envio e recebimento");
}

unsigned long CalculaTempo() {
  unsigned long tempo
  if (tempoEmit > tempoDebug) {
    tempo = tempoDebug - tempoEmit;
    Serial.print("\n\nTempo de conexão até retorno: ");
    Serial.println(tempo);
  }
  else if (tempoConexao > tempoDebug) {
    tempo = tempoDebug - tempoConexao;
    Serial.print("\n\nTempo de teste: ");
    Serial.println(tempo);
  }
}

