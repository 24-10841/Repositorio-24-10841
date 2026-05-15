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







#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> dec_to_base(int n, int base) {
    if (n == 0) return {'0'};

    vector<char> res;
    while (n > 0) {
        int r = n % base;
        if (r < 10) res.push_back('0' + r);
        else res.push_back('A' + (r - 10));
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int base_to_dec(const vector<char>& v, int base) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        int val;
        if (v[i] >= '0' && v[i] <= '9') val = v[i] - '0';
        else val = v[i] - 'A' + 10;
        res = res * base + val;
    }
    return res;
}

vector<char> dec_to_septapus(int n) { return dec_to_base(n, 7); }
vector<char> dec_to_octopus(int n) { return dec_to_base(n, 8); }
vector<char> dec_to_hexakaidecapus(int n) { return dec_to_base(n, 16); }

int septapus_to_dec(const vector<char>& s) { return base_to_dec(s, 7); }
int octopus_to_dec(const vector<char>& s) { return base_to_dec(s, 8); }
int hexakaidecapus_to_dec(const vector<char>& s) { return base_to_dec(s, 16); }

vector<char> septapus_to_octopus(const vector<char>& s) {
    return dec_to_octopus(septapus_to_dec(s));
}

vector<char> septapus_to_hexakaidecapus(const vector<char>& s) {
    return dec_to_hexakaidecapus(septapus_to_dec(s));
}

vector<char> octopus_to_septapus(const vector<char>& s) {
    return dec_to_septapus(octopus_to_dec(s));
}

vector<char> octopus_to_hexakaidecapus(const vector<char>& s) {
    return dec_to_hexakaidecapus(octopus_to_dec(s));
}

vector<char> hexakaidecapus_to_septapus(const vector<char>& s) {
    return dec_to_septapus(hexakaidecapus_to_dec(s));
}

vector<char> hexakaidecapus_to_octopus(const vector<char>& s) {
    return dec_to_octopus(hexakaidecapus_to_dec(s));
}

void print_vector(const vector<char>& v) {
    for (char c : v) cout << c;
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese un numero decimal: ";
    cin >> n;

    cout << "Septapus (base 7): ";
    print_vector(dec_to_septapus(n));

    cout << "Octopus (base 8): ";
    print_vector(dec_to_octopus(n));

    cout << "Hexakaidecapus (base 16): ";
    print_vector(dec_to_hexakaidecapus(n));

    return 0;
}










