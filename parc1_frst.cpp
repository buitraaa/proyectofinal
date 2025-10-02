#include <iostream> 
#include <cctype> 
using namespace std; 
int main() { 
    const int max = 50; 
    const int max_error = 6; 
    const int max_intnt = 26; 
    // Lista de palabras  
    const char palabras[10][max] = { 
        "GATO", "CASA", "COLOMBIA", "AHORCADO", "PROGRAMACION", 
        "MECATRONICA", "SEGURIDAD", "ALGORITMO", "CONSOLA", "UNIVERSIDAD" 
    }; 

    char jugarOtra; 
    int indice = 0; // Empezar con la primera palabra 
    do { 

        // Seleccionar palabra 

        const char * palabraSecreta = palabras[indice]; 
        int longitud = 0; 
        while (palabraSecreta[longitud] != '\0') { 
            longitud++; 

        } 

        char estado[max]; 
        for (int i = 0; i < longitud; i++) { 
            estado[i] = '_'; 

        } 

        estado[longitud] = '\0'; 
        char intentadas[max_intnt]; 
        int nIntentadas = 0; 
        int errores = 0; 

 

        while (errores < max_error) { 
            // Mostrar estado 
            cout << "\nPalabra: "; 
            for (int i = 0; i < longitud; i++) { 
                cout << estado[i] << " "; 
            } 
            cout << "\nIntentos restantes: " << (max_error - errores) << "\n"; 

            // Verificar si ya ganó 

            bool completo = true; 
            for (int i = 0; i < longitud; i++) { 
                if (estado[i] == '_') { 
                    completo = false; 
                    break; 

                } 

            } 

            if (completo) { 
                cout << "\n¡Ganaste! La palabra era: " << palabraSecreta << "\n"; 
                break; 

            } 

 

            // Pedir letra 
            cout << "Ingresa una letra: "; 
            char letra; 
            cin >> letra; 
            letra = toupper(letra); 

 

            // Verificar repetida 
            bool repetida = false; 
            for (int i = 0; i < nIntentadas; i++) { 
                if (intentadas[i] == letra) { 
                    repetida = true; 
                    break; 
                } 

            } 

            if (repetida) { 
                cout << "Ya intentaste esa letra.\n"; 
                continue; 

            } 

            intentadas[nIntentadas++] = letra; 



            // Verificar si está en la palabra 

            bool acierto = false; 
            for (int i = 0; i < longitud; i++) { 
                if (palabraSecreta[i] == letra) { 
                    estado[i] = letra; 
                    acierto = true; 

                } 

            } 

            if (!acierto) { 
                errores++; 
                cout << "Letra incorrecta.\n"; 
            } else { 
                cout << "¡Bien! La letra está en la palabra.\n"; 

            } 

        } 


        if (errores == max_error) { 
            cout << "\nPerdiste. La palabra era: " << palabraSecreta << "\n"; 

        } 
        cout << "\n¿Quieres jugar otra vez? (S/N): "; 
        cin >> jugarOtra; 
        jugarOtra = toupper(jugarOtra); 

        // Cambiar palabra 
        indice++; 
        if (indice >= 10) indice = 0;
    } while (jugarOtra == 'S'); 

    return 0; 

} 
