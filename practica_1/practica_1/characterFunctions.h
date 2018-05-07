/*
Function getBullets

unsigned int charBits

Returns the bullets that i have in my gun

returns int
*/
unsigned int getBullets(unsigned int charBits);

/*
Function addBullets

unsigned int charBits
unsigned int numToAdd

Adds more bullets to my gun

returns int
*/
void addBullets(unsigned int &charBits, unsigned int numToAdd);

/*
Function haveInfiniteBullets

unsigned int charBits

Returns if i have infinite bullets

returns bool
*/
bool haveInfiniteBullets(unsigned int charBits);

/*
Function activeBullets

unsigned int charBits

Activate infinite bullets

returns void
*/
void activeBullets(unsigned int &charBits);