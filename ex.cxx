#include <iostream>
#include <vector>
using namespace std;

double mean(const vector<double>& v) {
    double suma = 0;
    for (double num : v) suma += num;
    return suma / v.size();
}

double variance(const vector<double>& v, double promedio) {
    double suma = 0;
    for (double num : v) suma += (num - promedio) * (num - promedio);
    return suma / v.size();
}

int main() {
    vector<double> numeros;
    int n;

    cout << "¿Cuántos números vas a ingresar? ";
    cin >> n;

    numeros.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    double prom = mean(numeros);
    double var = variance(numeros, prom);

    cout << "Promedio: " << prom << endl;
    cout << "Varianza: " << var << endl;

    return 0;
}




#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double mean(const vector<double>& v){
double suma = 0;
for (double num : v) suma += num;
  return suma / v.size();
}

double pearson_r(const vector<double>& A, const vector<double>& B) {
  double meanA = mean(A);
  double meanB = mean(B);

   double num = 0;
   double denA = 0;
   double denB = 0;

   for (int i = 0; i < A.size(); i++) {
     double diffA = A[i] - meanA;
     double diffB = B[i] - meanB;

   num += diffA * diffB;
   denA += diffA * diffA;
   denB += diffB * diffB;

}

return num / sqrt(denA * denB);

}
  
  int main() {

    int n;
    cout << "ingrese la cantidad de numeros: ";
    cin >> n;

    vector<double> A(n), B(n);

      for (int i = 0; i < n; i++) {
        cout << "ingrese el valor de A[" << i << "]: ";
        cin >> A[i];
        cout << "ingrese el valor de B[" << i << "]: ";
        cin >> B[i];
      }

        double r = pearson_r(A, B);
        cout << "el coeficiente de correlacion de pearson es: " << r << endl;

         return 0;
  }












