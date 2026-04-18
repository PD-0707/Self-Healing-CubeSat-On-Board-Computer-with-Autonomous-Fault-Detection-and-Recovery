#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

// ================== LORA PINS ==================
#define NSS   5
#define RST   14
#define DIO0  26

// ================== STRUCT ==================
struct __attribute__((packed)) Telemetry {
  uint32_t timestamp;
  float    voltage;
  float    temperature;
  float    stability;
  float    gyro;
  uint8_t  faults;
  uint8_t  mode;
};
// sizeof = 22 bytes

Telemetry data;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Base Station RX Starting...");

  Serial.print("Struct size RX: ");
  Serial.println(sizeof(Telemetry)); // must print 22

  SPI.begin(18, 19, 23, NSS);
  LoRa.setPins(NSS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
    while (1);
  }
  Serial.println("LoRa Initialized");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (!packetSize) return;

  if (packetSize == sizeof(Telemetry)) {
    LoRa.readBytes((uint8_t*)&data, sizeof(data));

    Serial.println("\n--- Packet Received ---");
    Serial.print("Time:        "); Serial.println(data.timestamp);
    Serial.print("Voltage:     "); Serial.print(data.voltage);     Serial.println(" V");
    Serial.print("Temperature: "); Serial.print(data.temperature); Serial.println(" C");
    Serial.print("Stability:   "); Serial.println(data.stability);
    Serial.print("Gyro:        "); Serial.println(data.gyro);
    Serial.print("Faults:      0x"); Serial.println(data.faults, HEX);

    // ── FIX: digit first so HTML parser regex /Mode:\s*(\d)/ can match ──
    Serial.print("Mode:        ");
    if      (data.mode == 0) Serial.println("0 (NORMAL)");
    else if (data.mode == 1) Serial.println("1 (SAFE)");
    else if (data.mode == 2) Serial.println("2 (CRITICAL)");
    else                     Serial.println("3 (UNKNOWN)");

    Serial.print("RSSI:        "); Serial.println(LoRa.packetRssi());

  } else {
    Serial.print("Size mismatch! Got: ");
    Serial.print(packetSize);
    Serial.print("  Expected: ");
    Serial.println(sizeof(Telemetry));
    while (LoRa.available()) LoRa.read(); // flush
  }
}