#include <stdio.h>
#include <string.h>
#include <dirent.h>

int equal_string(char *x, char *y){
	int i=0;
	while(*(x+i)!='\0'){
		if(*(x+i)!=*(y+i)){
			return 0;
		}
		i++;
	}
	return 1;
}

void main(){
	DIR* datafile=opendir("Data");
	if(datafile){
		closedir(datafile);
	}
	else{
		mkdir("Data");
	}
  
	char input1[100];
	printf("Welcome to MiniDB Manager!\n");
	Start:
	scanf("%s",input1);
	
	if(equal_string(input1,"create")){
		scanf("%s",input1);

		if(equal_string(input1,"database")){
			scanf("%s",input1);
			
			char location[]="Data/";
			strcat(location,input1);
			DIR* datafile=opendir(location);
			
			if(datafile){
				closedir(datafile);
				printf("Database already exists.\n");
				fflush(stdin);
				goto Start;
			}
			else{
				mkdir(location);
				printf("Database created.\n");
				fflush(stdin);
				goto Start;
			}
			
		}
		else if(equal_string(input1,"table")){
			scanf("%s",input1);
			char database[]="Data/";
			strcat(database,input1);
			
			DIR* loc=opendir(database);
			
			if(loc){
				closedir(loc);
				scanf("%s",input1);
				char sample_loc[100];
				strcpy(sample_loc,database);
				strcat(sample_loc,"/");
				strcat(sample_loc,input1);
				strcat(sample_loc,".csv");
				
				FILE* check_table;
				if(check_table=fopen(sample_loc,"r")){
					
					printf("Table already exists.\n");
					fclose(check_table);
					fflush(stdin);
					goto Start;
				}
				else{
					FILE* table_in_use=fopen(sample_loc,"w");
					
					scanf("%s",input1);
					if(equal_string(input1,"(")){
						scanf("%s",input1);
						
						char table_struct_heading[10000];
						int table_struct_heading_size=0;
						
						while(!equal_string(input1,")")){
							char column[100];
							strcpy(column,input1);
							strcat(column,", ");
							table_struct_heading_size+=strlen(column);
							strcat(table_struct_heading,column);
							scanf("%s",input1);
							column[0]='\0';
						}
						table_struct_heading[table_struct_heading_size-2]='\n';
						table_struct_heading[table_struct_heading_size-1]='\0';
						fputs(table_struct_heading,table_in_use);
						fclose(table_in_use);
						table_struct_heading[0]='\0';
						printf("table created.\n");
						fflush(stdin);
						goto Start;
					}
        }
      }
		}
		else{
			fflush(stdin); 
			goto Start;
		}
  }
}
