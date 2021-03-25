// 2012 A 傻逼题
// #include <stdio.h>
// #include <stdlib.h>

// int s[10][7];

// int main()
// {
//     int i,j,sum,ord[10],t;
//     FILE *fp;

//     if((fp=fopen("f1.dat", "rb"))==NULL)
//     {
//         printf("can’t open file %s \n", "f1.dat");
//         exit(1);
//     }

//     for(i=0;i<10;i++)
//     {
//         fread(fp,2,6,s);
//         sum=0;
//         for(j=1;j<=5;j++)
//             sum=sum+s[j];
//         s[6]=sum;
//         ord=i;
//         fclose(fp);
//     }

//     for(i=0;i<9;i++)
//     {
//         for(j=i+1;j<10;j++)
//         if(s[6]<s[j][6])
//         {
//             t=ord;
//             ord=ord[j];
//             ord[j]=t;
//         }
//     }
    
//     fp=fopen("f2.dat", "wb");
//     for(i=0;i<10;i++)
//     {
//         s[0]=i+1;
//         fwrite(s,2,7,fp);
//     }

//     fclose(fp);

//     return 0;
// }

# include "stdio.h"
    int s[10][7];
    int main()
    {int i,j,sum,ord[10],t;
     FILE *fp;
     if((fp=fopen("f1.dat", "rb"))==NULL)        
     {printf("can't open file %s \n", "f1.dat");
     exit(1);}
     for(i=0;i<10;i++)
     {fread(s,2,6,fp);                        
     sum=0;
     for(j=1;j<=5;j++)
     sum=sum+s[j];
     s[i][6]=sum;  //
     ord[i]=i;  //
     fclose(fp);}                                     
     for(i=0;i<9;i++)
     for(j=i+1;j<10;j++)
     if(s[i][6]<s[j][6]) //
     {t=ord[i]; ord[i]=ord[j];ord[j]=t;} //
     fp=fopen("f2.dat", "wb");                    
     for(i=0;i<10;i++)
     {j=ord[i];  //                               
     fwrite(s[j],2,7,fp);
	 }                            
     fclose(fp);
    sdsad
    return 0;
    }