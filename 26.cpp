#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


//Задание 1

int Msize, *M, *Ms;

void Add(int element)
{
    Msize += 1;
    M = (int*) realloc(M,Msize*sizeof(int));
    M[Msize-1] = element;
}

void DeleteElement(int index)
{
    for (int i = index+1;i < Msize;i++)
        *(M+i-1) = *(M+i);
    Msize -= 1;
    int *tmp = (M+Msize);
    M = (int*) realloc(M,Msize*sizeof(int));
    free(tmp);
}

void PrintM(void)
{
    for (int i=0;i < Msize;i++)
        printf("%d ",*(M+i));
    printf("\n");
}

void ClearM(void)
{
    Msize = 0;
    free(M);
}

int *SortM(int *arr)
{
    int tmp = *arr;
    int ind = 0;
    for (int i=1; i < Msize; i++)
        if (tmp > *(arr+i)) {tmp = *(arr+i); ind = i;}
    *(arr + ind) = *M;
    *arr = tmp;
    for (int i=1; i < Msize; i++)
    {
        tmp = *(arr+i);
        int ind = i;
        for (int j=i-1; j >= 0; j--)
            if (tmp > *(arr+j))
            {
                for (int l=ind - 1;l >= j+1;l--)
                    *(arr+l+1) = *(arr+l);
                *(arr+j+1) = tmp;
                break;
            }
    }
    return arr;
}

int _BinSearch(int st, int el, int en)
{
	if (Ms[st + int((en - st)/2)] == el)
		return st + int((en - st)/2);
	else if ((st == en) or (st < 0) or (en > Msize)) return -1;
	else if (Ms[st + int((en - st)/2)] > el)
		return _BinSearch(st, el, int((en - st)/2)-1);
	else return _BinSearch(st + int((en - st)/2) + 1, el, en);
}

void BinSearchM(int element)
{
    Ms = SortM(M);
    printf("Otsortirovaniy massiv: \n");
    for (int i=0;i < Msize;i++)
        printf("%d ",*(Ms+i));
    printf("\n");
    int r = _BinSearch(0,element,Msize-1);
    if (r==-1) printf("Ne naydeno\n");
    else printf("[%d] = %d\n", r,element);
}

void Zadanie_1(void)
{
    printf("Zadanie 1\n");
    printf("Vvedite razmer massiva: ");
    scanf("%d",&Msize);
    M = (int*) malloc(Msize * sizeof(int));
    printf("Vvedite elementi: ");
    for (int i = 0;i < Msize;i++)
        scanf("%d",(M+i));
    getchar();
    PrintM();
    printf("Dobavit' element: ");
    int x;
    scanf("%d",&x);
    getchar();
    Add(x);
    PrintM();
    printf("Udalit' element po indeksu: ");
    int k;
    scanf("%d",&k);
    getchar();
    DeleteElement(k);
    PrintM();
    printf("Dvoichniy poisk elementa: ");
    scanf("%d",&x);
    getchar();
    BinSearchM(x);
    printf("Otchistka massiva:\n");
    ClearM();
    PrintM();
}


//Задание 2.1

float *Matr1;
int Mstr,Mcol;

void AddStr1(void)
{
    printf("Dobavlena novaya stroka, vvedite eyo elementi:\n");
    Mstr++;
    Matr1 = (float*) realloc(Matr1,Mstr*Mcol*sizeof(float));
    for(int j=0;j<Mcol;j++)
        scanf("%f",&Matr1[(Mstr-1)*Mcol + j]);
}

void DelStr1(int index)
{
    for(int i=index+1;i<Mstr;i++)
        for(int j=0;j<Mcol;j++)
            Matr1[(i-1)*Mcol + j] = Matr1[i*Mcol + j];
    Mstr--;
    float *tmp = (Matr1+Mstr*Mcol);
    tmp = (float*) realloc(tmp,Mcol*sizeof(float));
    Matr1 = (float*) realloc(Matr1,Mstr*Mcol*sizeof(float));
    free(tmp);
}

