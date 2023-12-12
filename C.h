#include "matrix.h"

int determ(int** Arr, int size);  
int opred_mas(int **Arr, int size);       //функция задания элементов массива

void alg()
{
setlocale(LC_ALL, "Russian");
int n,k,k1;
cout<<"введите порядок матрицы\n";
cin>>n;

int** a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int [n];
opred_mas(a, n);
for (int index1=0;index1<n;index1++)
    for (int index2=0;index2<n;index2++)
    {
        k=index1; k1=index2;
        int** temp = new int *[n-1];
            for (int i = 0; i < n-1; i++)
                temp[i] = new int [n-1];
        int s=0,s1=0;
        for(int i=0;i<n;++i)//строим матрицу минора участвующего в вычислении алгебраисческого дополнения
            if(i!=k) 
            {
                s1=0;
                for(int j=0;j<n;++j)
                    if(j!=k1) 
                        {
                            temp[s][s1]=a[i][j];
                            s1++;
                        }

                s++;
            }
            /*cout<<"\nМатрица минора элемента A"<<k+1<<k1+1<<endl;
             for(int i=0;i<n-1;++i)
            {
                for(int j=0;j<n-1;++j)
                {

                cout<<temp[i][j]<<" ";
                }
                cout<<endl;
            }*/
            //for(int i = 0; i < n-2; i++){
                //for(int j=0;j<n-2;++j)
                //{
                    int res=0;
                    res=pow(-1.,k+1+k1+1)*determ(temp,n-1);
                    cout << res << " ";
                //}
            //}
    }
}

int opred_mas(int **Arr, int size)       //функция задания элементов массива
{
    //srand(time(NULL));
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
        Arr[i][j]=rand()%10-5;
        cout<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl;
    return 0; 
}

int determ(int** Arr, int size)         //функция поиска определителя
{
    int i,j;
    double det=0;       //переменная определителя
    int **matr;         //указатель
        if(size==1)     // 1-е условие , размер 1
        {
        det=Arr[0][0];
        }
            else if(size==2)    // 2-е условие , размер 2
            {
            det=Arr[0][0]*Arr[1][1]-Arr[0][1]*Arr[1][0];    //
            }
    else
    {
    matr=new int*[size-1]; //создание динамического массива
    for(i=0;i<size;++i)
        {
        for(j=0;j<size-1;++j)     
        {
        if(j<i)
          {
            matr[j]=Arr[j];
                   }
        else
            matr[j]=Arr[j+1];
               }
    det+=pow(-1., (i+j))*determ(matr, size-1)*Arr[i][size-1];  //подсчеты
    }
    delete[] matr;  //удаляем массив
    } //возвращаем значение определителя
    return det;
    }
