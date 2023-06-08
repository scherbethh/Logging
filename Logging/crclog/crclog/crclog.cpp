#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	
	int dosyaSayisi = 0;
    int dakika;
    int dosyasiniri;
    const int maxDosyaSayisi = 100; // Maksimum dosya sayısı
    string dosyalar[maxDosyaSayisi]; // Dosya yollarını saklayacak dizi

	// Bu string ile uzun uzun kalabalık yapmamıza gerek kalmadı.
    

    //********************************************************************************************************
	const string dosyaYolu = "C:\\Users\\omerg\\Desktop\\Logging\\crclog";//**********************************
    //********************************************************************************************************



    /* for (int i = 1; i <= dosyasayisi; ++i) {

        stringstream ss;
        ss << dosyaYolu << "\\reg" << i << ".txt";
        const string dosyaYolu = ss.str();

        // Dosya oluşturma
        ofstream baseFile(dosyaYolu);
        baseFile.close();

        
    }

    */


    /*while (true) {
        // Dosya adını oluşturma

        time_t now = time(nullptr);
        stringstream ss;
        ss << dosyaYolu << "\\reg" << dosyasayisi << ".txt";
        const string dosyaYolu = ss.str();

        // Dosya oluşturma
        ofstream baseFile(dosyaYolu);
        baseFile.close();
        
        // 1 dakika bekletme
        this_thread::sleep_for(chrono::minutes(1));

        dosyasayisi++;
    }
    */

   
    // Bekletme süresini kullanıcıdan alma
    cout << "Kaç dakika bekletilsin? ";
    cin >> dakika;
    //Kayıt sınır sayısını kullanıcıdan alma
    cout << "Kayıt sınırı ne kadar olsun ?";
    cin >> dosyasiniri;

     while (true) 
     {
        // Tarih ve saat bilgisini alıyoruz
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);
        struct tm localTime;
        localtime_s(&localTime, &time);

        // Dosya adını oluşturma
        stringstream ss;
        ss << dosyaYolu << "\\";
   
        ss << setw(2) << setfill('0') << localTime.tm_mon + 1 << ".";
        
        ss << setw(2) << setfill('0') << localTime.tm_mday << ".";
      
        ss << setw(2) << setfill('0') << localTime.tm_hour << ".";
        
        ss << setw(2) << setfill('0') << localTime.tm_min << ".";
       
        ss << setw(2) << setfill('0') << localTime.tm_sec << ".";
       
        ss << ".txt";

        const string dosyaYolu = ss.str();


        // Dosya oluşturma
        ofstream baseFile(dosyaYolu);
        baseFile.close();

        // Dosya yollarını kaydetme
        dosyalar[dosyaSayisi] = dosyaYolu;

        if (dosyaSayisi >= dosyasiniri) 
        {
            const string eskidosyaYolu = dosyalar[dosyaSayisi - dosyasiniri];
            remove(eskidosyaYolu.c_str());
        }




        // Belirtilen süre kadar bekletme

        this_thread::sleep_for(chrono::minutes(dakika));

        dosyaSayisi++;
    }
    



}