int led = D7;
#define VD_N D3
#define VD_P D4

void VD_LOOP()
{
long int j;
 
// Прикладываем обратное напряжение 
// это зарядит собственную емкость вывода 2
pinMode(VD_N, OUTPUT);
pinMode(VD_P, OUTPUT);
digitalWrite(VD_N, HIGH);
digitalWrite(VD_P, LOW);
 
pinMode(VD_N, INPUT); 
// Переключаем 2й вывод на вход

digitalWrite(VD_N, LOW); 
// и отключаем на нем подтягивающий резистор
 
// Считаем сколько времени потребуется, 
// чтобы емкость разрядилась до логич. 0
for ( j = 0; j < 128000; j++) 
{
if (digitalRead(VD_N)==0) break;
}
 
Serial.println(j); 
// Выводим значение счетчика в COM-порт

delay(100); 
// Пауза, чтобы не переполнять буфер COM-порта

if(j<4000)
digitalWrite(led,HIGH);
else
digitalWrite(led,LOW);
}