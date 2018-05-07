using fileID = FILE *;

int getStringSize(const char myStr[]);

// Devuelve las apariciones de una cadena dentro del fichero
int getStrApparitions(fileID fileId, const char *strToSearch);

// Devuelve la suma de los enteros separados por coma de un fichero
signed int getStrCounter(fileID fileId);
