#include <iostream>
#include <cmath>
using namespace std;

class Punto
{
  // no hay constructor, usar el predeterminado
  public:
    void AsignarX( float x ) { suX = x; }
    void AsignarY( float y ) { suY = y; }
    float ObtenerX() const { return suX; }
    float ObtenerY() const { return suY; }
  private:
    float suX;
    float suY;
    // fin de la declaracion de la clase Punto
};

class Decagono {
public:
  Decagono(float x, float y, float r);
  ~Decagono() {}

  Punto ObtenerD0() const { return d0; }
  Punto ObtenerD1() const { return d1; }
  Punto ObtenerD2() const { return d2; }
  Punto ObtenerD3() const { return d3; }
  Punto ObtenerD4() const { return d4; }
  Punto ObtenerD5() const { return d5; }
  Punto ObtenerD6() const { return d6; }
  Punto ObtenerD7() const { return d7; }
  Punto ObtenerD8() const { return d8; }
  Punto ObtenerD9() const { return d9; }

  void AsignarD0(Punto Ubicacion) { d0 = Ubicacion; }
  void AsignarD1(Punto Ubicacion) { d1 = Ubicacion; }
  void AsignarD2(Punto Ubicacion) { d2 = Ubicacion; }
  void AsignarD3(Punto Ubicacion) { d3 = Ubicacion; }
  void AsignarD4(Punto Ubicacion) { d4 = Ubicacion; }
  void AsignarD5(Punto Ubicacion) { d5 = Ubicacion; }
  void AsignarD6(Punto Ubicacion) { d6 = Ubicacion; }
  void AsignarD7(Punto Ubicacion) { d7 = Ubicacion; }
  void AsignarD8(Punto Ubicacion) { d8 = Ubicacion; }
  void AsignarD9(Punto Ubicacion) { d9 = Ubicacion; }

  Punto ObtenerCentro() const { return centro; }
  void AsignarCentro(Punto Ubicacion) { centro = Ubicacion; }

  int ObtenerLado() const { return lado; }
  int ObtenerApotema() const { return apotema; }

  void AsignarLado(int _lado) { lado = _lado; }
  void AsignarApotema(int _apotema) { apotema = _apotema; }

  Punto centro;
  Punto d0;
  Punto d1;
  Punto d2;
  Punto d3;
  Punto d4;
  Punto d5;
  Punto d6;
  Punto d7;
  Punto d8;
  Punto d9;
  int lado;
  int apotema;
};