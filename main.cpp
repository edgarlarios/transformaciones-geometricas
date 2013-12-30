
#include<winbgim.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include <cmath>

using namespace std;

double n, ANGULO, Sx, Sy;
double T[2];
double P[3][2];
int x;
double S[2];


//void putpixel(double x, double y, int color);
void line(double x0, double y0, double x1, double y1);

double cmx(double x){
    return x+300;
}
double cmy(double y){
    return 150-y;
}
double signo(double numero){
   if(numero < 0) return -1;
   if(numero > 0) return 1;
   if(numero == 0) return 0;
}
void bresenham(double x1,double y1, double x2, double y2){
   float incE,dx,dy,temp;
   double s1,s2,intercambio,i,x,y;
  
   x = x1;
   y = y1;
   dx = abs(x2-x1);
   dy = abs(y2-y1);
   s1 = signo(x2-x1);
   s2 = signo(y2-y1);
   
   if(dy > dx){
      temp = dx;
      dx = dy;
      dy = temp;
      intercambio = 1;
   }else{
       intercambio = 0;
   }
   incE = 2*dy-dx;
   
   for(i =1; i <= dx; i++){
      putpixel(cmx(x),cmy(y),4);
      if(incE >= 0){
         if(intercambio == 1){
             x = x+s1;
         }else{
             y = y+s2;
         }
            incE = incE-(2*dx);
      }
      if(intercambio == 1){
          y = y+s2;
      }else{
          x = x+s1;
      }
      incE = incE+2*dy;
   }
}


using namespace std;

int main(){
       
    float pi= 3.1416;
    
    initwindow(600,300);
    line(300,0,300,300);
    line(0,150,600,150);
    
   int opcion;
   cout<<"INTRODUZCA UN VALOR DE ACTIVIDAD A REALIZAR"<<endl; 
   cout<<"1 TRASLACION "<<endl;
   cout<<"2 ROTACION"<<endl;
   cout<<"3 ESCALACION "<<endl;
   cin>>opcion;
   
   switch(opcion){
       case 1:
              
              cout<<"Ingrea el numero de lados de la figura: "<<endl;
              cin>>n;
             
              cout<<">>>> TRASLACION  <<<<"<<endl<<endl;
    
              for(int i=1; i<=n; i++){
                for(int j=1; j<=2; j++){             
                   if(j == 1){
                      cout<<"punto "<<i<<" en X: ";
                      cin>>P[i][j];
                   }else{
                      cout<<"punto "<<i<<" en Y: ";
                      cin>>P[i][j];   
                   }             
                 }  
              }        
             cout<<"ingrese traslacion TX: ";
             cin>>T[0];
             cout<<"ingrese traslacion Ty: ";
             cin>>T[1];
       
             for(int i=1; i<=1; i++){
                 for(int j=1; j<=n; j++){   
                    if(j == n){ x=1;}
                    else{ x=j+1;}
                    bresenham(P[j][i], P[j][i+1], P[x][i], P[x][i+1]);
                    bresenham((P[j][i] + T[0]), (P[j][i+1] + T[1]), (P[x][i] + T[0]), (P[x][i+1] + T[1]));
                 }
            }            
            break;  
          
      case 2:
              
              cout<<"Ingrea el numero de lados de la figura: "<<endl;
              cin>>n;
  
              cout<<">>>> TRASLACION  <<<<"<<endl<<endl;
    
              for(int i=1; i<=n; i++){
                for(int j=1; j<=2; j++){             
                   if(j == 1){
                      cout<<"punto "<<i<<" en X: ";
                      cin>>P[i][j];
                   }else{
                      cout<<"punto "<<i<<" en Y: ";
                      cin>>P[i][j];   
                   }             
                 }  
              }        
             cout<<"Ingrese un angulo: ";
             cin>>ANGULO;
       
             for(int i=1; i<=1; i++){
                 for(int j=1; j<=n; j++){   
                    if(j == n){ x=1;}
                    else{ x=j+1;}
                    bresenham(P[j][i], P[j][i+1], P[x][i], P[x][i+1]);
                    bresenham(((P[j][i]*(cos((ANGULO*3.1416)/150)))-(P[j][i+1]*(sin((ANGULO*3.1416)/150)))), ((P[j][i]*(sin((ANGULO*3.1416)/150)))+(P[j][i+1]*(cos((ANGULO*3.1416)/150)))), ((P[x][i]*(cos((ANGULO*3.1416)/150)))-(P[x][i+1]*(sin((ANGULO*3.1416)/150)))), ((P[x][i]*(sin((ANGULO*3.1416)/150)))+(P[x][i+1]*(cos((ANGULO*3.1416)/150)))));            
                 }
             }   
           break;
 
   
   
   case 3:

              cout<<"Ingrea el numero de lados de la figura: "<<endl;
              cin>>n;
              cout<<">>>>  ESCALACION  <<<<"<<endl<<endl;
    
              for(int i=1; i<=n; i++){
                for(int j=1; j<=2; j++){
             
                   if(j == 1){
                      cout<<"punto "<<i<<" en X: ";
                      cin>>P[i][j];
                   }else{
                      cout<<"punto "<<i<<" en Y: ";
                      cin>>P[i][j];   
                   }             
               }  
              }        
              cout<<"Factor de escala en X: ";
             cin>>Sx;
             cout<<"Factor de escala en Y: ";
             cin>>Sy;
             
             for(int i=1; i<=1; i++){
                 for(int j=1; j<=n; j++){   
                    if(j == n){ x = 1;}
                      else{ x=j+1;}
                      bresenham(P[j][i], P[j][i+1], P[x][i], P[x][i+1]);
                      bresenham((P[j][i]*Sx), (P[j][i+1]*Sy), (P[x][i]*Sx), (P[x][i+1]*Sy));
                }
             }
             break;   
      }
      while(!kbhit());
    closegraph();        
	return 0;
}
