#include <TelnetStream.h>
#include "./Telnet.h"

Telnet::Telnet()
{
}

void Telnet::begin()
{
  TelnetStream.begin();
}

size_t Telnet::print(const __FlashStringHelper *ifsh)
{
  return TelnetStream.print(ifsh);
}

size_t Telnet::print(const String &s)
{
  return TelnetStream.print(s);
}

size_t Telnet::print(const char str[])
{
  return TelnetStream.print(str);
}

size_t Telnet::print(char c)
{
  return TelnetStream.print(c);
}

size_t Telnet::print(unsigned char b, int base)
{
  return TelnetStream.print(b, base);
}

size_t Telnet::print(int n, int base)
{
  return TelnetStream.print(n, base);
}

size_t Telnet::print(unsigned int n, int base)
{
  return TelnetStream.print(n, base);
}

size_t Telnet::print(long n, int base)
{
  return TelnetStream.print(n, base);
}

size_t Telnet::print(unsigned long n, int base)
{
  return TelnetStream.print(n, base);
}

size_t Telnet::print(long long n, int base)
{
  return TelnetStream.print(n, base);
}

size_t Telnet::print(unsigned long long n, int base)
{
  return TelnetStream.print(n, base);
}

size_t Telnet::print(double n, int digits)
{
  return TelnetStream.print(n, digits);
}

size_t Telnet::println()
{
  return TelnetStream.println();
}

size_t Telnet::println(const __FlashStringHelper *ifsh)
{
  return TelnetStream.println(ifsh);
}

size_t Telnet::println(const String &s)
{
  return TelnetStream.println(s);
}

size_t Telnet::println(const char c[])
{
  return TelnetStream.println(c);
}

size_t Telnet::println(char c)
{
  return TelnetStream.println(c);
}

size_t Telnet::println(unsigned char b, int base)
{
  return TelnetStream.println(b, base);
}

size_t Telnet::println(int num, int base)
{
  return TelnetStream.println(num, base);
}

size_t Telnet::println(unsigned int num, int base)
{
  return TelnetStream.println(num, base);
}

size_t Telnet::println(long num, int base)
{
  return TelnetStream.println(num, base);
}

size_t Telnet::println(unsigned long num, int base)
{
  return TelnetStream.println(num, base);
}

size_t Telnet::println(long long num, int base)
{
  return TelnetStream.println(num, base);
}

size_t Telnet::println(unsigned long long num, int base)
{
  return TelnetStream.println(num, base);
}

size_t Telnet::println(double num, int digits)
{
  return TelnetStream.println(num, digits);
}

void Telnet::flush()
{
  TelnetStream.flush();
}

void Telnet::handle()
{
  switch (TelnetStream.read())
  {
  case 'r':
    TelnetStream.println(F("RESET"));
    TelnetStream.stop();
    delay(100);
    ESP.reset();
    break;
  case 'q':
    TelnetStream.println("bye bye");
    TelnetStream.flush();
    TelnetStream.stop();
    break;
  }
}
