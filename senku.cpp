#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------
	
//DECLARACION FUNCIONES para el juego
void inicio() ;
const int FILAS = 16; 
const int COLUMNAS = 45; 

//char a int
int chartoint(char caracter)
{
 int auxiliar =0;
 auxiliar = caracter-48;
 return auxiliar;
}

//volver positivo
int positivo(int num)
{
	 if( num <= 0)
	 {
	 	num = num*(-1);
	 }
	 return num;
}

//mostrarmatriz
void mostrarMatriz( char matriz[][45]) 
{ 
	cout<<"\n\n\n";
	for (int i=0;i<FILAS;i++) 
	{ 
		for(int j=0;j<COLUMNAS;j++) 
		{
			cout<<matriz[i][j];
		} 
		cout<<endl; 
	}		 
}  

//Validar GANADOR
bool validarganador(char matriz[][45]) 
{ 	
	int contadordeceros=0;
	for (int i=0;i<FILAS;i++) 
	{ 
		for(int j=0;j<COLUMNAS;j++) 
		{
			if(matriz[i][j]=='0')
			{
				contadordeceros=contadordeceros+1;
			}
		} 
	}
	if(contadordeceros==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Validar PERDEDOR
bool validarperdedor(char matriz[][45], int valor) 
{ 	
	if(valor==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 

//Validar datos
bool validacioningreso(char matriz[][45],
						int filainicio, int columnainicio,
						int filafinal,  int columnafinal) 
{ 
	//posicion inical llena (0) posicion final vacia (+)
	if((matriz[filainicio][columnainicio] == '0') && 
		(matriz[filafinal][columnafinal] == '+'))
	{
		int a=filainicio - filafinal;
		int b=columnainicio - columnafinal;
		int c=a;
		int d=b;
		a=positivo(a);
		b=positivo(b);
		//validar movimiento vertical u horizontal
		if( ((a==0) && (b==12)) || ((a==4) && (b==0)) )
		{
			if( (a==0) && (b==12) )
			{
				if( d>=0 )
				{
					if(matriz[filainicio][columnainicio + 6] == '0')
					{
						return true;
					}
					else 
					{
						return false;
					}
				}
				else
				{
					if(matriz[filainicio][columnainicio - 6] == '0')
					{
						return true;
					}
					else 
					{
						return false;
					}
				}
			}
			else
			{
				if( c>=0 )
				{
					if(matriz[filainicio+2][columnainicio] == '0')
					{
						return true;
					}
					else 
					{
						return false;
					}
				}
				else
				{
					if(matriz[filainicio+2][columnainicio] == '0')
					{
						return true;
					}
					else 
					{
						return false;
					}
				}
			}
		}
		else 
		{
			return false;
		}
	}
	else 
	{
		return false;
	}
}
 
//-----------------------------------------------------------------------------------

//DECLARACION FUNCIONES del juego


//Empezar a jugar
void juego(char matriz[][45]) 
{ 
	int ganar=0;
	//mostrado de tablero
    	mostrarMatriz(matriz);
	while( ganar==0)
	{
		//ingreso datos
		char cadenainicio[5];
		char cadenafinal[5];
		int filainicio,filafinal,columnainicio,columnafinal;
		cout<<"Si desea reiniciar el juego o ya no posees jugadas"; 
		cout<<"posibles, poner 00000 en los dos valores a solicitar.";
		cout<<"\nIngrese la posicion de origen (fila, columna):";
		cin>>cadenainicio;
		cout<<"\nIngrese la posicion de decision (fila, columna):";
		cin>>cadenafinal;
		filainicio=chartoint(cadenainicio[1])*2-1;
		columnainicio=chartoint(cadenainicio[3])*6-3-1;
		filafinal=chartoint(cadenafinal[1])*2-1;
		columnafinal=chartoint(cadenafinal[3])*6-3-1;
		
		//verificar si perdio
		if(validarperdedor(matriz,filainicio))
		{	
    		cout << "\n\n\nPERDISTEEEEEEEEEEEEEEE!\n\n\n";
    		ganar=1;
		}
		else
		{
			//validacion de datos 
			if( validacioningreso(matriz,filainicio,columnainicio,
									filafinal,columnafinal) )
			{
	    		//esto sucede si están bien los datos ingresados
	    		//cambian valores de incio y final
				matriz[filainicio][columnainicio] = '+';
				matriz[filafinal][columnafinal] = '0';
				//cambia intermedio
				int a=filainicio - filafinal;
				int b=columnainicio - columnafinal;
				int c=a;
				int d=b;
				a=positivo(a);
				b=positivo(b);
				if( ((a==0) && (b==12)) || ((a==4) && (b==0)) )
				{
					if( (a==0) && (b==12) )
					{
						if( d>=0 )
						{
							matriz[filainicio][columnainicio + 6] = '+';
						}
						else
						{
							matriz[filainicio][columnainicio - 6] = '+';
							
						}
					}
					else
					{
						if( c>=0 )
						{
							matriz[filainicio+2][columnainicio] = '+';
						}
						else
						{
							matriz[filainicio+2][columnainicio] = '+';
						}
					}
				}
				
			}
			else
			{
				//esto sucede si estan mal los datos ingresados
	    		cout << "\n\nJugada invalida\n\n";
			}
			
			//verificar si gano
			if(validarganador(matriz))
			{
	    		cout << "\n\n\nGANASTEEEEEEEEEEEEEEE!\n\n\n";
	    		ganar=1;
			}
			else
			{
				//mostrado de tablero
	    		mostrarMatriz(matriz);
			}
		}
		
	}
	inicio();	
} 


//Asignar forma de juego
void asignarForma(int forma) 
{ 
	char matriz[FILAS][COLUMNAS];
	switch(forma)
	{
    	case 1:
		{
			char matriz[FILAS][COLUMNAS]={
			    {' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', '2', ' ', ' ', ' ', ' ',
			     ' ', '3', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ',
			     '5', ' ', ' ', ' ', ' ', ' ', '6', ' ', ' ', ' ', ' ', ' ', '7', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //indice arriba
			    {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //1
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //2
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'3', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //3
			    {' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
			    {'4', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '+', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //4
			    {' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'5', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //5
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //6
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //7
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //8
			  };
			break;
			}
    	case 2: 
		{
			char matriz[FILAS][COLUMNAS]={
			    {' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', '2', ' ', ' ', ' ', ' ',
			     ' ', '3', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ',
			     '5', ' ', ' ', ' ', ' ', ' ', '6', ' ', ' ', ' ', ' ', ' ', '7', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //indice arriba
			    {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //1
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '-', '-', '-', '-',
				 '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //2
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'3', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //3
			    {' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
			    {'4', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '+', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //4
			    {' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'5', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //5
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '-', '-', '-', '-',
				 '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //6
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //7
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //8
			  };
    		break;
		}
    	case 3:
		{
			char matriz[FILAS][COLUMNAS]={
			    {' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', '2', ' ', ' ', ' ', ' ',
			     ' ', '3', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ',
			     '5', ' ', ' ', ' ', ' ', ' ', '6', ' ', ' ', ' ', ' ', ' ', '7', 
				 ' ', ' ', ' ', ' ', ' ', '8'},
			    //indice arriba
			    {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //1
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //2
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //3
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'4', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 '-', '-', '-', '-', '-', '0'},
			    //4
			    {' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|',
				 ' ', ' ', ' ', ' ', ' ', '|'},
			    {'5', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '+', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 '-', '-', '-', '-', '-', '0'},
			    //5
			    {' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', 
				 ' ', ' ', ' ', ' ', ' ', '|'},
			    {'6', ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-',
			     '-', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-', '0', 
				 '-', '-', '-', '-', '-', '0'},
			    //6
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //7
			    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ',
			     '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    {'8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			     ' ', '0', '-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-',
			     '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
				 ' ', ' ', ' ', ' ', ' ', ' '},
			    //8
			  };
    		break;
		}
    	default: 
		{
			cout << "Usted ha ingresado una opción incorrecta";
			inicio();
		}
	}
	juego(matriz);
} 

//Imprimir menu inicio
void inicio() 
{ 
	cout << "                  Menú - Juego Senku"<<endl;
	cout << "---------------------------------------------------------"<<endl;
	cout << "	1. Estilo ingles"<<endl;
	cout << "	2. Estilo frances"<<endl;
	cout << "	3. Estilo asimetrico"<<endl;
	cout << "---------------------------------------------------------"<<endl;
	cout << "	0. Salir del Programa\n\n";
	cout << "	Seleccionar la opcion: ";
	int forma;
	cin >>forma;
	asignarForma(forma);
} 


//-----------------------------------------------------------------------------------

//PRINCIPAL

int main() {
	inicio();
	return 0;
}

