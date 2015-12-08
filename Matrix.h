#pragma once 
#include <iostream>
template <typename Typ, int X , int Y   > 
class Matrix 
{
	public :
		Matrix  ();
		void zero ( Typ) ;
		template <int ,int  > 
		Typ & at ()   ;
	 	template < typename T   > 
		void add (const  Matrix < T, X , Y  > & ) ;
		template < typename T, int x , int y   > 
		friend std::ostream & operator <<(std::ostream & wyj , Matrix<T , x,y > & obj );
		Typ   get (int ,int) const ;
		~Matrix () ;

	 	private:
		Typ ** typ ;	
		
				

};
/*********************************************/

template <typename Typ, int X , int Y   > 
Matrix <Typ,X,Y   > ::Matrix ( ) 
{
	typ = new Typ * [X];
	for (int i = 0 ; i < X ;i++)
		typ[i] = new Typ [Y] ;

	for ( int i=0 ;i<X ; i++ )
		for ( int j= 0 ; j<Y ; j++)
			typ[i][j]=0;
	 
}

/*********************************************/

 template <typename Typ, int X , int Y   > 
void Matrix <Typ,X,Y   > :: zero ( Typ val ) 
{
	for ( int i =0 ; i<X ;i++)
		for (int j =0 ; j<X ; j++)
			typ[i][j]=val ;	
}

/*********************************************/
template <typename Typ, int X , int Y   > 
template <int x  ,int y  > 
Typ & Matrix <Typ,X,Y   > ::at ()   
{
	return   typ[x][y];
}
/*********************************************/
template <typename Typ, int X , int Y   > 
Typ    Matrix <Typ,X,Y   > :: get (int i,int j)  const 
{
	return  typ[i][j];
}


/*********************************************/


template <typename Typ, int X , int Y   > 
template < typename T   > 
void Matrix <Typ,X,Y   > :: add ( const Matrix < T, X , Y  > & obj) 
{
	for (int i=0; i<X; i++)
		for (int j = 0 ; j<Y; j++ ) 
			this->typ[i][j]+=obj.get(i,j);
}

/*********************************************/

template < typename T, int x , int y   > 
std::ostream & operator <<(std::ostream & wyj , Matrix<T , x,y > & obj )
{  
	for ( int i = 0 ; i<x; ++i)
	{
		for ( int j = 0 ; j< y ;++j)
		{
		wyj<<obj.get(i,j)<<" " ;
		}
	wyj<<std::endl ;
	} 
	return  wyj; 
}

/*********************************************/

template <typename Typ, int X , int Y   > 
Matrix<Typ,X,Y>::~Matrix () 
{
	for (int i = 0 ; i<X ; i++)
		delete [] typ[i];
	delete []  typ ;
}
