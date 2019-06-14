/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return 1 se leyo bien , 0 se leyo mal ,
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si leyo bien , 0 si leyo mal
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);
