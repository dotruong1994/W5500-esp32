void handleData(ModbusMessage response, uint32_t token) 
{
  Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
  Serial.println(response);
  for (auto& byte : response) {
    Serial.printf("%02X ", byte);
  }
  content1 = response[5];
  content2 = response[6];
  sendContent = "["+content1 + "," + content2+"]";
  Serial.println(sendContent);
}

// Define an onError handler function to receive error responses
// Arguments are the error code returned and a user-supplied token to identify the causing request
void handleError(Error error, uint32_t token) 
{
  // ModbusError wraps the error code and provides a readable error message for it
  ModbusError me(error);
  Serial.printf("Error response: %02X - %s\n", (int)me, (const char *)me);
}
