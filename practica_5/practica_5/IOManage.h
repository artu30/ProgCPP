using fileID = FILE *;

// Abre un fichero especificando su nombre y su modo (leer o escribir)
fileID openFile(const char *file, const char *mode);

// Cierra el fichero
void closeFile(fileID fileId);

// Lee en el fichero el numero de caracteres indicado
const int readFile(fileID fileId, unsigned int numCharacters, char *readBuffer);

// Escribe en el fichero el texto indicado
const int writeFile(fileID fileId, const char writeBuffer[]);

// Devuelve la longitud de una cadena
int getStringSize(const char myStr[]);