void Clear1(void)
{
    printf("Otchistka matrici:\n");
    Mstr = 0;
    Mcol = 0;
    free(Matr1);
}

void MinOfChStr1()
{
    printf("Poisk minimalnogo elementa v kajdoy chotnoy stroke matrici:\n");
    for (int i=1;i<Mstr;i+=2)
    {
        int y=0;
		float min = Matr1[i*Mcol];
        for (int j=1;j<Mcol;j++)
            if (min>Matr1[i*Mcol + j])
            {
                min = Matr1[i*Mcol + j];
                y = j;
            }
        printf("[%d;%d] = %f\n",i+1,y+1,min);
    }
}

void Print1()
{
    printf("\n");
    for (int i=0;i<Mstr;i++)
    {
        for (int j=0;j<Mcol;j++)
            printf("%f ",Matr1[i*Mcol + j]);
        printf("\n");
    }
    printf("\n");
}

void Zadanie_21(void)
{
    printf("Zadanie 2 (int *M)\n");
    printf("Vvedite razmer massiva N*M:");
    scanf("%d %d",&Mstr,&Mcol);
    Matr1 = (float*) malloc(Mstr * Mcol * sizeof(float));
    printf("Vvedite elementi massiva po strokam:\n");
    for (int i=0;i<Mstr;i++)
        for (int j=0;j<Mcol;j++)
            scanf("%f",&Matr1[i*Mcol + j]);
    Print1();
    AddStr1();
    Print1();
    printf("Vvedite nomer stroki v massive, kotoraya budet udalena:\n");
    int k;
    scanf("%d",&k);
    DelStr1(k);
    Print1();
    MinOfChStr1();
    Clear1();
    Print1();
}

//Задание 2.2

float **Matr2;

void AddStr2(void)
{
    printf("Dobavlena novaya stroka, vvedite eyo elementi:\n");
    Mstr++;
    Matr2 = (float**) realloc(Matr2,Mstr*sizeof(float*));
    Matr2[Mstr-1] = (float*) malloc(Mcol * sizeof(float));
    for(int j=0;j<Mcol;j++)
        scanf("%f",&Matr2[Mstr-1][j]);
}

void DelStr2(int index)
{
    for(int i=index+1;i<Mstr;i++)
        for(int j=0;j<Mcol;j++)
            Matr2[i-1][j] = Matr2[i][j];
    Mstr--;
    float **tmp_ = (Matr2+Mstr);
    float *tmp = Matr2[Mstr];
    tmp = (float*) realloc(tmp,Mcol*sizeof(float));
    Matr2 = (float**) realloc(Matr2,Mstr*sizeof(float));
    free(tmp);
    free(tmp_);
}

void Clear2(void)
{
    printf("Otchistka matrici:\n");
    for (int i=0;i<Mstr;i++)
        free(Matr2[i]);
    free(Matr2);
    Mstr = 0;
    Mcol = 0;
}

void MinOfChStr2(void)
{
    printf("Poisk minimalnogo elementa v chotnih strokah matrici:\n");
    for (int i=1;i<Mstr;i+=2)
    {
        int y=0;
		float min = Matr2[i][0];
        for (int j=1;j<Mcol;j++)
            if (min>Matr2[i][j])
            {
                min = Matr2[i][j];
                y = j;
            }
        printf("[%d;%d] = %f\n",i+1,y+1,min);
    }
}

void Print2(void)
{
    printf("\n");
    for (int i=0;i<Mstr;i++)
    {
        for (int j=0;j<Mcol;j++)
            printf("%f ",Matr2[i][j]);
        printf("\n");
    }
    printf("\n");
}

