
#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
using namespace std;


int *A,*B,c,d;
void obroctablica(int *A,int rozmiar){
int i ;
free(B);
B = (int*)malloc(rozmiar*sizeof(int)); 
for ( i = 0; i < rozmiar; ++i)
{
        B[i]=A[rozmiar-1-i];
}
for (i = 0; i < rozmiar; ++i)
{
        A[i]=B[i];
}
}




void merge(int *A,int *L,int rozmiarlewy,int *R,int rozmiarprawy) {
	int i,j,k;

	i = 0; j = 0; k =0;

	while(i<rozmiarlewy && j< rozmiarprawy) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < rozmiarlewy) A[k++] = L[i++];
	while(j < rozmiarprawy) A[k++] = R[j++];
}
void mergesort(int *A,int rozmiar){
	int mid,i, *L, *R;
	if(rozmiar < 2) return; // jezeli jest tylko jeden element to nie rob nic

	mid = rozmiar/2;  // znalezienie polowy tablicy. 
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((rozmiar- mid)*sizeof(int)); 
	//alokacja prawej i lewej czesci tablicy
	for(i = 0;i<mid;i++) L[i] = A[i]; // zapelnienie lewej strony tablicy
	for(i = mid;i<rozmiar;i++) R[i-mid] = A[i]; // zapelnienie prawej strony tablicy

	mergesort(L,mid);  // sortowanie lewej strony tablicy
	mergesort(R,rozmiar-mid);  // sortowanie prawej strony tablicy
	merge(A,L,mid,R,rozmiar-mid);  // laczenie prawej i lewj strony w jedna tablice
        free(L);
        free(R);
}
void tworztablica(int rozmiar, float procent){
	int e;
free(A);
A = (int*)malloc(rozmiar*sizeof(int)); 
c=rozmiar*(procent/100);
for (int i = 0; i < rozmiar; ++i)
{
        A[i]=(rand()%10)+1;
    
}
mergesort(A,c);
cout<<"jezeli chcesz odwrocic tablice nacijnij 1"<<endl;
cin>>d;
if (d==1)
{
	obroctablica(A,rozmiar);
}

};
/* wybieramy pivota nastepnie ustawiamy wszystkie mniejsze na elementy na jego lewa strona,
a wszystkie wieksze na prawa*/
int partation(int *A,int start,int end)
{
int pivot =A[end];
int partationindex=start;
for (int i = start; i < end; i++)
{
	if (A[i]<=pivot)
	{
		swap(A[i],A[partationindex]);
		partationindex++;
	}
}
 swap(A[partationindex],A[end]);
return partationindex;
}

void quicksort(int *A,int start,int end){
if (start<end)
{
int partationindex=partation(A, start, end);//dokonujemy partition
quicksort(A,start,partationindex-1);//uzywamy quicksorta na lewej 
quicksort(A,partationindex+1,end);//i prawej stronie
}
}

/*budowanie  kopca*/
void heapify(int *A,int curr,int rozmiar){
int largest=curr;
int l =2*curr+1;
int r =2*curr+2;
if (l<rozmiar && A[l]>A[largest])
{
	largest=l;
}
if (r<rozmiar && A[r]>A[largest])
{
	largest=r;
}
if (largest!=curr)
{
int tmp=A[curr];
A[curr]=A[largest];
A[largest]=tmp;
heapify(A,largest,rozmiar);
}
}


void heapsort(int *A,int rozmiar){
for (int i = rozmiar/2-1; i >= 0; i--)
{
	heapify(A,i,rozmiar);
}
/*sortowanie kopca*/
for (int i = rozmiar-1; i >0; --i)
{
int tmp=A[0];
A[0]=A[i];
A[i]=tmp;
heapify(A,0,i);
}
}




void introspectivesort(int *A,int rozmiar,int depthlimit){
	int p;
if (depthlimit<=0)
{
	heapsort(A,rozmiar);
	return;

}



p=partation(A,0,rozmiar);
if (p>9)
{
introspectivesort(A,p,depthlimit-1);
}
if (rozmiar-1-p>9)
{
introspectivesort(A+p+1,rozmiar-1-p,depthlimit-1);
}


}
	

int main()
{
int rozmiar,i,start,end,liczba=0;
float procent;
int depthlimit;
cout<<"Podaj rozmiar tablicy"<<endl;
cin>>rozmiar;
cout<<"Podaj procent ulozenia tablicy (0-100) "<<endl;
cin>>procent;
tworztablica(rozmiar,procent);

while (liczba!=6)
{



cout<<endl<<"1 sortowanie mergesort "<<endl
<<"2 sortowanie quicksort"<<endl
<<"3 sortowanie introspectivesort"<<endl
<<"4 sortowanie przez kopcowanie "<<endl
<<"5 utworz nowa tablica "<<endl
<<"6 koniec"<<endl;
cin>>liczba;
cout<<endl;
if (rozmiar<=100)
{
cout<<endl;
for (int i = 0; i < rozmiar; ++i)
{
        cout<<A[i]<<endl;
      
}
cout<<endl;
}


auto poczatek = std::chrono::high_resolution_clock::now();
switch (liczba)
{
case 1:
   
	mergesort(A,rozmiar);

	break;
case 2:
 
	quicksort(A,0,rozmiar-1);
	
	break;
case 3:
     depthlimit=2*floor(log(rozmiar)/M_LN2);
    introspectivesort(A,rozmiar,depthlimit);
	
	break;
case 4:
    
    heapsort(A,rozmiar);
	
	break;	
case 5:
   cout<<"Podaj rozmiar tablicy"<<endl;
   cin>>rozmiar;
   cout<<"Podaj procent ulozenia tablicy (0-100) "<<endl;
   cin>>procent;
   tworztablica(rozmiar,procent);
	break;
	break;
default :
  if (liczba!=6)
{cout<<"niepoprawna opcja"<<endl;}
	break;
}
	auto koniec = std::chrono::high_resolution_clock::now();
 std::chrono::duration<double> elapsed=koniec-poczatek;
 cout<<elapsed.count()<<endl;
if (rozmiar<=100)
{
cout<<endl;
for (int i = 0; i < rozmiar; ++i)
{
        cout<<A[i]<<endl;
      
}
cout<<endl;
}

}
   free(A);
   free(B);
   return 0;
}