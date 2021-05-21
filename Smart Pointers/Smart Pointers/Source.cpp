#include <iostream>
#include <memory>
using namespace std;
int main() {




    auto sharedPtr = make_shared<int>(10);
    weak_ptr<int> weakPtr(sharedPtr);
    weak_ptr<int> weakPtr1;
    weakPtr1.expired();
    cout << "Weak ptr1 expired: " <<boolalpha<< weakPtr1.expired() << endl;//Weak ptr 1 i hec bir shared ptr ile connect etmediyimize bos olduguna gore expired funskiyasi bize true qaytaracaq
    //Yuxaridaki setrde menbeyini shared_ptrdan goturen bir weak pointer yaradiram
    cout << "weakPtr.use_count(): " << weakPtr.use_count() << endl;//Ve burada weak pointerin sayi 1 e beraber  olur
    cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << endl;//Eyni zamanda shared pointerin sayida 1 e beraberdir
    cout << "weakPtr.expired(): " << weakPtr.expired() << endl;//Ve biz burada expired metodu sayesinde menbenin silinib ve yaxud silinmediyini yoxluyuruq.
    //Hal hazirda silinmediyi ucun false gosterecek.

    if (shared_ptr<int> sharedPtr1 =weakPtr.lock()) {//Burada weakptr.lock() metodu vasitesi ile hansi shared pointer ile elaqe qurulub hemin pointeri return edir.
        cout << "(*sharedPtr) deyeri: " << *sharedPtr << endl;
        cout << "(*sharedPtr1) deyeri: " << *sharedPtr1 << endl;
        //Yuxaridaki setrlerde gorunduyuu kimi shared ptr nin deyeri normal olaraq 10 ve sharedptr1-i shared ptrin weak pointerinin lock metodu vasitesiyle bir birine beraber etdiyimize gore netice 10 olacaq.
        cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << endl;//Burada shared ptr lari bir birine beraber etdiyimize gore count+1 olaraq 2 ni gosterecek
    }
    else {
        cout << "Don't get the resource!" << endl;
    }

    weakPtr.reset();//Reset funksiyasi vasitesi ile shared ptr arasindaki elaqeni kesirik
   
    if (shared_ptr<int> sharedPtr1 = weakPtr.lock()) {//Burada weakptr ini resetlediyimize gore hec bir shared ptr ile connect olunmadigi ucun if sertini odemeyecek ve 
      //belece else sertine gore hec bir menbe tapilmadi yazi ekrana cixacaq
        cout << "*sharedPtr: " << *sharedPtr << endl;
        cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << endl;
    }
    else {
        cout << "Don't get the resource!" << endl;
    }

  

}