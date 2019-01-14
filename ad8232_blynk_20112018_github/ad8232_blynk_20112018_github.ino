#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// Deberías obtener el token de autenticación en la aplicación Blynk.
// Ir a la configuración del proyecto.

char auth[] = "xxxxxxxxxxxxxxxxxxxxxx";



char ssid[] = "xxxxxxxxxxxx";            // Nombre de la red WiFi.
char pass[] = "xxxxxxxxxxxx";                         // Establezca la contraseña en "" para redes abiertas.

#define ANALOGIN A0          // a qué pin digital estamos conectados



BlynkTimer timer;

// Esta función envía el tiempo de actividad de Arduino cada segundo a Virtual Pin (5).
// En la aplicación, la frecuencia de lectura del Widget se debe establecer en PUSH. Esto significa
// que define con qué frecuencia enviar datos a la aplicación Blynk.
void sendSensor()
{
  
  int h = analogRead(A0)/10;  
  


    // Puedes enviar cualquier valor en cualquier momento.
     // Por favor, no envíe más de 10 valores por segundo.
  Blynk.virtualWrite(V5, h);

  
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // También puede especificar el servidor:
   //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
   //Blynk.begin(auth, ssid, pass, IPAddress (192,168,1,100), 8442);


 // Configurar una función para ser llamada cada segundo
  timer.setInterval(100L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}

