typedef struct
{
    char Direccion[20];
    int Altura;
    char Barrio[20];
} STDireccion;

typedef struct
{
    int fecha;
    int Total;
    char Nombre[30];
    char DNI[15];

} STFactura;

typedef struct
{
    int id;
    int DNI;
    char Nombre[30];
    char Apellido[30];
    char NumeroCel[20];
    STDireccion direccion;

} STPersonal;

typedef struct
{
    int alta;
    int Internet;
    int Cable;


} STServicio;

typedef struct 
{
    STPersonal Dato;
    STFactura Factura;
    STServicio Servicio;
}STCliente;

