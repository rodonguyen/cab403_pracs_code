#include <stdio.h>

/* random record description - could be anything */
struct record
{
  int x, y, z;
};

/* writes and then reads 10 arbitrary records from the file "junk". */
int main()
{
  int i;
  FILE *file;
  struct record a_record;

  /* create the file of 10 records */
  file = fopen("junk", "w");
  if (!file)
    return 1;
  for (i = 1; i <= 10; i++)
  {
    a_record.x = i;
    fwrite(&a_record, sizeof(struct record), 1, file);
  }
  fclose(file);

  /* read the 10 records */
  file = fopen("junk", "r");
  if (!file)
    return 1;
  for (i = 1; i <= 10; i++)
  {
    fread(&a_record, sizeof(struct record), 1, file);
    printf("%d\n", a_record.x);
  }
  fclose(file);
  printf("\n");

  /* use fseek to read the 10 records in reverse order */
  file = fopen("junk", "r");
  if (!file)
    return 1;
  for (i = 9; i >= 0; i--)
  {
    fseek(file, sizeof(struct record) * i, SEEK_SET);
    fread(&a_record, sizeof(struct record), 1, file);
    printf("%d\n", a_record.x);
  }
  fclose(file);
  printf("\n");

  /* use fseek to read odd records */
  file = fopen("junk", "r");
  if (!file)
    return 1;
  fseek(file, 0, SEEK_SET);
  for (i = 0; i < 5; i++)
  {
    fread(&a_record, sizeof(struct record), 1, file);
    printf("%d\n", a_record.x);
    fseek(file, sizeof(struct record), SEEK_CUR);  // move the file pointer up by one record
  }
  fclose(file);
  printf("\n");

  /* use fseek to read 4th record, change it, and write it back */
  file = fopen("junk", "r+");
  if (!file)
    return 1;
  
  // move the file pointer to the 4th record
  fseek(file, sizeof(struct record) * 3, SEEK_SET);
  
  // get the 4th record
  fread(&a_record, sizeof(struct record), 1, file);
  a_record.x = 100;

  // move the file pointer back to the 4th record and write the new record
  fseek(file, sizeof(struct record) * 3, SEEK_SET);
  fwrite(&a_record, sizeof(struct record), 1, file);
  fclose(file);
  printf("\n");

  /* read the 10 records to ensure 4th record was changed */
  file = fopen("junk", "r");
  if (!file)
    return 1;
  for (i = 1; i <= 10; i++)
  {
    fread(&a_record, sizeof(struct record), 1, file);
    printf("%d\n", a_record.x);
  }
  fclose(file);

  return 0;
}