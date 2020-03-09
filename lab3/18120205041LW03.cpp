/* Fatih Dursun Üzer
 * 18120205041
 * 
 * LW03 Çalışması.
 * 6 mart 2019 */

#include <iostream>
#include <vector>
#include "MyVector.h"
using namespace std;


MyVector::MyVector()
{
	
}

MyVector::MyVector(int val)  /*Vektörün  İlk indexine değere alınan val değerini atar */ 
{
	v[0]=val;
}

void MyVector::addNewItem(int val) /* Vektörün sonuna val değerini ekler */ 
{
	v.push_back(val);
	
}

MyVector::MyVector(int numberOfItems, int defaultValue) /* numberOfItemslik bir vektör oluşturup her elemanına defaultValue yu atar*/
{
	 for(int i=0; i<numberOfItems; ++i)
	 {
		 v.push_back(defaultValue);
	 }
}


const MyVector operator +(const MyVector& myVector1, const MyVector& myVector2) /* Aynı boyutlara sahip vektörleri toplar ve tempe atayıp dönderir */
{
	MyVector temp;
	if(myVector1.v.size()==myVector2.v.size())
	{
		
	  for(unsigned int i=0; i<myVector1.v.size(); ++i)
	  {
		  temp.v[i]=myVector1.v[i]+myVector2.v[i];
		
	  }
	 
	 }
    
     return temp.v[i]; 
    
}

  ostream& operator<<(ostream& outputStream, const MyVector& myVector) /* Cout benzeri işlev gerçekleştirir */
{
	for(unsigned int i=0; i<myVector.v.size(); ++i)
	{
		outputStream<<myVector.v[i];
		outputStream<<"\t";
     }
     
     outputStream<<endl;
     
     return outputStream;
	
}
   

   
    
	 

