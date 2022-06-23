#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>


int process_str(char *str,char arglist[100][100],int *nargs)
{
	int i=0,j=0,k=0;
	while(str[i]!='\0')
	{
//     printf("Enter while,arglist par i=%d,j=%d,k=%d\n",i,j,k);
    	if (str[i]=='\n')
    	{
        	i++;
        	continue;

    	}
    	else if(str[i]!= ' '){
        	arglist[j][k++]=str[i++];
//     printf("Arglist value= %s\n",arglist[j][k]);
//     printf("Enter while,arglist par i=%d,j=%d,k=%d\n",i,j,k);
    }
  	 
    	else
    	{
        	(*nargs)++;
        	arglist[j][k]='\0';

        	j++;
        	k=0;
        	i++;

    	}
	}
	return 0;
}

void endprogram()
{
    exit(0);
}


int main( int argc, char **argv)
{
	int n,argno=0,i=0,fd1,fd2,pos;
	char ch;
	char path[100],buf[100],path1[100],path2[100];
	char str[100], arglist[100][100];
	printf("WELCOME TO MINI-LINUX\n");
//	strcpy(path,"./");
	while(1)
	{

    	strcpy(path,"./");
    	argno=0;
    	fflush(stdin);
    	n= read(0,str,100);
 	memset(arglist,o,100);
    	str[n]='\0';
    	process_str(str,arglist,&argno);
    	for(i=0;i<=argno;i++)
    	{
        	printf("Arguments passed = '%s' \n",arglist[i]);
    	}

  		  if(strcmp(arglist[0],"mycp")==0)
            	{
            	printf("This is my version of cp command\n");
            	strcat(path,arglist[i]);
            	fd1 = open(arglist[1],O_RDONLY);
                	if(fd1<0)
            	{
                	printf("Open Error\n");
                	exit(1);
            	}
           	 
            	strcpy(path,"./");
            	strcat(path,arglist[2]);
            	printf("dest path = %s\n",path);
            	fd2= open(arglist[2],O_RDWR|O_CREAT, 0666);

            	if(fd2<0)
            	{
                	printf("Open Error\n");
                	exit(1);
            	}
            	while((n=read(fd1,buf,100))>0)
            	{
                	write(fd2,buf,n);
            	}
            	close(fd1);
            	close(fd2);
            	}
  		  else if(strcmp(arglist[0],"mymv")==0)
    	{
        	strcpy(path1,"./");
        	strcpy(path2,"./");
        	strcat(path1,arglist[1]);
        	strcat(path2,arglist[2]);
        	rename(path1,path2);

    	}
  		  else if(strcmp(arglist[0],"mycat")==0)
            	{
            	printf("This is my version of cat command\n");
            	fd1 = open(arglist[1],O_RDONLY);
            	while(1)
            	{
                	n = read(fd1,&ch,1);
                	if (n==0)
                    	break;
                	else
                    	printf("%c",ch);
            	}
            	close(fd1);
   	 
            	}

  		  else if(strcmp(arglist[0],"myrm")==0)
    	{
        	printf("This is my version of rm command\n");
        	fd1=open(arglist[1],O_RDONLY);
        	if(fd1==0)
        	{
            	printf("Source File not found, Copy noy possible\n");
            	exit(0);
        	}
        	close(fd1);
        	unlink(arglist[1]);
    	}
      
     else if(strcmp(arglist[0],"exit")==0)
    {
   	 printf("Exiting from the program\n");
   	 endprogram();
   	 return 0;
    }


	}
}
	   	 
         

\\  HISTORY \\





int i;
  char cmd[4096];
  int cmdHisC =0; 
  char *cmdHistory;
  char *cmdsHistory[50];
int stderr;
void functail() {

// creating stack of lines
struct stack
{
          char strings[100];
};



             // stucture initialisation    
              struct stack s[100];

              FILE *file;
              char line[100];
         
              int n,count=0, i=0;

              file  = fopen(argv[1] , "r");
         
              // reading line by line and push to stack
              while(fscanf(file , "%[^\n]\n" , line)!=EOF)
              {
                             strcpy(s[i].strings , line);
                             i++;
                             n=i;
               }

               // pop line by line
               for(i=n-10;i<n;i++)
               {
                        // last 10 lines  
                         if(count == 10)
                               break;
                         else
                               printf("%s\n" , s[i].strings);
                         count++;
               }
}

void main() 
{
functail();
while(1) {
    /*** Read input from shell ***/
        fgets(cmd,4096,stdin);
        if(strcmp(cmd,"") != 0)
{
    if((cmdHistory= strdup(cmd)) != NULL)
    {
        if (cmdsHistory[cmdHisC] != NULL) 
        free(cmdsHistory[cmdHisC]);

        cmdsHistory[cmdHisC] = cmdHistory;
        cmdHisC++;
    }       
    else
    fprintf(stderr, "Error, Cannot save this command in the history pointer: Out of memory\n");

    if(cmdHisC>9)
        cmdHisC=0;
}
}


               }
