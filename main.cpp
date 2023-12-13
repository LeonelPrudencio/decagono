#include "decagono.cpp"
#include <fstream>
#include <cstdlib>
#include <cmath>

float DefineX(float x0, float m1, float m2, float rad) {
  return x0 - (m2 / (m1 - m2)) * rad;
}

float DefineY(float x0, float y0, float m1, float m2, float rad) {
  return m1 * (x0 - (m2 / (m1 - m2)) * rad) - m1 * x0 + y0;
}

//Este es el primer constructor
Decagono::Decagono(float _x, float _y, float _r)
{

//Lo primero asignar las coordenadas del centro
  centro.AsignarX(_x);
  centro.AsignarY(_y);
  float pi=3.1416;

//Ahora asignar las coordenadas de cada punto

  d0.AsignarX(_x+_r);
  d0.AsignarY(_y);

  d1.AsignarX(DefineX(_x,tan(0.2*pi),-tan(0.4*pi),_r));
  d1.AsignarY(DefineY(_x,_y,tan(0.2*pi),-tan(0.4*pi),_r));

  d2.AsignarX(DefineX(_x,tan(0.4*pi),-tan(0.3*pi),_r));
  d2.AsignarY(DefineY(_x,_y,tan(0.4*pi),-tan(0.3*pi),_r));

  d3.AsignarX(DefineX(_x,-tan(0.4*pi),-tan(0.2*pi),_r));
  d3.AsignarY(d2.ObtenerY());

  d4.AsignarX(DefineX(_x,-tan(0.2*pi),-tan(0.1*pi),_r));
  d4.AsignarY(d1.ObtenerY());

  d5.AsignarX(_x-_r);
  d5.AsignarY(_y);

  d6.AsignarX(d4.ObtenerX());
  d6.AsignarY(DefineY(_x,_y,tan(0.2*pi),tan(0.1*pi),_r));

  d7.AsignarX(d3.ObtenerX());
  d7.AsignarY(DefineY(_x,_y,tan(0.4*pi),tan(0.2*pi),_r));

  d8.AsignarX(d2.ObtenerX());
  d8.AsignarY(d7.ObtenerY());

  d9.AsignarX(d1.ObtenerX());
  d9.AsignarY(d6.ObtenerY());
}


int main()
{
   // inicializar una variable Decagono local
  // las primeras dos coordenadas son del centro y la ultima del radio de un circulo que circunscriba el decagono
   Decagono MiDecagono(-1,-4,2);

   cout << "Centro: (" << MiDecagono.centro.ObtenerX() <<" ,"<< MiDecagono.centro.ObtenerY() << ")\n";
   cout << "Punto 0: ("<< MiDecagono.d0.ObtenerX() <<" ,"<< MiDecagono.d0.ObtenerY() << ")\n";
   cout << "Punto 1: ("<< MiDecagono.d1.ObtenerX() <<" ,"<< MiDecagono.d1.ObtenerY() << ")\n";
   cout << "Punto 2: ("<< MiDecagono.d2.ObtenerX() <<" ,"<< MiDecagono.d2.ObtenerY() << ")\n";
   cout << "Punto 3: ("<< MiDecagono.d3.ObtenerX() <<" ,"<< MiDecagono.d3.ObtenerY() << ")\n";
   cout << "Punto 4: ("<< MiDecagono.d4.ObtenerX() <<" ,"<< MiDecagono.d4.ObtenerY() << ")\n";
   cout << "Punto 5: ("<< MiDecagono.d5.ObtenerX() <<" ,"<< MiDecagono.d5.ObtenerY() << ")\n";
   cout << "Punto 6: ("<< MiDecagono.d6.ObtenerX() <<" ,"<< MiDecagono.d6.ObtenerY() << ")\n";
   cout << "Punto 7: ("<< MiDecagono.d7.ObtenerX() <<" ,"<< MiDecagono.d7.ObtenerY() << ")\n";
   cout << "Punto 8: ("<< MiDecagono.d8.ObtenerX() <<" ,"<< MiDecagono.d8.ObtenerY() << ")\n";
   cout << "Punto 9: ("<< MiDecagono.d9.ObtenerX() <<" ,"<< MiDecagono.d9.ObtenerY() << ")\n";

  // Abre un archivo para escribir
  std::ofstream archivo("puntos_decagono.txt");

  // Verifica si el archivo se abrió correctamente
  if (archivo.is_open()) {
      // Escribe datos en el archivo
      archivo <<  MiDecagono.d0.ObtenerX() <<" ,"<< MiDecagono.d0.ObtenerY() << "\n";
      archivo <<  MiDecagono.d1.ObtenerX() <<" ,"<< MiDecagono.d1.ObtenerY() << "\n";
      archivo <<  MiDecagono.d2.ObtenerX() <<" ,"<< MiDecagono.d2.ObtenerY() << "\n";
    archivo <<  MiDecagono.d3.ObtenerX() <<" ,"<< MiDecagono.d3.ObtenerY() << "\n";
    archivo <<  MiDecagono.d4.ObtenerX() <<" ,"<< MiDecagono.d4.ObtenerY() << "\n";
    archivo <<  MiDecagono.d5.ObtenerX() <<" ,"<< MiDecagono.d5.ObtenerY() << "\n";
    archivo <<  MiDecagono.d6.ObtenerX() <<" ,"<< MiDecagono.d6.ObtenerY() << "\n";
    archivo <<  MiDecagono.d7.ObtenerX() <<" ,"<< MiDecagono.d7.ObtenerY() << "\n";
    archivo <<  MiDecagono.d8.ObtenerX() <<" ,"<< MiDecagono.d8.ObtenerY() << "\n";
    archivo <<  MiDecagono.d9.ObtenerX() <<" ,"<< MiDecagono.d9.ObtenerY() << "\n";


      // Cierra el archivo
      archivo.close();
      std::cout << "Archivo txt generado exitosamente.\n";
  } else {
      // Muestra un mensaje de error si no se pudo abrir el archivo
      std::cerr << "Error al abrir el archivo.\n";
  }

  // Ejecuta el script de R desde C++
  int resultado = system("Rscript dibujo.R");

  // Verifica el resultado
  if (resultado == 0) {
      // Éxito
      return 0;
  } else {
      // Algo salió mal
      return 1;
  }

}