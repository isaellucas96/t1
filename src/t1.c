//Trabalho 1
//Estrutura de Dados
//Isael Antonio Lucas Paulo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printString(FILE **idArquivo, int id, char *string){
	int aux;
	char temp;
	char barraN[] = "\n";
	aux = strlen(string);
	for(int i=0;i<aux;i++){
		temp=string[i];
		if(temp=='\\'){
			if(string[i+1]=='n'){
			fprintf(idArquivo[id],"%s",barraN);
			//fputs("\n",idArquivo[i]);
			i++;
			}
		}
		else{
			fputc(temp,idArquivo[id]);
		}
	}
}
char *stringAspas(char *stringAux){
	char *newString;
	int aux;
	aux = strlen(stringAux);
	newString = (char *)malloc((aux-1)*sizeof(char));
	for(int i=1;i<(aux-1);i++){
		newString[i-1]=stringAux[i];
	}
	if(stringAux[0]!='"')
		return stringAux;
	else{
	newString[aux-2]='\0';
	free(stringAux);
	return newString;
	}
}
int convStringToInt(char *string){
	int tamanhoPrimeiroString, tamanhoSegundoString,result;
	char *String;
	tamanhoPrimeiroString = strlen(string);
	String = (char *)malloc((tamanhoPrimeiroString)*sizeof(char));
	for(int i=1;i<tamanhoPrimeiroString;i++){
		String[i-1]=string[i];
	}
	String[tamanhoPrimeiroString-1]='\0';
	return (atoi(String));
	free(String);
	String = NULL;
}
void contX(FILE *arquivo, char *x, char *parametroUm, char *parametroDois, char *parametroTres){
	char *string;
	//alocacoes dinamicas
	string = (char *)malloc(1000*sizeof(char));
	//fim da alocacao dinamica
	fscanf(arquivo," %[^\n]s",string);
			if(strcmp(string,"@1")==0){
				sprintf(x,"%s%s",x,parametroUm);
			}
			else if(strcmp(string,"@2")==0){
				sprintf(x,"%s%s",x,parametroDois);
			}
			else if(strcmp(string,"@3")==0){
				sprintf(x,"%s%s",x,parametroTres);
			}
			else{
				string=stringAspas(string);
				sprintf(x,"%s%s",x,string);
			}
	free(string);
	string = NULL;
}
void contY(FILE *arquivo, char *y, char *parametroUm, char *parametroDois, char *parametroTres){
	char *string;
	//alocacoes dinamicas
	string = (char *)malloc(1000*sizeof(char));
	//fim da alocacao dinamica
	fscanf(arquivo,"%s",string);
			if(strcmp(string,"@1")==0){
				sprintf(y,"%s%s",y,parametroUm);
			}
			else if(strcmp(string,"@2")==0){
				sprintf(y,"%s%s",y,parametroDois);
			}
			else if(strcmp(string,"@3")==0){
				sprintf(y,"%s%s",y,parametroTres);
			}
			else{
				string=stringAspas(string);
				sprintf(y,"%s%s",y,string);
			}
	free(string);
	string = NULL;
}
void contZ(FILE *arquivo, char *z, char *parametroUm){
	char *string, *temporario;
	int aux;
	//alocacoes dinamicas
	string = (char *)malloc(1000*sizeof(char));
	temporario = (char *)malloc(1000*sizeof(char));
	//fim da alocacao dinamica
	fscanf(arquivo,"%s",string);
			if(string[0]=='*'){
				if(string[1]=='*'){
					strcpy(temporario,z);
					for(int i=0;i<(atoi(parametroUm));i++){
						sprintf(z,"%s%s",z,temporario);
					}
				}
				else{
					strcpy(temporario,z);
					aux=convStringToInt(string);
					for(int i=0;i<aux;i++){
						sprintf(z,"%s%s",z,temporario);
					}
				}

			}
			else{
				string = stringAspas(string);
				sprintf(z,"%s%s",z,string);
			}
	free(string);
	free(temporario);
	string = NULL;
	temporario = NULL;
}
void dir(FILE *arquivo, char *path, char *x, char *y, char *z){
	char *string;
	string = (char *)malloc(1000*sizeof(char));
	fscanf(arquivo,"%s",string);
			if(strcmp(string,"#x")==0){
				strcpy(path,x);
			}
			else if(strcmp(string,"#y")==0){
				strcpy(path,y);
			}		
			else if(strcmp(string,"#z")==0){
				strcpy(path,z);
			}
			else{
				strcpy(path,string);
			}
	free(string);
	string = NULL;
}
void nameFile(FILE *arquivo, char *fileWrite, char *x, char *y, char *z){
	char *string;
	string = (char *)malloc(1000*sizeof(char));
	fscanf(arquivo,"%s",string);
			if(strcmp(string,"#x")==0){
				strcpy(fileWrite,x);
			}
			else if(strcmp(string,"#y")==0){
				strcpy(fileWrite,y);
			}
			else if(strcmp(string,"#z")==0){
				strcpy(fileWrite,z);
			}
			else{
				string=stringAspas(string);
				strcpy(fileWrite,string);
			}
	free(string);
	string = NULL;
}
void extFile(FILE *arquivo, char *extensaoFile, char *x, char *y, char *z){
	char *string;
	string = (char *)malloc(1000*sizeof(char));
	fscanf(arquivo,"%s",string);
			if(strcmp(string,"#x")==0){
				strcpy(extensaoFile,x);
			}
			else if(strcmp(string,"#y")==0){
				strcpy(extensaoFile,y);
			}
			else if(strcmp(string,"#z")==0){
				strcpy(extensaoFile,z);
			}
			else{
				string=stringAspas(string);
				strcpy(extensaoFile,string);

			}
	free(string);
	string = NULL;
}
void readInFile(FILE *arquivo, FILE **idArquivo, char *x, char *y, char *z){
	int id;
	char *string;
	//alocações dinamicas
	string = (char *)malloc(5*sizeof(char));
	//fim das alocações dinamicas
	fscanf(arquivo,"%d",&id);
	fscanf(arquivo,"%s",string);
	if(strcmp(string,"#x")==0){
		//fgets(x,1000,idArquivo[id]);
		fscanf(idArquivo[id]," %[^\n]s",x);
		
	}
	else if(strcmp(string,"#y")==0){
		//fgets(y,1000,idArquivo[id]);
		fscanf(idArquivo[id]," %[^\n]s",y);
		
	}
	else if(strcmp(string,"#z")==0){
		//fgets(z,1000,idArquivo[id]);
		fscanf(idArquivo[id]," %[^\n]s",z);
	
	}
	free(string);
	string = NULL;
}
void closeFile(FILE *arquivo, FILE **idArquivo){
	int id;
	fscanf(arquivo,"%d",&id);
	if(idArquivo[id]!=NULL){
	fclose(idArquivo[id]);
	}
	idArquivo[id] = NULL;
}
void createFile(FILE *arquivo, FILE **idArquivo, char *fileWrite, char *extensaoFile, char *path){
	int id,aux;
	char *string, *createArquivoTemp;
	string = (char *)malloc(1000*sizeof(char));
	aux = strlen(path);
	createArquivoTemp = (char *)malloc((2+aux)*sizeof(char));
	fscanf(arquivo,"%d",&id);
	if(path[aux-1]!='/'){
		for(int i=0;i<aux;i++){
			createArquivoTemp[i]=path[i];
		}
		createArquivoTemp[aux]='/';
		createArquivoTemp[aux+1]='\0';
		sprintf(string,"%s%s.%s",createArquivoTemp,fileWrite,extensaoFile);
	}
	else{
		sprintf(string,"%s%s.%s",path,fileWrite,extensaoFile);
	}
	//idArquivo[id] = (FILE *)malloc(sizeof(FILE));
	idArquivo[id] = fopen(string,"w");
	free(string);
	free(createArquivoTemp);
	string = NULL;
}
void openFile(FILE *arquivo, FILE **idArquivo, char *fileWrite, char *extensaoFile, char *path){
	int id,aux;
	char *string, *createArquivoTemp;
	string = (char *)malloc(1000*sizeof(char));
	aux = strlen(path);
	createArquivoTemp = (char *)malloc((2+aux)*sizeof(char));
	fscanf(arquivo,"%d",&id);
	if(path[aux-1]!='/'){
		for(int i=0;i<aux;i++){
			createArquivoTemp[i]=path[i];
		}
		createArquivoTemp[aux]='/';
		createArquivoTemp[aux+1]='\0';
		sprintf(string,"%s%s.%s",createArquivoTemp,fileWrite,extensaoFile);
	}
	else{
		sprintf(string,"%s%s.%s",path,fileWrite,extensaoFile);
	}
	//idArquivo[id] = (FILE *)malloc(sizeof(FILE));
	string=stringAspas(string);
	idArquivo[id] = fopen(string,"a");
	free(string);
	free(createArquivoTemp);
	string = NULL;
}
void readFile(FILE *arquivo, FILE **idArquivo, char *fileWrite, char *extensaoFile, char *path){
	int id,aux;
	char *string, *createArquivoTemp;
	string = (char *)malloc(1000*sizeof(char));
	createArquivoTemp = (char *)malloc(1000*sizeof(char));
	aux = strlen(path);
	fscanf(arquivo,"%d",&id);
	if(path[aux-1]!='/'){
		for(int i=0;i<aux;i++){
			createArquivoTemp[i]=path[i];
		}
		createArquivoTemp[aux]='/';
		createArquivoTemp[aux+1]='\0';
		sprintf(string,"%s%s.%s",createArquivoTemp,fileWrite,extensaoFile);
	}
	else{
		sprintf(string,"%s%s.%s",path,fileWrite,extensaoFile);
	}
	//sprintf(string,"%s%s.%s",path,fileWrite,extensaoFile);
	//idArquivo[id] = (FILE *)malloc(sizeof(FILE));

	idArquivo[id] = fopen(string,"r");
	free(string);
	free(createArquivoTemp);
	createArquivoTemp = NULL;
	string = NULL;
}
void writeInFile(FILE *arquivo, FILE **idArquivo, char *x, char *y, char *z){
	int id;
	char *string, *temporario;
	//alocação dinamica
	string = (char *)malloc(1000*sizeof(char));
	temporario = (char *)malloc(1000*sizeof(char));
	//fim da alocação dinamica
	fscanf(arquivo,"%d",&id);
	fscanf(arquivo," %[^\n]s",string);
	if(idArquivo[id]==NULL)
		printf("O arquivo não esta aberto\n");
	else if(strcmp(string,"#x")==0){
		//fprintf(idArquivo[id],"%s\n",x);
		//fputs(x,idArquivo[id]);
		temporario=stringAspas(x);
		printString(idArquivo,id,temporario);
	}
	else if(strcmp(string,"#y")==0){
		//fprintf(idArquivo[id],"%s\n",y);
		temporario=stringAspas(y);
		printString(idArquivo,id,temporario);
	}
	else if(strcmp(string,"#z")==0){
		//fprintf(idArquivo[id],"%s\n",z);
		temporario=stringAspas(z);
		printString(idArquivo,id,temporario);
	}
	else{
		string=stringAspas(string);
		fprintf(idArquivo[id],"%s\n",string);
	}
	free(string);
	string = NULL;
}
void manipulacaoDeArquivo(FILE *arquivo, char *path, char *parametroUm, char *parametroDois, char *parametroTres){
	char *x = NULL, *y = NULL, *z = NULL;
	char *comando, *fileWrite, *extensaoFile, comandoChar, aux;
	FILE **idArquivo;
	//Alocações dinamicas
	comando = (char *)malloc(10*sizeof(char));
	fileWrite = (char *)malloc(1000*sizeof(char));
	extensaoFile = (char *)malloc(1000*sizeof(char));
	idArquivo = (FILE **)malloc(10*sizeof(FILE *));
	x = (char *)malloc(1000*sizeof(char));
	y = (char *)malloc(1000*sizeof(char));
	z = (char *)malloc(100000*sizeof(char));
	//Fim das alocações dinamicas
	//Zerando as strings
	x[0]='\0';
	y[0]='\0';
	z[0]='\0';
	//Fim
	
	while(!feof(arquivo)){
		//fscanf(arquivo,"%c",&teste);
		comandoChar=fgetc(arquivo);
		if(comandoChar=='+'){
			aux=fgetc(arquivo);
			if(aux=='x')
					contX(arquivo,x,parametroUm,parametroDois,parametroTres);
				if(aux=='y')
					contY(arquivo,y,parametroUm,parametroDois,parametroTres);
				if(aux=='z')
					contZ(arquivo,z,parametroUm);
		}
		//Comandos para limpar as variaveis
		if(comandoChar=='x')
			x[0]='\0';
		if(comandoChar=='y')
			y[0]='\0';
		if(comandoChar=='z')
			z[0]='\0';
		//Fim dos comandos para limpar as variaveis
		if(comandoChar=='d')
			dir(arquivo,path,x,y,z);
		if(comandoChar=='a')
			nameFile(arquivo,fileWrite,x,y,z);
		if(comandoChar=='e')
			extFile(arquivo,extensaoFile,x,y,z);
		if(comandoChar=='c')
			createFile(arquivo,idArquivo,fileWrite,extensaoFile,path);
		if(comandoChar=='o')
			openFile(arquivo,idArquivo,fileWrite,extensaoFile,path);
		if(comandoChar=='l')
			readFile(arquivo,idArquivo,fileWrite,extensaoFile,path);
		if(comandoChar=='w')
			writeInFile(arquivo,idArquivo,x,y,z);
		if(comandoChar=='r')
			readInFile(arquivo,idArquivo,x,y,z);
		if(comandoChar=='f')
			closeFile(arquivo,idArquivo);

	
	
	}
	//liberacao de memoria
	free(comando); 
	free(fileWrite);
	free(extensaoFile);
	free(idArquivo);
	free(x); 
	free(y);
	free(z);
	//fim da liberacao de memoria
	fclose(arquivo);
}
void borja(int argc, char const **argv, char *path, char *arq, char *parametroUm, char *parametroDois, char *parametroTres,FILE *arquivo){
	int tamanhoCaractere;
	parametroUm = NULL;
	parametroDois = NULL;
	parametroTres = NULL;
	for(int i=1;i<argc;i++){
		if(strcmp((argv[i]),"-f")==0)
		{
			tamanhoCaractere = strlen((argv[i+1]));
			strcpy(arq,(argv[i+1]));
		}
		else if(strcmp((argv[i]),"-o")==0){
			tamanhoCaractere = strlen((argv[i+1]));
			strcpy(path,(argv[i+1]));
		}
		else if((strcmp(argv[i-1],"-f")!=0)&&(strcmp(argv[i-1],"-o")!=0)){
			if(parametroUm==NULL){
				parametroUm = (char *)malloc(1000*sizeof(char));
				strcpy(parametroUm,(argv[i]));
			}
			else if(parametroDois==NULL){
				parametroDois = (char *)malloc(1000*sizeof(char));
				strcpy(parametroDois,(argv[i]));
			}
			else if(parametroTres==NULL){
				parametroTres = (char *)malloc(1000*sizeof(char));
				strcpy(parametroTres,(argv[i]));
			}

		}

	}
	arquivo = fopen(arq, "r");
	manipulacaoDeArquivo(arquivo,path,parametroUm,parametroDois,parametroTres);
}
void main(int argc, char const *argv[])
{
	char *path, *arq, *parametroUm, *parametroDois, *parametroTres;
	FILE *arquivo;
	path = (char *)malloc(1000*sizeof(char));
	arq = (char *)malloc(1000*sizeof(char));
	borja(argc,argv,path,arq,parametroUm,parametroDois,parametroTres,arquivo);
	free(path);
	free(arq);
}