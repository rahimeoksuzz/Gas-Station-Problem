#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;


int main(){
	int mList[5] = {20, 37, 55, 75, 100}; //başlangıçtan sona kadar artan sırayla benzinlik
	int pList[5] = {1, 2 ,3 ,4, 5}; //benzinlik fiyat
	vector<int> kList(5); //iki benzinlik arası uzaklığı tutar 
	
	kList.push_back(mList[0]);  //vektöre 0 konumunu ekliyorum
	for(int i= 0; i<5; i++)   //mlistin diğer elemanlarının farkını ekliyorum
    {
	  int fark = mList[i+1]-mList[i];
      kList.push_back(fark);
    } 
    
	int menzil = 100;
	int F {40}; //ful depo gitme kapasitesi
	int Limit {30}; //iki benzinlik arası durma mesafe şartı 
	int mesafe {0};
	int i {0};
	int benzinlikSayisi {0}; //durulan benzinlik sayısı
	while ( mesafe < menzil ){
		mesafe = mesafe + kList[i] ;
		F = F - kList[i];
		if (kList[i+1] <= F && kList[i+1] < Limit){
			++i;
	    }
		else {
			++benzinlikSayisi;
			int maliyet = pList[benzinlikSayisi];  //maliyet
			cout << "\nDURDUGUMUZ BENZINLIKLER : " << mList[benzinlikSayisi] <<endl; //durduğumuz durakların konumları
			F = 40;
		}
	}
	cout << "\nMINIMUM MALIYET ICIN " << benzinlikSayisi << " BENZINLIKTE DURULDU " <<endl; //durduğumuz benzinlik sayısı
	
	
}


