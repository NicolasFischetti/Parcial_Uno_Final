#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getStringLetras(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);
void getString(char mensaje[],char input[]);
void clearStdin(void);
int esNumerico(char str[]);
int opcion_getInt(int* num, int limite, char* msg, char* msgErr, int reintentos);
int pedirCUIT(char *str, char *mensaje, char *error, int intentos);
int esCUIT(char *str);
int getStringNumeros(char mensaje[],char input[]);

#endif // UTN_H_INCLUDED
