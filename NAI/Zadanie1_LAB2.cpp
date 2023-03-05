#include <opencv2/highgui/highgui.hpp>            //Dołączenie potrzebnych nagłówków 
#include "opencv2/imgproc/imgproc.hpp" 
#include <string> 
#include <iostream> 

using namespace cv;                        //Przestrzeń nazw OpenCV 
using namespace std; 

int main() 
{ 
    const string file_name = "kookie.jpg";    //Nazwa obrazka 
    Mat img, hsv;                    //Miejsce na obrazki 
    vector<Mat> img_split;                //Miejsce na składowe HSV 
    img = imread(file_name);                //Wczytanie obrazka 
    if ( !img.data )                    //Sprawdzenie poprawnosci odczytu 
    { 
        cout << "Nie znaleziono pliku " << file_name << "."; 
        return -1; 
    } 
    const string named_window[] = {"BGR", "HSV", "HUE", "SAT", "VAL" }; 
    namedWindow(named_window[0], CV_WINDOW_AUTOSIZE);    //Utworzenie okien 
    namedWindow(named_window[1], CV_WINDOW_AUTOSIZE); 
    namedWindow(named_window[2], CV_WINDOW_AUTOSIZE); 
    namedWindow(named_window[3], CV_WINDOW_AUTOSIZE); 
    namedWindow(named_window[4], CV_WINDOW_AUTOSIZE); 
    cvtColor(img, hsv, CV_BGR2HSV );                //Konwersja BGR -> HSV 
    split(hsv, img_split);            //Rozdzielenie HSV na poszczególne kanały 
    imshow(named_window[0], img);        //Obraz oryginalny 
    imshow(named_window[1], hsv);        //Obraz w wersji HSV 

    cv::Mat flip(hsv, img, 1);
    imshow("flipped",img);

    imshow(named_window[2], img_split[0]);    //Barwa 
    imshow(named_window[3], img_split[1]);    //Nasycenie 
    imshow(named_window[4], img_split[2]);    //Wartosc 
    vector<int> compression_params;    //Element przechowujący dane o sposobie zapisu 
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);    //Konwersja jpg 
    compression_params.push_back(100);                //Jakosc 100 
    imwrite("hsv.jpg", hsv, compression_params);    //Zapis poszczegolnych obrazow 
    imwrite("hue.jpg", img_split[0], compression_params); 
    imwrite("sat.jpg", img_split[1], compression_params); 
    imwrite("val.jpg", img_split[2], compression_params); 
    waitKey();                    //Oczekiwanie na wciesniecie klawisza 
    return 0; 
}
