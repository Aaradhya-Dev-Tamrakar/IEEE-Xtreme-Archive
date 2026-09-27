#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int T;
    // Leer el número de casos de prueba
    if (!(cin >> T)) return;
    
    while (T--) {
        int N;
        cin >> N;
        
        // Frecuencia de cada valor dado por Alex
        unordered_map<int, int> count;
        for (int i = 0; i < N; ++i) {
            int a;
            cin >> a;
            count[a]++;
        }

        long long total_cost = 0;
        int P = 0; // Cantidad de grupos "parciales" (con espacio)
        
        // Calcular el costo de los N elementos como si fueran todos verdaderos
        for (auto const& [v, c] : count) {
            long long groups = (c + v - 1LL) / v; // Equivalente a ceil(c / v)
            total_cost += groups * v;
            
            if (c % v != 0) {
                P++; // Hay un grupo parcial para el valor v
            }
        }

        long long min_ans = -1;

        // Iterar probando cada valor único como si fuese la "mentira"
        for (auto const& [x, c] : count) {
            long long c_prime = total_cost;
            
            // Si al quitar una instancia de 'x' completamos el múltiple y desaparece un grupo
            if ((c - 1) % x == 0) {
                c_prime -= x;
            }

            // ¿Es 'x' actualmente uno de los grupos parciales?
            bool in_S_partial = (c % x != 0);
            bool valid_opt1 = false;

            // Verificamos si existe un grupo parcial al que podamos anexar la canica "x"
            if (!in_S_partial) {
                if (P > 0) valid_opt1 = true;
            } else {
                if (P > 1) valid_opt1 = true;
            }

            long long ans;
            if (valid_opt1) {
                // Si existe un espacio de otro color, lo anexamos sin costo adicional
                ans = c_prime;
            } else {
                // Si no hay otro espacio, creamos un nuevo color para este
                if (x != 1) {
                    ans = c_prime + 1;
                } else {
                    // Si el valor reportado fue 1, su tamaño real no puede ser 1 (debe mentir)
                    ans = c_prime + 2; 
                }
            }

            // Registrar la respuesta mínima
            if (min_ans == -1 || ans < min_ans) {
                min_ans = ans;
            }
        }

        cout << min_ans << "\n";
    }
}

int main() {
    // Optimización de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}