void Zadanie_22(void)
{
    printf("Zadanie 2 (int **M)\n");
    printf("Vvedite razmer massiva N*M:");
    scanf("%d %d",&Mstr,&Mcol);
    printf("Vvedite elementi massiva po strokam:\n");
    Matr2 = (float**) malloc(Mstr * sizeof(float*));
    for (int i=0;i<Mstr;i++)
    {
        Matr2[i] = (float*) malloc(Mcol * sizeof(float));
        for (int j=0;j<Mcol;j++)
            scanf("%f",&Matr2[i][j]);
    }
    Print2();
    AddStr2();
    Print2();
    printf("Vvedite nomer stroki v massive, kotoraya budet udalena:\n");
    int k;
    scanf("%d",&k);
    DelStr2(k);
    Print2();
    MinOfChStr2();
    Clear2();
    Print2();
}

//Задание 3

struct Student
{
    char name[32];
    char fak[32];
    int nzach;
};

struct Student C[128];
int len;

void AddStudent(void)
{
    char name[32];
    printf("Imya studenta: \n");
    getchar();
    gets(name);
    char fak[32];
    printf("Nazvanie fakulteta: \n");
    gets(fak);
    int nzach;
    printf("Nomer zachetki: ");
    scanf("%d",&nzach);
    strcpy(C[len].name, name);
    strcpy(C[len].fak, fak);
    C[len].nzach= nzach;
    len++;
}

void DelStudent(int nzach)
{
	int index = -1;
	for (int i=0;i<len;i++)
	{
		if (nzach == C[i].nzach)
		{
			index = i;
			break;
		}
		if (i == len-1)
			printf("Ne nayden");
	}
	if (index != -1)
	{
	    char name[32];
	    strcpy(name, C[index].name);
	    char fak[32];
	    strcpy(fak, C[index].fak);
	    for (int i=index+1;i<len;i++)
	    {
	        strcpy(C[i-1].name,C[i].name);
	        strcpy(C[i-1].fak,C[i].fak);
	        C[i-1].nzach = C[i].nzach;
	    }
	    printf("%s iz %s udalen\n",name,fak);
	    len--;
	    C[len].nzach = 0;
	    name[0] = '\0';
	    strcpy(C[len].name, name);
	    fak[0] = '\0';
	    strcpy(C[len].fak, fak);
	}
}

void RedStudent(int nzach)
{
	int index = -1;
	for (int i=0;i<len;i++)
	{
		if (nzach == C[i].nzach)
		{
			index = i;
			break;
		}
		if (i == len-1)
			printf("Ne nayden");
	}
	if (index != -1)
	{
    	char name[32];
    	printf("Imya studenta: \n");
    	getchar();
    	gets(name);
    	char fak[32];
    	printf("Nazvanie fakulteta: \n");
    	getchar();
    	gets(fak);
    	int nzach_;
	    printf("Nomer zachetki: ");
	    scanf("%d",&nzach_);
	    strcpy(C[len].name, name);
	    strcpy(C[len].fak, fak);
    	C[len].nzach= nzach_;
	}
}

void PrintStudents(void)
{
    printf("\n");
    printf("[\n");
    for (int i=0;i<len;i++)
        printf(" %s iz %s, %d\n",C[i].name,C[i].fak,C[i].nzach);
    printf("]\n");
    printf("\n");
}

void SearchStudent(void)
{
	char fak[32];
	printf("Poisk po fakultetu: \n");
	getchar();
	gets(fak);
    printf("[\n");
    for (int i=0;i<len;i++)
        if (strcmp(fak,C[i].fak) == 0)
        	printf(" %s iz %s, %d\n",C[i].name,C[i].fak,C[i].nzach);
    printf("]\n");
    printf("\n");
}

void Zadanie_3(void)
{
    printf("Zadanie 3\n");
    printf("Skolko novih studentov dobavit?\n");
    int k;
    scanf("%d",&k);
    for (int i=0;i<k;i++)
        AddStudent();
    PrintStudents();
    printf("Udalit studenta po noveru zachetki: ");
    scanf("%d",&k);
    DelStudent(k);
    PrintStudents();
    printf("Redaktirovat studenta po noveru zachetki: ");
    scanf("%d",&k);
    RedStudent(k);
    SearchStudent();
}

int main()
{
    Zadanie_1();
    Zadanie_21();
    Zadanie_22();
    Zadanie_3();
    getchar();
}
