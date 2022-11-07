/// === Estructuras
typedef struct {
    char username[20] = {"Administrador"};
    char contraseña[20] = {"Administrador"};
}Admin;

/// === Prototipados.
int ComprobarAdmin(char usuario[20], char contraseña[20]);
void menuAdministrador();