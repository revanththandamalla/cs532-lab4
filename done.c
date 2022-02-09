#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc,char *argv[]){
 int  file1,file2;
	long int n;
	ssize_t MAX=5000;
	char buf[MAX];

	
	
	
	if (argc != 3){
		printf("exceeded files for the code : %s",argv[0]);
		exit (-1);
	}
	file1 = open(argv[1],O_WRONLY|O_APPEND);
   file2 = open(argv[2], O_RDONLY);

   if ( file1 == -1 || file2 == -1){
		printf("Error with file open\n");
		exit (-1);
	}
   
	while ((n = read(file2, buf, MAX)) > 0){

		if (write(file1, buf, n)!=n){

		printf("Error writing to file\n");
		exit (-1);
		}
	}
if (n < 0){
		printf("Error reading file\n");
		exit (-1);

}
    close(file1);
	close(file2);
	
	 
	return 0; 
	
}



