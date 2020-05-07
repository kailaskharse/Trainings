#include<errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <mosquitto.h>
#include <unistd.h>
#include <fcntl.h>
#include <my_global.h>
#include <mysql.h>

#define MAXLEN 80
#define CONFIG_FILE "config"
char MYSQL_HOST[MAXLEN];
char MYSQL_PASSWD[MAXLEN];
char MYSQL_USER[MAXLEN];

void param_config(void);
char* trim (char * );


int main(int argc, char **argv)
{  

  
  param_config(); //Reading config file

  MYSQL *con = mysql_init(NULL);
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, MYSQL_HOST, MYSQL_USER, MYSQL_PASSWD, NULL, 0, NULL, 0) == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }  

  if (mysql_query(con, "USE kernel")) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

if (mysql_query(con, "INSERT INTO `energy`(`sl.no`, `watts`) VALUES (2,23)"))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
  mysql_close(con);
  exit(0);
}


void param_config(void) {
        char *s, buff[256];
        FILE *fp = fopen (CONFIG_FILE, "r");
        if (fp == NULL)
        {
                return;
        }

        /* Read next line */
        while ((s = fgets (buff, sizeof buff, fp)) != NULL)
        {
                /* Skip blank lines and comments */
                if (buff[0] == '\n' || buff[0] == '#')
                        continue;

                /* Parse name/value pair from line */
                char name[MAXLEN], value[MAXLEN];
                s = strtok (buff, "=");
                if (s==NULL)
                        continue;
                else
                        strncpy (name, s, MAXLEN);
                s = strtok (NULL, "=");
                if (s==NULL)
                        continue;
                else
                        strncpy (value, s, MAXLEN);
                trim (value);

                /* Copy into correct entry in parameters struct */
                if (strcmp(name, "MYSQL_HOST")==0) {
                        strncpy (MYSQL_HOST, value, MAXLEN);
			printf("MYSQL_HOST:\t%s\n",MYSQL_HOST);
		}
                else if (strcmp(name, "MYSQL_PASSWD")==0) {
                        strncpy (MYSQL_PASSWD, value, MAXLEN);
			printf("MYSQL_PASSWD:\t%s\n",MYSQL_PASSWD);
		}
                else if (strcmp(name, "MYSQL_USER")==0) {
                        strncpy (MYSQL_USER, value, MAXLEN);
			printf("MYSQL_USER:\t%s\n",MYSQL_USER);
		}
                else
                        printf ("WARNING: %s/%s: Unknown name/value pair!\n",
                                        name, value);



        }

        /* Close file */
        fclose (fp);
}


char* trim (char * s)
{
        /* Initialize start, end pointers */
        char *s1 = s, *s2 = &s[strlen (s) - 1];

        /* Trim and delimit right side */
        while ( (isspace (*s2)) && (s2 >= s1) )
                s2--;
        *(s2+1) = '\0';

        /* Trim left side */
        while ( (isspace (*s1)) && (s1 < s2) )
                s1++;

        /* Copy finished string */
        strcpy (s, s1);
        return s;
}     
